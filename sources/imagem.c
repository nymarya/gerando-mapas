#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../headers/registro.h"
#include "../headers/imagem.h"

/**
 * Função que define os valores do pixel.
 * @param pixel  Referência ao pixel que será alterado
 * @param r      Valor do vermelho
 * @param g      Valor do verde
 * @param b      Valor do azul
 */
void configuraPixel(PIXEL *pixel, int r, int g, int b){
	
     pixel->r = r;
     pixel->g = g;
     pixel->b = b;
}

/**
 * Função para desenhar imagem na matriz.
 * @param tam      Dimensão da matriz (quadrada) e do vetor
 * @param matriz   Matriz que será alterada
 * @param vetor    Vetor que servirá como linha de contorno
 */
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


/**
 * Função para gravar imagem em formato ppm na pasta galeria.
 * @param tam               Dimensão da matriz (quadrada)
 * @param matriz            Matriz da qual é gerada a imagem
 * @param nome_do_arquivo   Nome do arquivo (padrão ou passado como parâmetro na linha de comando)
 */
int escreverImagem(int tam, PIXEL matriz[tam][tam], char nome_do_arquivo[30]){
	
    char *endereco = "../galeria/"; //endereço padrão
    char *caminho = malloc(strlen(endereco)+strlen(nome_do_arquivo)+1);
    strcpy(caminho, endereco); //copia endereço para variável
    strcat(caminho, nome_do_arquivo); //concatena endereço e nome do arquivo
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
