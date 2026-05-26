#include <stdio.h>
#include <sys/alt_timestamp.h>
#include "FIFO_1.h"

int main()
{
    printf("Consumer starting benchmark...\n");
    FIFO_1_INIT(); // Hardware FIFO init

    int total_tokens = 100000;
    int received_value = 0;

    if (alt_timestamp_start() < 0) {
        printf("Error: Timestamp timer not found!\n");
        return 1;
    }

    alt_u32 start_time = alt_timestamp();

    int k;
    for(k = 1; k <= total_tokens; k++) {
        READ_FIFO_1(&received_value);
    }

    alt_u32 end_time = alt_timestamp();
    alt_u32 clock_freq = alt_timestamp_freq();

    // Calculate Consumer time
    alt_u32 ticks_total = end_time - start_time;
    alt_u32 time_ms_consumer = ticks_total / (clock_freq / 1000);

    // Read the dummy token so the Producer can safely exit
    READ_FIFO_1(&received_value);

    // Print the final, accurate system time
    printf("\n--- PART 2 HARDWARE FIFO RESULTS ---\n");
    printf("Tokens Transferred : %d\n", total_tokens);
    printf("Hardware FIFO Time : %u ms\n", (unsigned int)time_ms_consumer);
    printf("------------------------------------\n");

    return 0;
}
