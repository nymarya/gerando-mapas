#include <stdio.h>
#include "../headers/registro.h"

//Gera linha de contorno
int alteraMatriz(int tamanho, int vetor[tamanho], Pixel matriz[tamanho][tamanho]){
    
    int i, j, indice;
    
    for(i = 0; i< tamanho; i++){
        for(j = 0; j < tamanho; j++){
            indice = tamanho -1 -vetor[j];
            
            
            if(i <= indice){
                matriz[i][j].r = 250;
                matriz[i][j].g = 250;
                matriz[i][j].b = 250;
            }
            
        
        }
    }
    
    return 0;
}

//Gerar imagem no formato PPM
void geraImagem(int tamanho, Pixel matriz[tamanho][tamanho], char nome_do_arquivo[30]){
    
	int i, j;
	
	char *endereco = "../galeria/";
	char *caminho = malloc(strlen(endereco)+strlen(nome_do_arquivo)+1);
	strcpy(caminho, endereco);
	strcat(caminho, nome_do_arquivo);
	
	FILE *arquivo;
	arquivo = fopen(caminho, "w" );
	
	tamanho = tamanho-1;
	fprintf(arquivo, "P3\n");
	fprintf(arquivo, "%i %i\n", tamanho, tamanho);
	fprintf(arquivo, "%i\n", 255);
	for(i=0; i<tamanho; i++){
		for(j=0; j<tamanho; j++){
			fprintf(arquivo, "%i ", matriz[i][j].r);
			fprintf(arquivo, "%i ", matriz[i][j].g);
			fprintf(arquivo, "%i\n", matriz[i][j].b);
			
		}
	}
	
	free(caminho);
	fclose(arquivo);
}
