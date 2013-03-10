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

	cli();	// Clear interrupts
	PORTB |= TRIAC; //Turn off the Triac
	DDRB = 0b00010100;

	//ADC conf
	ADMUX = ADLAR | MUX1 | MUX0;
	ADCSRA = ADEN | ADPS1 | ADPS0;
	sei();//Enable interrupts
	
	enum 
	{
		OFF, 
		PREHEAT, 
		REFLOW
	} state = OFF;

	uint8_t last_sense = 0;
	uint16_t counter = 0;
	uint16_t last_voltage = 0;
	uint8_t heater_request = 0;

	//Application loop
	while (1)
	{
		//Wait for button pressing 
		while (SWITCH & PINB)
		{
			counter ++;
			if (counter & 0x10) PORTB |= LED else PORTB &= ~LED;
			_delay_ms(4);
		}

		state = PREHEAT;
		PORTB |= LED;
		counter = 0;

		while (state != OFF)
		{
			if (PINB & SENSE)
			{
				last_sense = 1;
			}
			else //on falling edge
			{
				if (last_sense)//turn on for this whole cycle
				{
					if (heater_request)
					{
						PORTB &= ~TRIAC;
						_delay_us(50);
						PORTB |= TRIAC;
						_delay_ms(10);
						PORTB &= ~TRIAC;
						_delay_us(50);
						PORTB |= TRIAC;
					}
					else
					{
						_delay_ms(11);
					}
					counter ++;
					if (state == PREHEAT) PORTB ^= LED; //blink the led
				}
				last_sense = 0;
			}
			//about 19ms to do measurement and user interaction
			
			ADCSRA |= ADSC; //start conversion
			while (~ADCSRA & ADIF);//wait it to complete
			last_voltage = average(last_voltage, ADC);//get the content

			switch(state)
			{
				case OFF:
					PORTB &= ~LED;
					break;
				case PREHEAT:
					if (last_voltage < 41200) heater_request = 0; else heater_request = 1;
					if (counter > 3500)
					{
						state = REFLOW;
						PORTB |= LED;
						counter = 0;
					}
					break;
				case REFLOW:
					if (last_voltage < 36000) heater_request = 0; else heater_request = 1;
					if (counter > 4500)
					{
						state = OFF;
						counter = 0;
					}
					break;
			}
			
			_delay_ms(1);
		}
	}
}
