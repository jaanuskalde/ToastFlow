#include <avr/sleep.h>

#define average(old, new) ( (new >> 2)+(old - (old >> 2)) )

int main()
{

	// Clear interrupts
	cli();

	// Inputs and outputs
	DDRB = 0b00000111;

	//Enable interrupts
	sei();

	while (1)
	{

	}
}
