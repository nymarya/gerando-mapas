#ifndef _REGISTRO_H
#define _REGISTRO_H


#include <stdio.h>

/** Declaração do struct de Pixel. **/
typedef struct RegPixel{
	int r;
	int g;
	int b;
} PIXEL;

/** Declaração do enum. **/
typedef enum {
	AMANHECER,
	DIA, 
	ANOITECER,
	NOITE 
} Modo;


#endif