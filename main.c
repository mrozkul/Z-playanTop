/*
 * LedBouncing_V1.c
 *
 * Created: 12.10.2020 16:20:28
 * Author : Emre
 */ 


#include "src\_328P_GPIO_.h"
#include "src\Timers\_328P_TIMER0_.h"
#include <avr\interrupt.h>

void timer0_init();
void init();

uint16_t milisaniye , dusus , led_no ;
int8_t direction;
uint8_t ziplama_sayisi;
int main(void)
{
	timer0_init();
	GPIO._DDRD_.port = 0xFF;
	direction = 1;
	milisaniye = 0;
	led_no = 0;
	ziplama_sayisi = 0;
	dusus = 160;
	while(1)
	{
		
	}
}



ISR(TIMER0_COMPA_vect)
{
	milisaniye++;
	if (milisaniye >= dusus)
	{
		
		milisaniye=0;
		GPIO._PORTD_.port = (1<<led_no);
		
	
	if (led_no >= 7 )
	{
		 direction = 1;
		 ziplama_sayisi +=1;
	}
	if (led_no <= ziplama_sayisi)
	{
		direction = -1;
	}
		dusus += (5 * direction );
		led_no = led_no - direction;
	}


	
}




void timer0_init()
{
	TIMER0_INTERRUPT_OCIE0A = 1;
	TIMER0_MODE_SELECTION = TIMER0_CTC_mode;
	TIMER0_CLOCK_SELECTION = prescaler_64;
	sei();
	OCR0A_.deger = 249;  //1/64 prescaler da 249 Output compare Register degeri  = 1ms ediyor.
}