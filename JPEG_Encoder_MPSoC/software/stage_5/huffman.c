#include <stdio.h>
#include "datatype.h"
#include "huffdata.h"
#include "markdata.h"

#include "system.h"
#include <altera_avalon_fifo_regs.h>

#ifndef FIFO_1_5_HUFF_OUT_BASE
#define FIFO_1_5_HUFF_OUT_BASE 0x0104104c
#endif
#ifndef FIFO_4_5_DATA_OUT_BASE
#define FIFO_4_5_DATA_OUT_BASE 0x01041050
#endif

#define RECV1() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_5_HUFF_OUT_BASE)
#define RECV2() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_4_5_DATA_OUT_BASE)

#define SEND1(val) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_5_6_DATA_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_5_6_DATA_IN_BASE, val); \
} while(0)

#define SEND2(val) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_5_6_SIZE_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_5_6_SIZE_IN_BASE, val); \
} while(0)

#define PUTBITS	\
{	\
	bits_in_next_word = (INT16) (bitindex + numbits - 32);	\
	if (bits_in_next_word < 0) { lcode = (lcode << numbits) | data; bitindex += numbits; } \
	else { \
		lcode = (lcode << (32 - bitindex)) | (data >> bits_in_next_word);	\
		out = (UINT8)(lcode >> 24); SEND1(out); if (out == 0xff) SEND1(0); \
		out = (UINT8)(lcode >> 16); SEND1(out); if (out == 0xff) SEND1(0); \
		out = (UINT8)(lcode >> 8);  SEND1(out); if (out == 0xff) SEND1(0); \
		out = (UINT8) lcode;        SEND1(out); if (out == 0xff) SEND1(0); \
		lcode = data; bitindex = bits_in_next_word;	\
	} \
}

void write_markers (UINT32 image_width, UINT32 image_height) {
	UINT16 i, header_length; UINT8 number_of_components;

	SEND1(0xFF); SEND1(0xD8); SEND1(0xFF); SEND1(0xDB); SEND1(0x00); SEND1(0x84); SEND1(0x00);
	for (i=0; i<64; i++) SEND1((UINT8)RECV2());
	SEND1(0x01);
	for (i=0; i<64; i++) SEND1((UINT8)RECV2());
	for (i=0; i<210; i++) { SEND1((UINT8) (markerdata [i] >> 8)); SEND1((UINT8) markerdata [i]); }

	number_of_components = 3;
	SEND1(0xFF); SEND1(0xC0); header_length = (UINT16) (8 + 3 * number_of_components);
	SEND1((UINT8) (header_length >> 8)); SEND1((UINT8) header_length); SEND1(0x08);
	SEND1((UINT8) (image_height >> 8)); SEND1((UINT8) image_height);
	SEND1((UINT8) (image_width >> 8)); SEND1((UINT8) image_width);
	SEND1(number_of_components);
    SEND1(0x01); SEND1(0x11); SEND1(0x00); SEND1(0x02); SEND1(0x11); SEND1(0x01); SEND1(0x03); SEND1(0x11); SEND1(0x01);

	SEND1(0xFF); SEND1(0xDA); header_length = (UINT16) (6 + (number_of_components << 1));
	SEND1((UINT8) (header_length >> 8)); SEND1((UINT8) header_length); SEND1(number_of_components);
    SEND1(0x01); SEND1(0x00); SEND1(0x02); SEND1(0x11); SEND1(0x03); SEND1(0x11);
	SEND1(0x00); SEND1(0x3F); SEND1(0x00);
}

UINT32 lcode = 0; UINT16 bitindex = 0; INT16 ldc1 = 0, ldc2 = 0, ldc3 = 0;

void huffman (UINT16 component) {
	UINT16 i; UINT16 *DcCodeTable, *DcSizeTable, *AcCodeTable, *AcSizeTable;
	INT16 Coeff, LastDc; UINT16 AbsCoeff, HuffCode, HuffSize, RunLength=0, DataSize=0, index;
	INT16 bits_in_next_word; UINT16 numbits; UINT32 data; UINT8 out;

	Coeff = (INT16)RECV2();
	if (component == 1) {
		DcCodeTable = luminance_dc_code_table; DcSizeTable = luminance_dc_size_table;
		AcCodeTable = luminance_ac_code_table; AcSizeTable = luminance_ac_size_table;
		LastDc = ldc1; ldc1 = Coeff;
	} else {
		DcCodeTable = chrominance_dc_code_table; DcSizeTable = chrominance_dc_size_table;
		AcCodeTable = chrominance_ac_code_table; AcSizeTable = chrominance_ac_size_table;
		if (component == 2) { LastDc = ldc2; ldc2 = Coeff; }
		else { LastDc = ldc3; ldc3 = Coeff; }
	}

	Coeff -= LastDc; AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;
	while (AbsCoeff != 0) { AbsCoeff >>= 1; DataSize++; }
	HuffCode = DcCodeTable [DataSize]; HuffSize = DcSizeTable [DataSize];
	Coeff &= (1 << DataSize) - 1; data = (HuffCode << DataSize) | Coeff; numbits = HuffSize + DataSize;
	PUTBITS

	for (i=63; i>0; i--) {
		if ((Coeff = (INT16)RECV2()) != 0) {
			while (RunLength > 15) {
				RunLength -= 16; data = AcCodeTable [161]; numbits = AcSizeTable [161]; PUTBITS
			}
			AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;
			if (AbsCoeff >> 8 == 0) DataSize = bitsize [AbsCoeff];
			else DataSize = bitsize [AbsCoeff >> 8] + 8;
			index = RunLength * 10 + DataSize; HuffCode = AcCodeTable [index]; HuffSize = AcSizeTable [index];
			Coeff &= (1 << DataSize) - 1; data = (HuffCode << DataSize) | Coeff; numbits = HuffSize + DataSize;
			PUTBITS RunLength = 0;
		} else RunLength++;
	}
	if (RunLength != 0) { data = AcCodeTable [0]; numbits = AcSizeTable [0]; PUTBITS }
}

void close_bitstream (void) {
	UINT16 i, count; UINT8 *ptr; UINT8 out;
	if (bitindex > 0) {
		lcode <<= (32 - bitindex); count = (bitindex + 7) >> 3; ptr = (UINT8 *) &lcode + 3;
		for (i=count; i>0; i--) {
			out = *ptr--; SEND1(out); if (out == 0xff) SEND1(0);
		}
	}
	SEND1(0xFF); SEND1(0xD9);
}

int main(void){
	printf("Stage 5: Huffman Encoder initialized. Waiting for pipeline start...\n");

	while(1) {
		UINT32 width, height, count; /* <-- Declared safely at the top of the block! */

		lcode = 0; bitindex = 0; ldc1 = 0; ldc2 = 0; ldc3 = 0;
		width  = (UINT32)RECV1();
		height = (UINT32)RECV1();
		count  = (UINT32)RECV1();

		write_markers(width, height);

		printf("\n[Stage 5] Receiving data from Stage 4 & Encoding...\n");

		for(; count>0; count--){
			huffman (1); huffman (2); huffman (3);
		}
		close_bitstream();
		SEND2(1);

		printf("[Stage 5] Bitstream generated and sent to Stage 6.\n");
	}
	return 0;
}
