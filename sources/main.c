#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/registro.h"
#include "../headers/contorno.h"
#include "../headers/imagem.h"



int main(int n, char **str)
{
    
    char nome_do_arquivo[30];
    strcpy(nome_do_arquivo, "terreno.ppm");

	if(n>1){
	    if(strcmp(str[1], "-o") == 0){
		strcpy(nome_do_arquivo, str[2]);
	    }
	}
        

	int tam = 513; //2^9+1

	int desloc = 128;
	int vetor[tam]; 
	PIXEL matriz[tam][tam];

	int i;
	for (i = 0; i < tam; i++){
		vetor[i] = 0;
	}

    //Gera números mais diversificados
    //http://stackoverflow.com/questions/5574914/srandtimenull-doesnt-change-seed-value-quick-enough
	srand(time(0) * getpid());

	vetor[0] = rand()%300+70;
    vetor[tam-1] = rand()%300+70;


	deslocamentoPonto(0, tam-1, tam, desloc, vetor);
	gerarMatriz(tam, matriz, vetor);
	escreverImagem(tam, matriz, nome_do_arquivo);

}