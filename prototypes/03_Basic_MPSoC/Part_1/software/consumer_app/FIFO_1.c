#include "FIFO_1.h"

// Define the variables
int writep;
int readpp;
int fullp;
int emptyp;
int countp;

// Initialization
void FIFO_1_INIT(int init_shared_mem)
{
    // 1. Always initialize local pointer offsets
    fullp = 0x00;
    emptyp = 0x04;
    countp = 0x08;
    writep = STARTP;
    readpp = STARTP;

    // 2. Only initialize Shared Memory hardware flags if asked (Producer only)
    if(init_shared_mem == 1)
    {
        IOWR_32DIRECT(MEM_BASE, fullp, 0);  // Not full
        IOWR_32DIRECT(MEM_BASE, emptyp, 1); // Is Empty
        IOWR_32DIRECT(MEM_BASE, countp, 0); // Count is 0
    }
}

void WRITE_FIFO_1(int *buffer)
{
    // 1. Wait if the fifo is full (Spinlock)
    while(IORD_32DIRECT(MEM_BASE, fullp) == 1) {
        // Just wait
    }

    // 2. Write the data to FIFO
    IOWR_32DIRECT(MEM_BASE, writep, *buffer);

    // 3. Update the write pointer
    writep += UNIT_SIZE;
    // Wrap around logic
    if(writep >= (STARTP + (CAPACITY * UNIT_SIZE))) {
        writep = STARTP;
    }

    // 4. Update "count" in shared mem
    int current_count = IORD_32DIRECT(MEM_BASE, countp);
    current_count++;
    IOWR_32DIRECT(MEM_BASE, countp, current_count);

    // 5. Update flags
    if(current_count == CAPACITY) {
        IOWR_32DIRECT(MEM_BASE, fullp, 1);
    }
    // We just added data, so it can't be empty
    IOWR_32DIRECT(MEM_BASE, emptyp, 0);
}

void READ_FIFO_1(int *buffer)
{
    // 1. Wait if the fifo is empty
    while(IORD_32DIRECT(MEM_BASE, emptyp) == 1) {
        // Just wait
    }

    // 2. Read the data
    *buffer = IORD_32DIRECT(MEM_BASE, readpp);

    // 3. Update the read pointer
    readpp += UNIT_SIZE;
    // Wrap around logic
    if(readpp >= (STARTP + (CAPACITY * UNIT_SIZE))) {
        readpp = STARTP;
    }

    // 4. Update count
    int current_count = IORD_32DIRECT(MEM_BASE, countp);
    current_count--;
    IOWR_32DIRECT(MEM_BASE, countp, current_count);

    // 5. Update flags
    if(current_count == 0) {
        IOWR_32DIRECT(MEM_BASE, emptyp, 1);
    }
    // We just read data, so it can't be full
    IOWR_32DIRECT(MEM_BASE, fullp, 0);
}
