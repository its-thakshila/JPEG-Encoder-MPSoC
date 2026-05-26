#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"

#include "system.h"
#include <altera_avalon_fifo_regs.h>

// --- HARDCODE BYPASS FOR ECLIPSE BSP DESYNC ---
#ifndef FIFO_1_6_FILE_OUT_BASE
#define FIFO_1_6_FILE_OUT_BASE 0x0104100c
#endif

#ifndef FIFO_5_6_DATA_OUT_BASE
#define FIFO_5_6_DATA_OUT_BASE 0x01041010
#endif

#ifndef FIFO_5_6_SIZE_OUT_BASE
#define FIFO_5_6_SIZE_OUT_BASE 0x01041008
#endif
// ----------------------------------------------

// READ DIRECTLY USING THE PHYSICAL SILICON ADDRESSES
#define RECV1() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_1_6_FILE_OUT_BASE)
#define RECV2() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_5_6_DATA_OUT_BASE)
#define RECV3() IORD_ALTERA_AVALON_FIFO_DATA(FIFO_5_6_SIZE_OUT_BASE)

typedef char INT8;
typedef unsigned char UINT8;

int main(void){
	UINT8 out; INT8 filename[100]; char full_path[150]; int byte_count = 0;
	int start_time, end_time, total_ticks;
	int ticks_per_sec = alt_ticks_per_second();

	printf("Stage 6: File Writer Initialized. Waiting for pipeline start...\n");

	while(1){
		int idx = 0;
		out = (INT8)RECV1();

		if (out == '\0'){
			printf("\nStage 6: Received termination signal from Stage 1. Exiting safely.\n");
			break;
		}

		filename[idx++] = out;
		while(1){
			out = (INT8)RECV1(); filename[idx++] = out;
			if(out == '\0') break;
		}

		sprintf(full_path, "/mnt/host/%s", filename);
		printf("\n[Stage 6] Intercepted filename: %s\n", filename);
		printf("[Stage 6] Creating file at: %s\n", full_path);

		FILE *fp = fopen(full_path, "wb");
		if (fp == NULL) printf("Stage 6 Error: Cannot create file %s\n", full_path);

		printf("[Stage 6] Receiving JPEG bitstream from Stage 5 and writing to disk...\n");
		start_time = alt_nticks(); byte_count = 0;

		while(1){
            out = (UINT8)RECV2();
            if(fp) fputc(out, fp);
            byte_count++;
            if (out == 0xFF){
                out = (UINT8)RECV2();
                if(fp) fputc(out, fp);
                byte_count++;
                if(out == 0xD9) break;
            }
		}
		if(fp) fclose(fp);
		RECV3();
		end_time = alt_nticks(); total_ticks = end_time - start_time;
		float total_seconds = (float)total_ticks / ticks_per_sec;
		float kb_per_sec = ((float)byte_count / 1024.0) / total_seconds;

		printf("\n================= STAGE 6 PERFORMANCE =================\n");
		printf("Total Compressed File Size   : %d bytes (%.2f KB)\n", byte_count, (float)byte_count / 1024.0);
		printf("Disk Write Throughput        : %.2f KB/second\n", kb_per_sec);
		printf("=======================================================\n");
		printf("[Stage 6] Image processing complete! Waiting for next file...\n");
	}
	return 0;
}
