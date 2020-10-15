#ifndef _TIMER1_REGISTER_
#define _TIMER1_REGISTER_


#define REG_ADDR_TCCR1			0x80
#define REG_ADDR_TIMSK1			0x6F
#define REG_ADDR_OCR1A			0x88

typedef struct
{
	uint8_t vgm1A:2;
	uint8_t reservedA:2;
	uint8_t com1B:2;
	uint8_t com1A:2;
	uint8_t clocks:3;
	uint8_t vgm1B:2;
	uint8_t reservedB:1;
	uint8_t ices1:1;
	uint8_t icnc1:1;
}_tccr1_t , *_tccr1_ptr_t;

typedef union
{
	_tccr1_t bits1;
	volatile uint16_t value1;
}tccr1_t , *tccr1_ptr_t;

#define TIMER1_MODE			(*(tccr1_ptr_t)REG_ADDR_TCCR1)
			
typedef enum
{
	_00_MODE_NORMAL = 0,
	_01_PWM_8BIT = 1,
	_02_PWM_9BIT = 2,	
	_03_PWM_10BIT = 3,
	_04_CTC_ON_OCR1A = 4,
	_05_FASTPWM_8BIT = 5,
	_06_FASTPWM_9BIT = 6,
	_07_FASTPWM_10BIT = 7,
	_08_PWMP_PFC_ICR1 = 8,
	_09_PWMP_PFC_OCR1A = 9,
	_10_PWM_PC_ICR1 = 10,
	_11_PWM_PC_OCR1A = 11,
	_12_CTC_ON_ICR1 = 12,
	_13_FASTPWM_ICR1 = 13,	
	_14_FASTPWM_OCR1A = 14,	
}timer1_modes_t;

void set_timer1_mode(timer1_modes_t mode_selection);

void set_timer1_mode(timer1_modes_t mode_selection)
{
	TIMER1_MODE.value1 = 0x0000;
	switch (mode_selection)
	{
		case 0:TIMER1_MODE.value1 |= 0x0000; break;
		case 1:TIMER1_MODE.value1 |= 0x0001; break;
		case 2:TIMER1_MODE.value1 |= 0x0002; break;
		case 3:TIMER1_MODE.value1 |= 0x0003; break;
		case 4:TIMER1_MODE.value1 |= 0x0800; break;
		case 5:TIMER1_MODE.value1 |= 0x0801; break;
		case 6:TIMER1_MODE.value1 |= 0x0802; break;
		case 7:TIMER1_MODE.value1 |= 0x0803; break;
		case 8:TIMER1_MODE.value1 |= 0x1000; break;
		case 9:TIMER1_MODE.value1 |= 0x1001; break;
		case 10:TIMER1_MODE.value1 |= 0x1002; break;
		case 11:TIMER1_MODE.value1 |= 0x1003; break;
		case 12:TIMER1_MODE.value1 |= 0x1800; break;
		case 13:TIMER1_MODE.value1 |= 0x1802; break;
		case 14:TIMER1_MODE.value1 |= 0x1803; break;
		default: break;				
	}
}






					
#define TIMER1_CLOCK_SELECTION				TIMER1_MODE.bits1.clocks

typedef enum
{
	NO_CLOCK_SOURCE = 0,
	NO_PRESCALER = 1,
	PRESCALER_8 = 2,
	PRESCALER_64 = 3,
	PRESCALER_256 = 4,
	PRESCALER_1024 = 5,
	FALLING_EDGE = 6,
	RISING_EDGE = 7,
	
}timer1_clock_mode_t;

void set_timer1_clock(timer1_clock_mode_t clock_select);
void set_timer1_clock(timer1_clock_mode_t clock_select)
{
	
	switch (clock_select)
	{
		case 0: TIMER1_CLOCK_SELECTION = 0; break;
		case 1: TIMER1_CLOCK_SELECTION = 1; break;
		case 2: TIMER1_CLOCK_SELECTION = 2; break;
		case 3: TIMER1_CLOCK_SELECTION = 3; break;
		case 4: TIMER1_CLOCK_SELECTION = 4; break;
		case 5: TIMER1_CLOCK_SELECTION = 5; break;
		case 6: TIMER1_CLOCK_SELECTION = 6; break;
	    case 7: TIMER1_CLOCK_SELECTION = 7; break;
		default: break;
	}	

}

typedef struct
{
	uint8_t toie1:1;
	uint8_t ocie1A:1;
	uint8_t ocie1B:1;
	uint8_t reservedA:2;
	uint8_t icie1:1;
	uint8_t reservedB:2;
}_timsk1_t , *_timsk1_ptr_t;

typedef union
{
	_timsk1_t bits;
	volatile uint8_t value;
}timsk1_t , *timsk1_ptr_t;

#define TIMSK1_UNION					(*(timsk1_ptr_t)REG_ADDR_TIMSK1)


typedef struct
{
	volatile uint16_t value:16;
}_ocr1A_t , *_ocr1A_ptr_t;

#define OCR1A_UNION						(*(_ocr1A_ptr_t)REG_ADDR_OCR1A)
#define timer1_ocr1A_value				OCR1A_UNION.value
#define TIMER1_INT_ENABLE				TIMSK1_UNION.value
typedef enum
{
	timer1_toie,
	timer1_ocieA,
	timer1_ocieB,
	timer1_icie,
}timer1_int_t;

void set_timer1_int(timer1_int_t int_select);
void set_timer1_int(timer1_int_t int_select)
{
	switch (int_select)
	{
		case 0: TIMSK1_UNION.bits.toie1 = 1; break;
		case 1: TIMSK1_UNION.bits.ocie1A = 1; break;
		case 2: TIMSK1_UNION.bits.ocie1B = 1; break;
		case 3: TIMSK1_UNION.bits.icie1 = 1; break;
		default: break;
	}
}


#endif    /*_TIMER1_REGISTER_*/
