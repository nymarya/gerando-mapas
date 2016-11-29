#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include "../headers/registro.h"


//FUNÇÃO PARA GERAR MATRIZ DA IMAGEM A PARTIR DO VETOR COM AS ALTITUDES
int gerarMatriz(int tam, PIXEL matriz[tam][tam], int vetor[tam]);

//FUNÇÃO PARA GERAR ARQUIVO DE IMAGEM NO FORMATO PPM
int escreverImagem(int tam, PIXEL matriz[tam][tam], char nome_do_arquivo[30]);

//FUNÇÃO PARA CONFIGURAR UM PIXEL
void configuraPixel(PIXEL *pixel, int r, int g, int b);


#endif
