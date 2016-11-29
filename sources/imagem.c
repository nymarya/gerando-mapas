#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../headers/registro.h"
#include "../headers/imagem.h"

//DEFINE CORES DO PIXEL
void configuraPixel(PIXEL *pixel, int r, int g, int b){

	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
}


//GERAR MATRIZ COM OS ELEMENTOS DO VETOR
int gerarMatriz(int tam, PIXEL matriz[tam][tam], int vetor[tam]){
	
	int i, j;
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam; j++) {

			if (i > vetor[j]) {
				configuraPixel(&matriz[i][j], 1, 2, 18);
			} 
				
		}
	}
	
	return 0;

}


//GERAR IMAGEM NO FORMATO PPM
int escreverImagem(int tam, PIXEL matriz[tam][tam], char nome_do_arquivo[30]){
	
	char *endereco = "../galeria/";
	char *caminho = malloc(strlen(endereco)+strlen(nome_do_arquivo)+1);
	strcpy(caminho, endereco);
	strcat(caminho, nome_do_arquivo);
	FILE *arquivo;
	arquivo = fopen(caminho, "w" );
	
	
	fprintf(arquivo, "P3\n");
	fprintf(arquivo, "%i %i\n", tam, tam);
	fprintf(arquivo, "%i\n", 255);

	int i, j;
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			fprintf(arquivo, "%i %i %i", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
			fprintf(arquivo, "\n");
		}
		fprintf(arquivo, "\n");
	}
	
	free(caminho);
	fclose(arquivo);
	return 0;
}
