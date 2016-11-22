#include <stdio.h>
#include <stdlib.h>
#include "../headers/registro.h"
#include <math.h>


int deslocamentoPonto(int index, int auxiliar, int tamanho, int fator, int vetor[tamanho])
{

        if(auxiliar != index +1){

            int fator_deslocamento = 2 * (rand()%fator) - fator;   
            if(fator > 1){
                fator /= 2;
            } else{
                fator_deslocamento = 0;
            }
        
            vetor[(index+auxiliar)/2] =
                    (vetor[index] + vetor[auxiliar])/2;
            vetor[(index+auxiliar)/2] += fator_deslocamento;
            
    
            deslocamentoPonto(index, (index+auxiliar)/2, tamanho, fator, vetor);
            deslocamentoPonto( (index+auxiliar)/2, auxiliar, tamanho, fator, vetor);
            
          
            
        }
        
}