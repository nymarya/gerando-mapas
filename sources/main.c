#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/registro.h"
#include "../headers/contorno.h"
#include "../headers/imagem.h"



int main(int n, char **str)
{
    
    char nome_do_arquivo[30];
    int desloc = 128; // fator deslocamento padrão
    strcpy(nome_do_arquivo, "terreno.ppm"); //nome do arquivo padrão

	if(n>1){
	    if(strcmp(str[1], "-o") == 0){
		  strcpy(nome_do_arquivo, str[2]); //Se o primeiro parâmetro for "-o", copia o nome
		  
		  if(n>3){
    		  if(strcmp(str[3], "-d") == 0){
    		      desloc = atoi(str[4]);//Se o segundo parâmetor for "-d", altera o fator deslocamento
    		  }
		  }

	    }
	    else if(strcmp(str[1], "-d") == 0){
	        desloc = atoi(str[2]);//Se o primeiro parâmetro for "-d", altera o fator deslocamento
	        
	        if(n>3){
    	      if(strcmp(str[3], "-o") == 0){
    		      strcpy(nome_do_arquivo, str[4]);//Se o segundo parâmetro for "-o", copia o nome
    		  }
		    }

	    }
	}
        

	int tam = 513; //2^9+1

	
	int vetor[tam]; 
	PIXEL matriz[tam][tam];

	int i;
	for (i = 0; i < tam; i++){
		vetor[i] = 0;
	}

    //Gera números mais diversificados
    //http://stackoverflow.com/a/17799756
	srand(time(0) * getpid());

	vetor[0] = rand()%300+70;
    vetor[tam-1] = rand()%300+70;


	deslocamentoPonto(0, tam-1, tam, desloc, vetor);
	gerarMatriz(tam, matriz, vetor);
	escreverImagem(tam, matriz, nome_do_arquivo);

}