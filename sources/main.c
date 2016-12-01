#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../headers/registro.h"
#include "../headers/contorno.h"
#include "../headers/imagem.h"
#include "../headers/adicionais.h"



int main(int n, char **str)
{
    
    char nome_do_arquivo[30];
    int desloc;
    /**
     * Valores padrão do fator deslocamento, nome do arquivo e modo da imagem
     */
    desloc = 128; 
    strcpy(nome_do_arquivo, "terreno.ppm");
    Modo modo = AMANHECER;

    if(n>1){
        if(strcmp(str[1], "-o") == 0 && str[2][0] != '-'){
		  strcpy(nome_do_arquivo, str[2]); //Se o primeiro parâmetro for "-o", copia o nome
			  
		if(n>3){
	        if(strcmp(str[3], "-d") == 0 && str[4][0] != '-' ){
			    desloc = atoi(str[4]);//Se o segundo parâmetor for "-d", altera o fator deslocamento
			} else if(strcmp(str[3], "-m") == 0 && str[4][0] != '-'){
				modo = atoi(str[4]);//Se o segundo parâmetro for "-m", recebe o modo
			} else{
			    printf("Comando inválido! Por favor, tente novamente\n");
			    return 0;
			}
					 
			if(n>5){
				if(strcmp(str[5], "-m") == 0 && str[6][0] != '-' ){
			        modo = atoi(str[6]);//Se o terceiro parâmetro for "-m", recebe o modo
				} else if(strcmp(str[5], "-d") == 0 && str[6][0] != '-'){
				    desloc = atoi(str[6]);//Se o terceiro parâmetro for "-d", altera o fator deslocamento
				} else{
				    printf("Comando inválido! Por favor, tente novamente\n");
				    return 0;
				}
			}
		}

      } else if(strcmp(str[1], "-d") == 0 && str[2][0] != '-'){
		 desloc = atoi(str[2]);//Se o primeiro parâmetro for "-d", altera o fator deslocamento
			    
		 if(n>3){
			if(strcmp(str[3], "-o") == 0 && str[4][0] != '-'){
				strcpy(nome_do_arquivo, str[4]);//Se o segundo parâmetro for "-o", copia o nome
			} else if(strcmp(str[3], "-m") == 0 && str[4][0] != '-'){
			    modo = atoi(str[4]);//Se o segundo parâmetro for "-m", recebe o modo
			} else{
				printf("Comando inválido! Por favor, tente novamente\n");
				return 0;
			}
					  
			if(n>5){
				if(strcmp(str[5], "-m") == 0 && str[6][0] != '-'){
			        modo = atoi(str[6]);//Se o terceiro parâmetro for "-m", recebe o modo
				} else if(strcmp(str[5], "-o") == 0 && str[6][0] != '-'){
					strcpy(nome_do_arquivo, str[6]);//Se o terceiro parâmetro for "-o", copia o nome
				} else{
					printf("Comando inválido! Por favor, tente novamente\n");
				    return 0;
				}  
			}
		}

      } else if(strcmp(str[1], "-m") == 0 && str[2][0] != '-'){
		modo = atoi(str[2]);//Se o primeiro parâmetro for "-d", altera o fator deslocamento
			    
		if(n>3){
			if(strcmp(str[3], "-d") == 0 && str[4][0] != '-'){
		        desloc = atoi(str[4]);//Se o segundo parâmetro for "-d", altera o fator
			} else if(strcmp(str[3], "-o") == 0 && str[4][0] != '-'){
			    strcpy(nome_do_arquivo, str[4]);//Se o segundo parâmetro for "-o", copia o nome
			} else{
				printf("Comando inválido! Por favor, tente novamente\n");
				return 0;
			}
					  
		    if(n>5){
				if(strcmp(str[5], "-o") == 0 && str[6][0] != '-'){
				    strcpy(nome_do_arquivo, str[6]);//Se o terceiro parâmetro for "-o", copia o nome
				} else if(strcmp(str[5], "-d") == 0 && str[6][0] != '-'){
					desloc = atoi(str[6]);//Se o terceiro parâmetro for "-d", altera o fator
				} else{
					printf("Comando inválido! Por favor, tente novamente\n");
					return 0;
				}
			}
		}
      } else{
	    printf("Comando inválido! Por favor, tente novamente\n");
		return 0;
	  }
	
	}
	
    if(modo > 3){
        modo = 3;
    } else if(modo < 0){
        modo = 0;
    }    

    int tam = 513; //2^9+1

	
    int vetor[tam]; 
    PIXEL matriz[tam][tam];

    int i;
    for (i = 0; i < tam; i++){
	vetor[i] = 0;
    }

    /**
     * Gera números mais diversificados.
     * http://stackoverflow.com/a/17799756
     */
    srand(time(0) * getpid());

    vetor[0] = rand()%200+70;
    vetor[tam-1] = rand()%200+70;
    

    deslocamentoPonto(0, tam-1, tam, desloc, vetor);
    gerarGradiente(tam, matriz, modo);
    gerarMatriz(tam, matriz, vetor);
    escreverImagem(tam, matriz, nome_do_arquivo);

    return 0;
}