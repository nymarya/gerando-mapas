#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include "../headers/registro.h"


/** Função para desenhar imagem na matriz. **/
int gerarMatriz(int tam, PIXEL matriz[tam][tam], int vetor[tam]);

/** Função para gravar imagem em formato ppm na pasta galeria. **/
int escreverImagem(int tam, PIXEL matriz[tam][tam], char nome_do_arquivo[30]);

/** Função que define os valores do pixel. **/
void configuraPixel(PIXEL *pixel, int r, int g, int b);


#endif
