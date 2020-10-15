/*GPIO REGISTER MODELLEME*/

#ifndef GPIO_REG

#define GPIO_REG

#ifndef STDINT_H
#include <stdint.h>
#endif

//PORTD REGISTER ADRESLERI
#define REG_ADDR_PORTD				0x2B
#define REG_ADDR_DDRD				0x2A
#define REG_ADDR_PIND				0x29

//PORTC REGISTER ADRESLERI
#define REG_ADDR_PORTC				0x28
#define REG_ADDR_DDRC				0x27
#define REG_ADDR_PINC				0x26

//PORTB REGISTER ADRESLERI
#define REG_ADDR_PORTB				0x25
#define REG_ADDR_DDRB				0x24
#define REG_ADDR_PINB				0x23

#define REG_ADDR_PORTS				0x23

typedef struct
{
	uint8_t pin0:1;
	uint8_t pin1:1;
	uint8_t pin2:1;
	uint8_t pin3:1;
	uint8_t pin4:1;
	uint8_t pin5:1;
	uint8_t pin6:1;
	uint8_t pin7:1;
}pin_t , *pin_ptr_t;


typedef union
{
	pin_t pins;
	volatile uint8_t port;
}port_t , *port_ptr_t;


typedef struct
{
	port_t _PINB_;
	port_t _DDRB_;
	port_t _PORTB_;
	port_t _PINC_;
	port_t _DDRC_;
	port_t _PORTC_;	
	port_t _PIND_;
	port_t _DDRD_;
	port_t _PORTD_;		
} gpio_t , *gpio_ptr_t;

#define GPIO				(*(gpio_ptr_t)REG_ADDR_PORTS)






//Lojik pin deðerleri

#define PIN_INPUT			0
#define PIN_OUTPUT			1
#define PORT_INPUT			0x00
#define PORT_OUTPUT			0xFF
#define PIN_HIGH			1
#define PIN_LOW				0
#define PORT_HIGH			0xFF
#define PORT_LOW			0x00







#endif /*GPIO_REG_H*/