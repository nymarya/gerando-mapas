#ifndef CONTORNO_H
#define CONTORNO_H


//FUNÇÕES PARA CALCULAR O DESLOCAMENTO. INTERCALA AS DUAS FUNÇÕES PARA PERCORRER O VETOR E ALTERAR 
//OS ELEMENTOS TANTO DA ESQUERDA PARA DIREITA, ASSIM COMO DA DIREITA PARA ESQUERDA
int deslocamentoEsquerda(int tam, float desloc, int iInicial, int iFinal, int vetor[tam]);
int deslocamentoDireita(int tam, float desloc, int iInicial, int iFinal, int vetor[tam]);


#endif