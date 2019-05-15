#pragma once
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef long double f128;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

#define FI(n) for(int i=0;i<n;++i)

#define set_bit(x,i) {x|=(1<<i);}
#define clear_bit(x,i) {x&=~(1<<i);}
#define toggle_bit(x,i) {x^=(1<<i);}

typedef union {
	u8 byte;
	struct {
		u8 b0 :1;
		u8 b1 :1;
		u8 b2 :1;
		u8 b3 :1;
		u8 b4 :1;
		u8 b5 :1;
		u8 b6 :1;
		u8 b7 :1;
	};
	struct {
		u8 B0 :1;
		u8 B1 :1;
		u8 B2 :1;
		u8 B3 :1;
		u8 B4 :1;
		u8 B5 :1;
		u8 B6 :1;
		u8 B7 :1;
	};

} reg8_t;
