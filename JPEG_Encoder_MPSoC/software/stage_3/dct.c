#include <stdio.h>
#include "datatype.h"

#include "system.h"
#include <altera_avalon_fifo_regs.h>

#ifndef FIFO_2_3_DATA_OUT_BASE
#define FIFO_2_3_DATA_OUT_BASE 0x01011028
#endif

#define RECV() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_2_3_DATA_OUT_BASE)
#define SEND(val) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_3_4_DATA_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_3_4_DATA_IN_BASE, val); \
} while(0)

#define TOTAL_MCUS 551
INT16 data_array[64];
INT16 *data;

void DCT (void) {
	UINT16 i; INT32 x0, x1, x2, x3, x4, x5, x6, x7, x8;
	static const UINT16 c1=1420; static const UINT16 c2=1338; static const UINT16 c3=1204;
	static const UINT16 c5=805; static const UINT16 c6=554; static const UINT16 c7=283;
	static const UINT16 s1=3; static const UINT16 s2=10; static const UINT16 s3=13;

	for (i=0; i<64; i++) { data [i] = (INT16)RECV(); }

	for (i=8; i>0; i--) {
		x8 = data [0] + data [7]; x0 = data [0] - data [7];
		x7 = data [1] + data [6]; x1 = data [1] - data [6];
		x6 = data [2] + data [5]; x2 = data [2] - data [5];
		x5 = data [3] + data [4]; x3 = data [3] - data [4];
		x4 = x8 + x5; x8 -= x5; x5 = x7 + x6; x7 -= x6;
		data [0] = (INT16) (x4 + x5); data [4] = (INT16) (x4 - x5);
		data [2] = (INT16) ((x8*c2 + x7*c6) >> s2); data [6] = (INT16) ((x8*c6 - x7*c2) >> s2);
		data [7] = (INT16) ((x0*c7 - x1*c5 + x2*c3 - x3*c1) >> s2);
		data [5] = (INT16) ((x0*c5 - x1*c1 + x2*c7 + x3*c3) >> s2);
		data [3] = (INT16) ((x0*c3 - x1*c7 - x2*c1 - x3*c5) >> s2);
		data [1] = (INT16) ((x0*c1 + x1*c3 + x2*c5 + x3*c7) >> s2);
		data += 8;
	}
	data -= 64;
	for (i=8; i>0; i--) {
		x8 = data [0] + data [56]; x0 = data [0] - data [56];
		x7 = data [8] + data [48]; x1 = data [8] - data [48];
		x6 = data [16] + data [40]; x2 = data [16] - data [40];
		x5 = data [24] + data [32]; x3 = data [24] - data [32];
		x4 = x8 + x5; x8 -= x5; x5 = x7 + x6; x7 -= x6;
		data [0] = (INT16) ((x4 + x5) >> s1); data [32] = (INT16) ((x4 - x5) >> s1);
		data [16] = (INT16) ((x8*c2 + x7*c6) >> s3); data [48] = (INT16) ((x8*c6 - x7*c2) >> s3);
		data [56] = (INT16) ((x0*c7 - x1*c5 + x2*c3 - x3*c1) >> s3);
		data [40] = (INT16) ((x0*c5 - x1*c1 + x2*c7 + x3*c3) >> s3);
		data [24] = (INT16) ((x0*c3 - x1*c7 - x2*c1 - x3*c5) >> s3);
		data [8] = (INT16) ((x0*c1 + x1*c3 + x2*c5 + x3*c7) >> s3);
		data++;
	}
	data -= 8;
	for (i=0; i<64; i++) { SEND(data [i]); }
}

int main(void){
	int mcu; /* <-- Declared safely at the top! */
	data = data_array;

	printf("Stage 3: DCT initialized. Waiting for data...\n");

	while(1){
		printf("\n[Stage 3] Receiving data from Stage 2...\n");

		for (mcu = 0; mcu < TOTAL_MCUS; mcu++) {
			DCT(); DCT(); DCT();
		}

		printf("[Stage 3] Processed 551 blocks and sent to Stage 4.\n");
	}
	return 0;
}
