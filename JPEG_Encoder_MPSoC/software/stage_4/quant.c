#include <stdio.h>
#include "datatype.h"
#include "config.h"
#include "quantdata.h"

#include "system.h"
#include <altera_avalon_fifo_regs.h>

#ifndef FIFO_1_4_QUANT_OUT_BASE
#define FIFO_1_4_QUANT_OUT_BASE 0x01011028
#endif
#ifndef FIFO_3_4_DATA_OUT_BASE
#define FIFO_3_4_DATA_OUT_BASE 0x0101102c
#endif

#define RECV1() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_4_QUANT_OUT_BASE)
#define RECV2() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_3_4_DATA_OUT_BASE)
#define SEND(val) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_4_5_DATA_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_4_5_DATA_IN_BASE, val); \
} while(0)

UINT8	Lqt [BLOCK_SIZE]; UINT8	Cqt [BLOCK_SIZE];
UINT16	ILqt [BLOCK_SIZE]; UINT16	ICqt [BLOCK_SIZE];
INT16	Temp [BLOCK_SIZE];

UINT16 DSP_Division (UINT32 numer, UINT32 denom) {
	UINT16 i; denom <<= 15;
	for (i=16; i>0; i--) {
		if (numer > denom) { numer -= denom; numer <<= 1; numer++; } else numer <<= 1;
	}
	return (UINT16) numer;
}

void initialize_quantization_tables (void) {
	UINT16 i, index; UINT32 value;
	UINT8 luminance_quant_table [] = {
		16, 11, 10, 16,  24,  40,  51,  61, 12, 12, 14, 19,  26,  58,  60,  55,
		14, 13, 16, 24,  40,  57,  69,  56, 14, 17, 22, 29,  51,  87,  80,  62,
		18, 22, 37, 56,  68, 109, 103,  77, 24, 35, 55, 64,  81, 104, 113,  92,
		49, 64, 78, 87, 103, 121, 120, 101, 72, 92, 95, 98, 112, 100, 103,  99
	};
	UINT8 chrominance_quant_table [] = {
		17, 18, 24, 47, 99, 99, 99, 99, 18, 21, 26, 66, 99, 99, 99, 99,
		24, 26, 56, 99, 99, 99, 99, 99, 47, 66, 99, 99, 99, 99, 99, 99,
		99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
		99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99
	};
	UINT32 quality_factor = (UINT32)RECV1();
	for (i=0; i<64; i++) {
		index = zigzag_table [i];
		value = luminance_quant_table [i] * quality_factor;
		value = (value + 0x200) >> 10;
		if (value == 0) value = 1; else if (value > 255) value = 255;
		Lqt [index] = (UINT8) value; ILqt [i] = DSP_Division (0x8000, value);

		value = chrominance_quant_table [i] * quality_factor;
		value = (value + 0x200) >> 10;
		if (value == 0) value = 1; else if (value > 255) value = 255;
		Cqt [index] = (UINT8) value; ICqt [i] = DSP_Division (0x8000, value);
	}
	for (i=0; i<64; i++) { SEND(Lqt[i]); }
	for (i=0; i<64; i++) { SEND(Cqt[i]); }
}

void quantization (UINT16* const quant_table_ptr) {
	INT16 i; INT32 value;
	for (i=0; i<=63; i++) {
		value = (INT16)RECV2() * quant_table_ptr [i];
		value = (value + 0x4000) >> 15;
		Temp [zigzag_table [i]] = (INT16) value;
	}
	for (i=0; i<=63; i++) { SEND(Temp [i]); }
}

int main(void){
	printf("Stage 4: Quantization initialized. Waiting for pipeline start...\n");

	while(1) {
		UINT32 count; /* <-- Declared safely at the top of the block! */
		count = (UINT32)RECV1();
		initialize_quantization_tables();

		printf("\n[Stage 4] Receiving data from Stage 3...\n");
		
		for(; count>0; count--){
			quantization (ILqt); quantization (ICqt); quantization (ICqt);
		}
		
		printf("[Stage 4] Data quantized and sent to Stage 5.\n");
	}
	return 0;
}