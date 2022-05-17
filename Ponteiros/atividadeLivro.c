// Atividade do livro, pag 34 -Estrutura de dados I


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int tam;  //Variável para armazenar o tamanho do nosso vetor.
	int *vetor;  //Iniciando nooso ponteiro que vai apontar para nossos endereços que será em forma de vetor.
	
	printf("Escolha o tamanho do vetor? ");
	scanf("%d", &tam); //Atribuimos o valor do tamanho, solicitando para o usuário.
	
	vetor = (int *)malloc(sizeof (int) * tam);  // Aqui alocamos de forma dinâmica. É multiplicamos pelo valor que foi solicitado pelo usuário.						
	printf("\n"); 				    // Essa multiplicação resultará no tamanho que será nosso vetor.
	
	for(int i = 0; i < tam; i++){	//Este laço de repetição vai adicionar a cada posição do nosso vetor uma potênciação de 2. De acorod com o valor que foi inserido pelo usuário.
	   	vetor[i] = pow(2, i);	
		printf("Posição %d: %d \n", i, vetor[i]);
	};
	return 0;
}
