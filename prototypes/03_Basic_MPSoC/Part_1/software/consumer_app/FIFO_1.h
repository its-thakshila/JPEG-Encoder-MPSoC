#ifndef FIFO_1_H_
#define FIFO_1_H_

#include <io.h>
#include "system.h"
#include <stdio.h>

// TODO: OPEN system.h AND FIND THE ADDRESS FOR 'shared_mem'
// Replace 0x8000 with your actual address!
#define MEM_BASE SHARED_MEM_BASE

#define CAPACITY 10
#define UNIT_SIZE 4       // Size of int = 4 bytes
#define STARTP 0x0C       // Offset 12 (Skip Full, Empty, Count)

// Pointers as offsets (extern tells the compiler they are defined in .c)
extern int writep;
extern int readpp;
extern int fullp;
extern int emptyp;
extern int countp;

void WRITE_FIFO_1(int *buffer);
void READ_FIFO_1(int *buffer);
void FIFO_1_INIT(int init_shared_mem);

#endif /* FIFO_1_H_ */
