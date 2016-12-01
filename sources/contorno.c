#include <stdio.h>
#include <stdlib.h>
#include "../headers/registro.h"
#include "../headers/contorno.h"


/**
 * Função que gera linha de contorno no arranjo.
 * @param extremo1   Primeiro índice que é usado para calcular ponto médio.
 * @param extremo2   Segundo índice que é usado para calcular ponto médio.
 * @param tamanho    Dimensão do arranjo.
 * @param fator      Fator do qual é gerado o fator deslocamento.
 * @param vetor      Arranjo que forma a linha de contorno.
 */

int deslocamentoPonto(int extremo1, int extremo2, int tamanho, int fator, int vetor[tamanho])
{

        if(extremo2 != extremo1 +1){

            int fator_deslocamento = 2 * (rand()%fator) - fator;   
            if(fator > 1){
                fator /= 2;
            } else{
                fator_deslocamento = 0;
            }
        
            vetor[(extremo1+extremo2)/2] =
                    (vetor[extremo1] + vetor[extremo2])/2;
            vetor[(extremo1+extremo2)/2] += fator_deslocamento;
            
    
            deslocamentoPonto(extremo1, (extremo1+extremo2)/2, tamanho, fator, vetor);
            deslocamentoPonto( (extremo1+extremo2)/2, extremo2, tamanho, fator, vetor);
            
          
            
        }
        
}