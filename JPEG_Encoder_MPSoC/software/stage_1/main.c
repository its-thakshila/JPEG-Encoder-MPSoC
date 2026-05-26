#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_alarm.h" // Altera Timer Library for performance measurement
#include "datatype.h"
#include "jdatatype.h"
#include "config.h"
#include "prototype.h"
#include "encoder.h"

// Actual dimensions of the 227flowg1.raw image
#define IMAGE_WIDTH  227
#define IMAGE_HEIGHT 149
#define FILE_NAME    "227flowg1.raw"
#define OUTPUT_NAME  "227flowg1.jpg"

int main(void){

	UINT8 *output_ptr = NULL;
	UINT32 quality_factor = 50;
	UINT32 image_format = FOUR_FOUR_FOUR;
	UINT32 image_width = IMAGE_WIDTH;
	UINT32 image_height = IMAGE_HEIGHT;

	printf("Stage 1: Initializing bare-metal encoder...\n");

	// 1. Allocate memory for the raw image in the massive SDRAM
	UINT32 image_size = image_width * image_height * 3;
	UINT8 *image_buffer = (UINT8 *)malloc(image_size);

	if (image_buffer == NULL) {
		printf("Stage 1 Error: Failed to allocate %lu bytes in SDRAM!\n", image_size);
		return -1;
	}

	// 2. Read the raw file from the computer's hard drive using HostFS
		printf("Stage 1: Opening /mnt/host/%s ...\n", FILE_NAME);
		FILE *fp = fopen("/mnt/host/" FILE_NAME, "rb");
		if (fp == NULL) {
			printf("Stage 1 Error: Cannot open file /mnt/host/%s\n", FILE_NAME);
			printf("Make sure the file is placed directly in your Eclipse project folder!\n");
			free(image_buffer);
			return -1;
		}

		printf("Stage 1: File opened! Downloading over JTAG (this may take a moment)...\n");

		// Read in 1KB chunks to prevent JTAG buffer deadlock
		size_t total_read = 0;
		size_t chunk_size = 1024;

		while (total_read < image_size) {
			size_t bytes_to_read = image_size - total_read;
			if (bytes_to_read > chunk_size) {
				bytes_to_read = chunk_size;
			}

			size_t bytes_read = fread(image_buffer + total_read, 1, bytes_to_read, fp);
			if (bytes_read == 0) break; // Hit end of file

			total_read += bytes_read;

			// Print a dot every 10KB to prove it hasn't crashed
			if (total_read % (1024 * 10) < chunk_size) {
				printf(".");
			}
		}
		fclose(fp);

		printf("\n");
		if (total_read != image_size) {
			printf("Stage 1 Warning: Expected %lu bytes, but only read %lu bytes.\n", image_size, total_read);
		} else {
			printf("Stage 1: Successfully loaded %lu bytes into SDRAM.\n", total_read);
		}

	// 3. Send output filename to Stage 6
	char *file_ptr = OUTPUT_NAME;
	while(*file_ptr != '\0'){
		SEND6(*file_ptr);
		file_ptr++;
	}
	SEND6('\0');

	printf("Stage 1: Pumping image blocks into the FIFOs...\n");

	// 4. Setup Performance Timers
	int start_time, end_time, total_ticks;
	int ticks_per_sec = alt_ticks_per_second();

	start_time = alt_nticks(); // START THE STOPWATCH

	// 5. Start the massive encoding pipeline!
	output_ptr = encode_image(image_buffer, output_ptr, quality_factor, image_format, image_width, image_height);

	end_time = alt_nticks(); // STOP THE STOPWATCH

	SEND6(0); // Send EOF signal to Stage 6 so it closes the file

	// 6. Calculate and print Throughput
	total_ticks = end_time - start_time;
	float total_seconds = (float)total_ticks / ticks_per_sec;

	// Calculate total macro-blocks (MCUs). For 4:4:4, MCUs are 8x8 pixels.
	UINT16 h_mcus = (image_width + 7) / 8;
	UINT16 v_mcus = (image_height + 7) / 8;
	UINT32 total_mcus = h_mcus * v_mcus;

	printf("\nStage 1: Finished sending data!\n");
	printf("================= PERFORMANCE =================\n");
	printf("Total Macro-blocks processed : %lu\n", total_mcus);
	printf("Total Execution Ticks        : %d\n", total_ticks);
	printf("Total Execution Time         : %f seconds\n", total_seconds);
	printf("Average Time per Macro-block : %f seconds\n", total_seconds / total_mcus);
	printf("===============================================\n");

	free(image_buffer);
	return 0;
}

// Override the custom Tensilica allocator to use our standard SDRAM malloc
void* jemalloc(size_t size)
{
	return malloc(size);
}
