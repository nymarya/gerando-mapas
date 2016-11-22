#ifndef IMAGEM_H
#define IMAGEM_H

//DECLARAÇÃO DE STRUCT RGB
typedef struct RegPixel{
	int r;
	int g;
	int b;
} PIXEL;


//FUNÇÃO PARA GERAR MATRIZ DA IMAGEM A PARTIR DO VETOR COM AS ALTITUDES
int gerarMatriz(int tam, PIXEL matriz[tam][tam], int vetor[tam]);

//FUNÇÃO PARA GERAR ARQUIVO DE IMAGEM NO FORMATO PPM
int escreverImagem(int tam, PIXEL matriz[tam][tam], char nome_do_arquivo[30]);


#endif