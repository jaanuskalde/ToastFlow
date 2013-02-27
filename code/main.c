#define F_CPU 1200000UL

// AVR includes
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define average(old, new) ( (new >> 2)+(old - (old >> 2)) )

#define SENSE 0x01
#define SWITCH 0x02
#define TRIAC 0x04
#define THERMISTOR 0x08
#define LED 0x10;

int main()
{

	// Clear interrupts
	cli();

	PORTB |= TRIAC; //Toggle the led

	// Inputs and outputs
	DDRB = 0b00010100;

	//Enable interrupts
	sei();

	//turn on the led
	PORTB |= LED; //Toggle the led

	//delay while 
	while (SWITCH & PINB);

	char tmp = 0;

	while (1)
	{
		if (PINB & SENSE)
		{
			tmp = 1;
		}
		else
		{
			if (tmp)
			{
				PORTB &= ~TRIAC;
				_delay_us(50);
				PORTB |= TRIAC;
				_delay_ms(10);
				PORTB &= ~TRIAC;
				_delay_us(50);
				PORTB |= TRIAC;
			}
			tmp = 0;
		}

		_delay_ms(1);
		PORTB ^= LED; //Toggle the led
	}
}
