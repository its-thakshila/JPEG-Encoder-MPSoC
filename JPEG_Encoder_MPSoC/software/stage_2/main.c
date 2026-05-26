#include <stdio.h>
#include "datatype.h"

#include "system.h"
#include <altera_avalon_fifo_regs.h>

#ifndef FIFO_1_2_Y_OUT_BASE
#define FIFO_1_2_Y_OUT_BASE 0x01011030
#endif
#ifndef FIFO_1_2_CB_OUT_BASE
#define FIFO_1_2_CB_OUT_BASE 0x0101102c
#endif
#ifndef FIFO_1_2_CR_OUT_BASE
#define FIFO_1_2_CR_OUT_BASE 0x01011028
#endif

#define RECV1() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_Y_OUT_BASE)
#define RECV2() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_CB_OUT_BASE)
#define RECV3() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_CR_OUT_BASE)

#define SEND(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_2_3_DATA_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_2_3_DATA_IN_BASE, data); \
} while(0)

#define TOTAL_MCUS 551

void levelshift (void) {
	INT16 j; INT16 y_buf[64]; INT16 cb_buf[64]; INT16 cr_buf[64];
	int mcu; /* <-- Declared safely at the top! */

	printf("Stage 2: Level Shifting initialized. Waiting for data...\n");

	while(1){
		printf("\n[Stage 2] Receiving data from Stage 1...\n");

		for(mcu = 0; mcu < TOTAL_MCUS; mcu++) {
			for(j=0;j<64;j++){
				y_buf[j] = (INT16)RECV1(); cb_buf[j] = (INT16)RECV2(); cr_buf[j] = (INT16)RECV3();
			}
			for(j=0;j<64;j++) SEND(y_buf[j] - 128);
			for(j=0;j<64;j++) SEND(cb_buf[j] - 128);
			for(j=0;j<64;j++) SEND(cr_buf[j] - 128);
		}

		printf("[Stage 2] Processed 551 blocks and sent to Stage 3.\n");
	}
}

int main (void) { levelshift(); return 0; }
