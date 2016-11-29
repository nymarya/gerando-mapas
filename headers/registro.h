#ifndef _REGISTRO_H
#define _REGISTRO_H


#include <stdio.h>

//DECLARAÇÃO DE STRUCT RGB
typedef struct RegPixel{
	int r;
	int g;
	int b;
} PIXEL;

//DECLARAÇÃO DO ENUM
typedef enum {
	AMANHECER,
	DIA, 
	ANOITECER,
	NOITE 
} Modo;


#endif