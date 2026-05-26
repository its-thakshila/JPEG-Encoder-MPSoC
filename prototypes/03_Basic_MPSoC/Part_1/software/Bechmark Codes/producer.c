#include <stdio.h>
#include <sys/alt_timestamp.h>
#include "FIFO_1.h"

int main()
{
    printf("Producer starting benchmark...\n");

    // Producer clears the memory and resets pointers
    FIFO_1_INIT(1);

    int total_tokens = 100000;

    int j;
    for(j = 1; j <= total_tokens; j++) {
        WRITE_FIFO_1(&j);
    }

    // Send one final dummy token to release the consumer
    int dummy = 0;
    WRITE_FIFO_1(&dummy);

    return 0;
}
