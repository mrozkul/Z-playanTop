#ifndef _TIMER0_REGISTER_
#define _TIMER0_REGISTER_


#define REG_ADDR_TCCR0					0x44
#define REG_ADDR_TCNT0					0x46
#define REG_ADDR_TIFR0					0x35
#define REG_ADDR_TIMSK0					0x6E
#define REG_ADDR_OCR0A					0x47

typedef struct
{
	uint8_t vgmA:2;
	uint8_t reservedA:2;
	uint8_t com0B:2;
	uint8_t com0A:2;
	uint8_t clockselect:3;
	uint8_t vgmB:1;
	uint8_t reservedB:2;
	uint8_t foc0b:1;
	uint8_t foc0a:1;
}	_tccr_t,*_tccr_ptr_t;

typedef union
{
	_tccr_t bits;
	volatile uint16_t value;
}tccr_t , *tccr_ptr_t;

#define TCCR0_UNION						(*(tccr_ptr_t)REG_ADDR_TCCR0)
#define TIMER0_MODE_SELECTION			TCCR0_UNION.bits.vgmA
#define TIMER0_CLOCK_SELECTION			TCCR0_UNION.bits.clockselect

//WaveForm generation modes

#define TIMER0_Normal_mode					0
#define TIMER0_CTC_mode						2

//Clock Select Modes

#define no_clock_source			0
#define no_prescaling			1
#define prescaler_8				2
#define prescaler_64			3
#define prescaler_256			4
#define prescaler_1024			5
#define falling_edge			6
#define rising_edge				7

typedef struct
{
	volatile uint8_t worth:8;
}tcnt_t , *tcnt_ptr_t;

#define REG_COUNTER			(*(tcnt_ptr_t)REG_ADDR_TCNT0)
#define timer0_counter		REG_COUNTER.worth



typedef struct
{
	uint8_t tov:1;
	uint8_t ocf0A:1;
	uint8_t ocf0B:1;
	uint8_t reserved:5;
}tifr_t , *tifr_ptr_t;

#define REG_TIFR				(*(tifr_ptr_t)REG_ADDR_TIFR0)  //timer/counter interrupt flag register pin

typedef struct
{
	uint8_t toie0:1;
	uint8_t ocie0A:1;
	uint8_t ocie0B:1;
	uint8_t reserved:5;
}_timsk_t , *_timsk_ptr_t;

typedef union
{
	_timsk_t bits;
	volatile uint8_t value;
	
}timsk_t , *timsk_ptr_t;

#define TIMSK0_UNION					(*(timsk_ptr_t)REG_ADDR_TIMSK0)  //timer/counter interrupt enable pin
#define TIMER0_INTERRUPT_OVERFLOW		TIMSK0_UNION.bits.toie0
#define TIMER0_INTERRUPT_OCIE0A			TIMSK0_UNION.bits.ocie0A
#define TIMER0_INTERRUPT_OCIE0B			TIMSK0_UNION.bits.ocie0B
#define timer0_interrupt_enable			1
#define timer0_interrupt_disable		0

typedef struct  
{
	uint8_t deger:8;
}ocr0a_t , *ocr0a_ptr_t;

#define OCR0A_		(*(ocr0a_ptr_t)REG_ADDR_OCR0A)


#endif  /*_TIMER0_REGISTER_*/

