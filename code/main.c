#define F_CPU 1200000UL

// AVR includes
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define average(old, new) ( (new >> 2)+(old - (old >> 2)) )

int main()
{

	// Clear interrupts
	cli();

	// Inputs and outputs
	DDRB = 0b00010100;

	//Enable interrupts
	sei();

	while (1)
	{
		_delay_ms(500);
		PORTB ^= 0x10; //Toggle the led
	}
}
