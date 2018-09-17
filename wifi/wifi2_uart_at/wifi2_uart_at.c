/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : wifi2_uart_at
//
//  Target Board : atmega32
//
//  Date Created : 18-09-2018 01:46:42
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>


#include "serial.h"
#include "lcd.h"


void init_uart() {
    // UART setup
    uint16_t ubbr_value = F_CPU / (16UL*BAUD) - 1;
    UBRR0H = (uint8_t) (ubbr_value >> 8);
    UBRR0L = (uint8_t) ubbr_value;
    UCSR0B = (1 << RXEN0)  | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    // Status LED on pin 16.
    DDRB |= (1<<DDB2);
}

void transmit(char c) {
    // Wait for the flag to say we're good to write to the data register.
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

char receive() {
    // Wait for the Rx flag to say we've received a message.
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}


int main()
{
	serial_init(9600);
	serial_select(2);
	
	while (1)
	{
		

		// write your code


	}

}