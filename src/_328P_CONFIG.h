

#ifndef _328P_CONFIG_H_
#define _328P_CONFIG_H_



#ifndef INT_H
#include <stdint.h>
#endif
#include "src/_328P_GPIO_.h"
#ifndef GPIO_H
#include "src/_328P_GPIO_.h"
#endif

#ifdef USE_PORTB
#define ddrb			GPIO._DDRB_
#define portb			GPIO._PORTB_
#define pinb			GPIO._PINB_
#endif

#ifdef USE_PORTB
#define ddrb			GPIO._DDRB_
#define portb			GPIO._PORTB_
#define pinb			GPIO._PINB_
#endif

#ifdef USE_PORTB
#define ddrb			GPIO._DDRB_
#define portb			GPIO._PORTB_
#define pinb			GPIO._PINB_
#endif

#ifndef TIMER0_H
#include "Source/Timers/_328P_TIMER0_.h"
#endif

#ifndef TIMER1_H
#include "Source/Timers/_328P_TIMER1_.h"
#endif





#endif /* _328P_CONFIG_H_ */