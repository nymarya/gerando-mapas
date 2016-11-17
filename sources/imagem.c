#include <stdio.h>
#include "../headers/registro.h"

//Gera linha de contorno
int alteraMatriz(int tamanho, int vetor[tamanho], Pixel matriz[tamanho][tamanho]){
    
    int i, j, indice;
    
    for(i = 0; i< tamanho; i++){
        for(j = 0; j < tamanho; j++){
            indice = tamanho -1 -vetor[j];
            
            if(i == indice){
                matriz[indice][j].r = 255;
                matriz[indice][j].g = 255;
                matriz[indice][j].b = 255;
            }
            
            if(i < indice){
                matriz[i][j].r = 250;
                matriz[i][j].g = 250;
                matriz[i][j].b = 250;
            }
            
        
        }
    }
    
    return 0;
}

//Gerar imagem no formato PPM
void geraImagem(int tamanho, Pixel matriz[tamanho][tamanho]){
	int i, j;
	
	tamanho = tamanho-1;
	printf("P3\n");
	printf("%i %i\n", tamanho, tamanho);
	printf("255\n");
	for(i=0; i<tamanho; i++){
		for(j=0; j<tamanho; j++){
			printf("%i ", matriz[i][j].r);
			printf("%i ", matriz[i][j].g);
			printf("%i\n", matriz[i][j].b);
			
		}
	}
}
