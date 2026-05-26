#include <stdio.h>
#include <sys/alt_timestamp.h>
#include "FIFO_1.h"

int main()
{
    printf("Producer starting benchmark...\n");
    FIFO_1_INIT(); // Hardware FIFO init

    int total_tokens = 100000;

    // Start timer just to ensure it's linked, but we won't print it
    if (alt_timestamp_start() < 0) return 1;

    int j;
    for(j = 1; j <= total_tokens; j++) {
        WRITE_FIFO_1(&j);
    }

    // Send one final dummy token to release the consumer
    int dummy = 0;
    WRITE_FIFO_1(&dummy);

    return 0;
}
