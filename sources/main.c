#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/registro.h"
#include "../headers/contorno.h"
#include "../headers/imagem.h"

int main(int n, char **str)
{
    
    char nome_do_arquivo[30];
    
    if(strcmp(str[1], "-o") == 0){
        strcpy(nome_do_arquivo, str[2]);
    } else{
        strcpy(nome_do_arquivo, "montanha.ppm");
    }

    
    if(n <= 1){
        n==3;
    }
 
    Pixel matriz[513][513] = {0};
    
    srand(time(0) * getpid());
     
    int fator = 256;
    
    int vetor[513]  = {0};
    vetor[0] = rand()%300+70;
    vetor[512] = rand()%300+70;
    
    while (abs(vetor[512]-vetor[0]) < 150){
        vetor[512] = rand()%300+70;
    }
    deslocamentoPonto(0, 512, 513, fator, vetor);
    alteraMatriz(513, vetor, matriz);
    geraImagem(513, matriz, nome_do_arquivo);
 
    return 0;
}