// Atividade do livro, pag 34 -Estrutura de dados I

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int tam;
	int *vetor;
	
	printf("Escolha o tamanho do vetor? ");
	scanf("%d", &tam);
	vetor = (int *)malloc(sizeof (int) * tam);
	printf("\n");
	for(int i = 0; i < tam; i++){
		vetor[i] = pow(2, i);	
		printf("Posição %d: %d \n", i, vetor[i]);
	};
	
	
	return 0;
}
