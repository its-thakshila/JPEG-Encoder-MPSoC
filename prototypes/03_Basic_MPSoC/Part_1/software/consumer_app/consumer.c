#include <stdio.h>
#include "FIFO_1.h"

void delay(int n);
int consumer();

int main()
{
	consumer();
	
	// Give the JTAG UART a moment to transmit the text before halting
	volatile int dummy;
	for(dummy = 0; dummy < 500000; dummy++);

	while(1) { }
	return 0;
}

int consumer()
{
	printf("Consumer starting..\n");

	// Part 1: Pass 0 so the Consumer DOES NOT wipe the Producer's data
	FIFO_1_INIT(0);

	int j = 0;
	int k = 5;
	while(k<500)
	{
		READ_FIFO_1(&j);  // Read from the producer-consumer fifo
		if(j==k)
			printf("Consumer successfully received [%i]\n",j);

		k+=10;
	}

	printf("Consumer finished..\n");
	return 0;
}

void delay(int n)
{
	int i;
	for(i=n; i>0; i--)
	{
		continue;
	}
}
