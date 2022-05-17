// Atividade do livro, pag 37 - Questão 5
//Objetivo: Criar um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho lido e o outro com dobro desse tamanho.


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int tam;
	int *ptr_1; //ponteiros
	int *ptr_2;
	
	printf("Qual tamanho do vetor? ");
	scanf("%d", &tam);        //Aqui pedidos ao usuário pra determinra o tamanho dos vetores (ponteiros) e atribuimos a variável tam.
	
	int tam2 = 2 * tam;        // Criamos outra variável para facilitar. Duplicamos o valor digitado pelo usúario.

	ptr_1 = (int *)malloc(sizeof (int) * tam);            //Alocando nosso ponteiro de forma dinâmica..
	ptr_2 = (int *)malloc(sizeof (int) * tam2);

	printf("--------------------------------\nPotências de 2 \n\n");  // Fica mais bunitinn nosso código hauauhaua
	

	for(int i =0; i < tam; i++){             //Laço de repetição que vai atribuir a potência de 2 ao nosso vetor, de acordo com o tamanho que foi estabelecido.
		ptr_1[i] = pow(2, i);                 // Pegando 1° índice do nosso vetor e utilizando a Função pow vem da biblioteca "Math.h" que calcula potências.
		
		printf("Posição %d : %d \n", i + 1, ptr_1[i]);
		
	};
	
	printf("--------------------------------\nPotências de 3 \n\n");
	
	for(int i = 0; i < tam2; i++){     //Aqui tudo se repete, diferença é que usamos o valor do vetor duplicado é utilizamos o valor 3 para calcular a potência.
		ptr_2[i] = pow(3, i);
		
		printf("Posição %d : %d \n", i + 1, ptr_2[i]);
		
	};

	
	return 0;
}
