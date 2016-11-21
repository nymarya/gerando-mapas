#include <stdio.h>
#include "../headers/contorno.h"

int deslocamentoDireita(int tam, float desloc, int iInicial, int iFinal, int vetor[tam]){

	if(iFinal-1 == iInicial){
		return 0;
	} else {

		int indice = (iFinal + iInicial)/2; //CALCULANDO A METADE ENTRE OS INDICES
		int valor = (vetor[iInicial]+vetor[iFinal])/2; //CALCULANDO MÉDIA ENTRE OS VALORES DOS DOIS EXTREMOS

		desloc /= 2.0; //CALCULANDO O DESLOCAMENTO

		valor = valor + desloc; //CALCULANDO O NOVO VALOR PARA A METADE ENTRE OS INDICES

		vetor[indice] = valor;

		deslocamentoEsquerda(tam, desloc, indice, iFinal, vetor); 
		deslocamentoDireita(tam, desloc, iInicial, indice, vetor);

		return 0;
	}

}

int deslocamentoEsquerda(int tam, float desloc, int iInicial, int iFinal, int vetor[tam]){

	if(iFinal-1 == iInicial){
		return 0;
	} else {
		int indice = (iFinal + iInicial)/2; //CALCULANDO A METADE ENTRE OS INDICES
		int valor = (vetor[iInicial]+vetor[iFinal])/2; //CALCULANDO MÉDIA ENTRE OS VALORES DOS DOIS EXTREMOS

		desloc /= 2.0; //CALCULANDO O DESLOCAMENTO

		valor = valor + (valor*desloc); //CALCULANDO O NOVO VALOR PARA A METADE ENTRE OS INDICES
		
		vetor[indice] = valor;

		deslocamentoDireita(tam, desloc, iInicial, indice, vetor);
		deslocamentoEsquerda(tam, desloc, indice, iFinal, vetor); 

		return 0;
	}
}