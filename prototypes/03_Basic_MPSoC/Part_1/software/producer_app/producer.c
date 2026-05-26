#include <stdio.h>
#include "FIFO_1.h"

void delay(int n);
int producer();

int main()
{
	producer();

	// Give the JTAG UART a moment to transmit the text before halting
	volatile int dummy;
	for(dummy = 0; dummy < 500000; dummy++);

	while(1) { }
	return 0;
}

int producer()
{
	printf("Producer starting..\n");

	// Part 1: Pass 1 to clear the shared memory
	FIFO_1_INIT(1);

	int j = 5;
	while(j<=500)
	{
		delay(100000);
		WRITE_FIFO_1(&j); // Write to the producer-consumer fifo
		delay(100000);

		printf("Producer sent [%i]\n",j);
		j+=10;
	}

	printf("Producer finished..\n");
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
