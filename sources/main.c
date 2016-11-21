#include <stdio.h>
#include "../headers/contorno.h"
#include "../headers/imagem.h"


int main() {
	int tam = 513; //2^9+1

	float desloc = 1.2;
	int vetor[tam]; 
	PIXEL matriz[tam][tam];

	int i;
	for (i = 0; i < tam; i++){
		vetor[i] = 0;
	}

	vetor[0] = 250;
	vetor[tam-1] = 201;


	deslocamentoDireita(tam, desloc, 0, tam-1, vetor);
	gerarMatriz(tam, matriz, vetor);
	escreverImagem(tam, matriz);


}