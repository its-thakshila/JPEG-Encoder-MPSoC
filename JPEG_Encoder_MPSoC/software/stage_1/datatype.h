#ifndef DATATYPE_H
#define DATATYPE_H

typedef char			INT8;
typedef unsigned char	UINT8;

typedef short			INT16;
typedef unsigned short	UINT16;

typedef int				INT32;
typedef unsigned int	UINT32;

// --- ALTERA HARDWARE FIFO INTEGRATION (STAGE 1) ---
#include "system.h"
#include <altera_avalon_fifo_regs.h>

// 1. Send Y block to Stage 2
#define SEND1(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_2_Y_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_Y_IN_BASE, data); \
} while(0)

// 2. Send Cb block to Stage 2
#define SEND2(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_2_CB_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_CB_IN_BASE, data); \
} while(0)

// 3. Send Cr block to Stage 2
#define SEND3(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_2_CR_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_2_CR_IN_BASE, data); \
} while(0)

// 4. Send Quantization Tables to Stage 4
#define SEND4(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_4_QUANT_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_4_QUANT_IN_BASE, data); \
} while(0)

// 5. Send Huffman Tables to Stage 5
#define SEND5(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_5_HUFF_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_5_HUFF_IN_BASE, data); \
} while(0)

// 6. Send Output Filename to Stage 6
#define SEND6(data) do { \
    while (IORD_ALTERA_AVALON_FIFO_STATUS(FIFO_1_6_FILE_IN_CSR_BASE) & ALTERA_AVALON_FIFO_STATUS_F_MSK); \
    IOWR_ALTERA_AVALON_FIFO_DATA(FIFO_1_6_FILE_IN_BASE, data); \
} while(0)
// --------------------------------------------------

#endif
