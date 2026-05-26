#include "FIFO_1.h"

void FIFO_1_INIT()
{
    // Hardware FIFO initialization is handled by the FPGA fabric.
}

// Only compile this function if the CPU is physically connected to the IN port
#ifdef FIFO_0_IN_BASE
void WRITE_FIFO_1(int *buffer)
{
    // 1. Wait if the FIFO is FULL (Bit 0)
    while( (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_0_IN_CSR_BASE) & FIFO_FULL_MSK) )
    {
        // Spin/Wait
    }

    // 2. Write data to the FIFO
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_0_IN_BASE, *buffer);
}
#endif


// Only compile this function if the CPU is physically connected to the OUT port
#ifdef FIFO_0_OUT_BASE
void READ_FIFO_1(int *buffer)
{
    // 1. Wait if the FIFO is EMPTY (Bit 1)
    while( (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_0_IN_CSR_BASE) & FIFO_EMPTY_MSK) )
    {
        // Spin/Wait
    }

    // 2. Read data from the FIFO
    *buffer = IORD_ALTERA_AVALON_FIFO_DATA(FIFO_0_OUT_BASE);
}
#endif
