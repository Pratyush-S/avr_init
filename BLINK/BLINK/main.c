/*
 * BLINK.c
 *
 * Created: 17-09-2018 23:51:44
 * Author : Pratyush
 */ 

#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL

int main(void)
{
	DDRB=0xFF;   //
    while (1) 
    {
		PORTB=0xFF;
		_delay_ms(250);
			
		PORTB=0x00;
		_delay_ms(250);		
	
    }
return 0;
}

