#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/registro.h"
#include "../headers/ponto_medio.h"
#include "../headers/imagem.h"

int main(int arc, char **argv)
{
    
 
    Pixel matriz[513][513] = {0};
    
    srand(time(0) * getpid());
     
    int fator = 128;
    
    int vetor[513]  = {0};
    vetor[0] = rand()%300+70;
    vetor[512] = rand()%300+70;
    
    while (abs(vetor[512]-vetor[0]) < 150){
        vetor[512] = rand()%300+70;
    }
    deslocamentoPonto(0, 512, 513, fator, vetor);
    alteraMatriz(513, vetor, matriz);
    geraImagem(513, matriz);
 
    return 0;
}