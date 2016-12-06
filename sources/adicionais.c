#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include "../headers/registro.h"
#include "../headers/imagem.h"
#include "../headers/adicionais.h"


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
	        (cores[modo][2] > 0)? cores[modo][2]-- : 0;
	        if(i%5 == 0){
		    cores[modo][1]++;
	        }
	    } else if( modo == DIA){
	        if(i%2 ==0){
		    (cores[modo][1] > 0)? cores[modo][1]-- : 0;
		    (cores[modo][2] > 0)? cores[modo][2]-- : 0;
	        } 
		if(i%5 == 0){
		    (cores[modo][0] < 255)? cores[modo][0]++ : 255;
	        }
	    } else if( modo == ANOITECER){
	        if(i%2 ==0){
		    (cores[modo][2] < 255)? cores[modo][2]++ : 255;
	        } 
		if(i%5 == 0){
		    (cores[modo][1] < 255)? cores[modo][1]++ : 255;
	        }
	    } else if( modo == NOITE){
	        if(i%5 == 0){
		    (cores[modo][2] < 255)? cores[modo][2]++ : 255;
	        }
	        gerarLua(tam, matriz);
	    }

	    for (j = 0; j < tam; j++) {
	        configuraPixel(&matriz[i][j], cores[modo][0], cores[modo][1], cores[modo][2]);
	    }
		
	}
	
	return 0;

}



/**
 * Função para gerar lua.
 * @param tam      Dimensão da matriz (quadrada)
 * @param matriz   Matriz que será alterada
 */

void gerarLua(int tam, PIXEL matriz[tam][tam]){
    
 
    /**
    
    O ponto central da lua é dado pelas coordenadas (400, 70)
    O círculo está inserido dentro de um quadrado que varia de 
    	- (350 - 450) de largura ~ eixo x no plano cartesiano
    	- (20  - 120) de altura  ~ eixo y no plano cartesiano
    
    
    A distancia euclidiana é dada por
    	1. soma = pow((j-400), 2) + pow((i-150), 2);
    	2. d = srqt(soma).
    
    Os pontos que estarão dentro do círculo possuem distancia do centro ao ponto menor que o raio.
    
    **/
    int i, j, soma, d, raio=50;

    for (i = 20; i < 120; i++) {
	for (j = 350; j < 450; j++) {
		soma = pow((j-400), 2) + pow((i-70), 2);
		d = sqrt(soma);
		if (d < raio) {
		    matriz[i][j].r = 211;
		    matriz[i][j].g = 211;
		    matriz[i][j].b = 211;
		}
 	 }
    }
}
