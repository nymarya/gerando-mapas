#include <stdio.h>
#include "../headers/imagem.h"

//GERAR MATRIZ COM OS ELEMENTOS DO VETOR
int gerarMatriz(int tam, PIXEL matriz[tam][tam], int vetor[tam]){
	
	int i, j;
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam; j++) {

			if (i > vetor[j]) {
				matriz[i][j].r = 102;
				matriz[i][j].g = 102;
				matriz[i][j].b = 51;
			} else {
				matriz[i][j].r = 153;
				matriz[i][j].g = 204;
				matriz[i][j].b = 255;
			}
				
		}
	}
	
	return 0;

}


//GERAR IMAGEM NO FORMATO PPM
int escreverImagem(int tam, PIXEL matriz[tam][tam]){
	FILE *arquivo;
	
	arquivo = fopen( "../galeria/terreno.ppm", "w" );
	
	
	fprintf(arquivo, "P3\n");
	fprintf(arquivo, "%i %i\n", tam, tam);
	fprintf(arquivo, "%i\n", 255);

	int i, j;
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			fprintf(arquivo, "%i %i %i", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
			fprintf(arquivo, "\n");
		}
		fprintf(arquivo, "\n");
	}

	fclose(arquivo);
	return 0;
}
