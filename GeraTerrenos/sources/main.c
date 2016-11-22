#include <stdio.h>
#include <stdlib.h>
#include "../headers/contorno.h"
#include "../headers/imagem.h"



int main() {
	int tam = 513; //2^9+1

	int desloc = 128;
	int vetor[tam]; 
	PIXEL matriz[tam][tam];

	int i;
	for (i = 0; i < tam; i++){
		vetor[i] = 0;
	}

	srand(time(0) * getpid());

	vetor[0] = rand()%300+70;
    vetor[tam-1] = rand()%300+70;


	deslocamentoPonto(0, tam-1, tam, desloc, vetor);
	gerarMatriz(tam, matriz, vetor);
	escreverImagem(tam, matriz);


}