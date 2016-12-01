#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../headers/registro.h"
#include "../headers/imagem.h"

#define N 4
#define M 3

/** Cores iniciais de cada tipo de céu **/

int cores[N][M] = {
	{147, 25, 255}, //amanhecer
	{102, 255, 255}, //dia
	{0, 2, 76}, //anoitecer
	{0, 0, 0} //noite

};

/**
 * Função para gerar gradiente no céu.
 * @param tam      Dimensão da matriz (quadrada)
 * @param matriz   Matriz que será alterada
 * @param modo     Tipo de céu (AMANHECER, DIA, ANOITECER OU NOITE)
 */

int gerarGradiente(int tam, PIXEL matriz[tam][tam], Modo modo){
	
	int i, j;
	for (i = 0; i < tam; i++) {    
	
		if(modo == AMANHECER){
			cores[modo][2]--;
			if(i%5 == 0){
			   cores[modo][1]++;
			}
		} else if( modo == DIA){
		    if(i%2 ==0){
			    cores[modo][2]--;
				cores[modo][1]--;
			} if(i%5 == 0){
				cores[modo][0]++;
			}
		} else if( modo == ANOITECER){
			if(i%2 ==0){
				cores[modo][2]++;
			} if(i%5 == 0){
				cores[modo][1]++;
			}
		} else if( modo == NOITE){
			if(i%5 == 0){
				cores[modo][2]++;
			}
		}
		
		for (j = 0; j < tam; j++) {
			configuraPixel(&matriz[i][j], cores[modo][0], cores[modo][1], cores[modo][2]);
					
		}
		
	}
	
	return 0;

}