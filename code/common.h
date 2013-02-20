#ifndef COMMON_H
#define COMMON_H

#define F_CPU 9600000UL

// AVR includes
#include <avr/interrupt.h>
#include <avr/io.h>

//! Makro biti seadmiseks
#define setbit(ADDRESS, BIT) (ADDRESS |= (1 << BIT))
//! Makro biti nullimiseks
#define clearbit(ADDRESS, BIT) (ADDRESS &= ~(1 << BIT))
//! Makro biti vastupidiseks panemiseks
//! Makro biti testimiseks


#endif
