//Atividade livro, pag 36 - Questão 2 
// Objetivo: Um semáforo tem 3 objetos, cada um contém um atributo cor e outro id. devido a limitações de memória e processamos, deseja que crie 
// um ponteiro que vai percorrer a memória e imprimir os dados na tela. 

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


	struct semaforo {
		char cor[10];           //Criação da estrutura princiapl
		int id;
	};
	
	struct semaforo s1 = { "Vermelho", 1};
	struct semaforo s2 = { "Amarelo", 2};           //Estamos criando variáveis do tipo da estrutura
	struct semaforo s3 = { "Verde", 3};
	struct semaforo *ptr;                           // Incluindo um ponteiro do tipo da estrutura

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	ptr = &s1;    //Iniciando o ponteiro apontando para a 1° variavel (s1)
  
	printf("%p  - %s \n", (*ptr).id, (*ptr).cor);   //Estamos imprimindo o conteúdo para a variavel que o ponteiro aponta.
  
	ptr = ptr + 1; //Aqui conseguimos usar operações aritméticas para apontar para o proximo endereço.(de forma indireta estamos Atribuindo o ponteiro a variáve (s2))
                       
  
	printf("%p  - %s \n", (*ptr).id, (*ptr).cor); //Aqui se repete a impressão
	ptr = ptr + 1;  //Indicamos o próximo elemento
	printf("%p  - %s", (*ptr).id, (*ptr).cor);  //Se repete


}
