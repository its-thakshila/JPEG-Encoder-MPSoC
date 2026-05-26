#ifndef FIFO_1_H_
#define FIFO_1_H_

#include <io.h>
#include "system.h"
#include <stdio.h>
#include <altera_avalon_fifo_regs.h>
#include <altera_avalon_fifo_util.h>

// Define our own masks based on Altera Datasheet Table 14-6
#define FIFO_FULL_MSK  0x01  // Bit 0
#define FIFO_EMPTY_MSK 0x02  // Bit 1

// Function Prototypes
void WRITE_FIFO_1(int *buffer);
void READ_FIFO_1(int *buffer);
void FIFO_1_INIT();

#endif /* FIFO_1_H_ */
