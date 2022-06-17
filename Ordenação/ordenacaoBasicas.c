#include <stdio.h>
//Estudos do livro Estrutura de Dados II - pag 67 a 84

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constante
#define tamanho 10    

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt = 1;
int qtd;

//Prototipação - Funções para gerar o vetor da nossa lista.
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

//Prototipação - Funções de Ordenação

int bubbleSort(int vec[]);
int selectionsort(int vec[], int tam);
int insertionsort(int vec[], int tam);
int shellsort(int vec[], int tam);
void troca(int *a, int *b);

//Início da implementação

int main(){
	srand(time(NULL));	//Inicialização da funções dos números randômicos
	
	//Loop para nosso menu principal
	do{		
		system("cls");	//Limpar tela
		lista_mostrar();	//Imprimir nossa lista
		lista_mostrar_ordenado();	//Imprimir lista ordenada
		menu_mostrar();			//Mostrar o menu
		scanf("%d", &opt);		//Salvar o valor inserido pelo usuário
		
		switch(opt){	//Estrutura condicional para seleção de um elemento de acordo com o valor inseriod pelo usuário
			
			case 1: 		//Gerar lista aleatória
				lista_gerar();
				lista_limpar();	   //Copiar os valores para nosso vetor "ordenados"
			break;
			
			case 2:			//Adicionar de forma manual os valores da lista
				lista_ler();	
				lista_limpar();	  //Copiar os valores para nosso vetor "ordenados"
			break;
			
			case 3:
				qtd = bubbleSort(ordenado);	// Chamada da função de ordenação, passando como parâmetro o vetor a ser ordenado
				lista_mostrar_ordenado();	//Impressão do nosso vetor ordenado
			break;	
			
			case 4: 
				qtd = selectionsort(ordenado, tamanho);	//Chamada da função de ordenação, passando como parâmetro o vetor é o tamanho do vetor
				lista_mostrar_ordenado();	//Impressão do nosso vetor ordenado
			break;
			
			case 5: 
				qtd = insertionsort(ordenado, tamanho);	//Chamada da função de ordenação, passando como parâmetro o vetor é o tamanho do vetor
				lista_mostrar_ordenado();	//Impressão do nosso vetor ordenado
			break;
			
			case 6: 
				qtd = shellsort(ordenado, tamanho);	//Chamada da função de ordenação, passando como parâmetro o vetor é o tamanho do vetor
				lista_mostrar_ordenado();	//Impressão do nosso vetor ordenado
			break;
		}
	}while(opt != 0);
	
	system("Pause");
	
	return 0;
	
}

//Menu 

void menu_mostrar(void){
	printf("1 - Gerar lista aleatoria\n");
	printf("2 - Fazer a lista manualmente\n");
	printf("3 - Ordenacao Bubblesort\n");
	printf("4 - Ordenacao Selectionsort\n");
	printf("5 - Ordenacao Insertionsort\n");
	printf("6 - Ordenacao Shellsort\n");
	printf("0 - Sair\n\n");
}

//Impressão da nossa lista

void lista_mostrar(void){
	int i;
	
	printf("[  ");
	for(i=0; i < tamanho; i++){
		printf("%d - ", lista[i]);
	}
	printf("  ] \n\n");
}

//Adicionando valores aleatórios no nosso vetor

void lista_gerar(void){
	int i;
	for(i=0; i < tamanho; i++){
		lista[i] = rand()%50;
	}
}

//Adicionando valores manualmente no nosso vetor

void lista_ler(void){
	int i;
	
	for(i=0; i < tamanho; i++){
		system("cls");
		lista_mostrar();
		printf("Informe um valor para ser inserido:  ");
		scanf("%d", &lista[i]);
	}
}

//Copiando os valores do nosso vetor principal (lista) para nosso vetor (ordenado)

void lista_limpar(void){
	int i;
	
	for(i=0; i < tamanho; i++){
		ordenado[i] = lista[i];
	}
	
}

//Impressão do nosso vetor ordenado, com o valor da iterações (que serão retornadas pelas funções)

void lista_mostrar_ordenado(){
	int i;
	printf("[  ");
	for(i=0; i < tamanho; i++){
		printf("%d - ", ordenado[i]);
	}
	printf("  ] Tempo = %d iteracoes\n\n", qtd);
	
}

//Função para trocar os valores de posições  (utilizando ponteiros(Endereços))

void troca(int *a, int *b){	//Recebendo como parâmetro 2 ponteiros.
	int aux;	//Variável auxiliar
	aux = *a;	//Variável auxiliar recebe o primeiro endereço A
	*a = *b;	// A vai receber o endereço de B
	*b = aux;	//B vai receber o endereço de A
}

//Função de ordenação BUBBLESORT

int bubbleSort(int vec[]){	//Recebe como parâmetro o vetor a ser ordenado
	int qtd, i, j, tmp;	//Variáveis que irão ajudar na nossa função
	qtd = 0;
	
	//Teremos 2 laços de repetição alinhados
	
	for(i=0; i < tamanho - 1; i++){		
		for(j= i+1; j < tamanho; j++){
			if(vec[i] > vec[j]){	//Vamos ter uma comparação - Se o valor 1 for maior que o valor 2, efetua a troca.
				troca(&vec[i], &vec[j]);    //Sendo que o 1 elemento vai ser fixo(cada loop ele muda) é o 2 elemento vai percorrer todos os valores do vetor, efetuando a comparação 
			}				    //Ele sempre jogará o maior valor para final do vetor
			qtd++;	//Verificar quantidade de iterações
		}
	}
	
	return qtd;
}

//Função de ordenação SELECTIONSORT

int selectionsort(int vec[], int tam){	//Recebe dois parâmetros, vetor é o tamanho do vetor
	int i, j, min, qtd;	//Variáveis auxiliares
	qtd = 0;	
	
	//Teremos 2 laços de repetições alinhados
	for(i=0; i < tam - 1 ; i++){
		min = i;	// Ele vai guardar o valor de i em min (supondo que ele seja o menor valor)
		for(j = i+1; j < tam; j++){	
			if(vec[j] < vec[min]){	//Vai haver um comparação com todos os valores da array, caso um valor seja menor do que estava armazenado em "min"
				min = j;	// Será atribuido para variável min..
			}
			qtd++;
		}
		
		if(i != min){	//Será feito uma verificação se i é diferente de min
			troca(&vec[i], &vec[min]);	//Aqui será efetuado a troca do valor atual, por o menor valor encontrado, que estava armazenado na variável "min"
		}
	}
	
	//Em seguida pássara para a posição 2 - Que vai verificar todos os elementos até encontrar o menor valor.
	
	return qtd;
	
}

//Função de ordenação INSERTIONSORT

int insertionsort(int vec[], int tam){	//Recebe dois parâmetros, vetor é o tamanho do vetor
	int i, j, qtd;	//Variáveis auxiliares
	qtd = 0;
	
	//Teremos 2 laços de repetições alinhados
	
	for(i=1; i < tam; i++){
		j = i;		//Vamos passar o índice para variável j 
		while((vec[j] < vec[j -1]) && (j!=0)){	//Faremos uma comparação com o índice atual é o anterior índice - Se o índice atual for menor que o anterior, efetuamos a troca de posição é se j for diferente de zero
			troca(&vec[j], &vec[j - 1]);	//Efetuamso a troca, quando a condição for verdadeira
			j--;	//Decrementamos o j a cada loop, para que ele possa verificar se os valores anteriores são menores que o índice decrementado no vetor, se for menor realizará a troca, se não for, não entrara no loop
			qtd++;	//Se caso o j for igual a 0, nossa condição tbm é quebrada.
		}
	}
	
	return qtd;
}

//Função de ordenação SHELLSORT

int shellsort(int vec[], int tam){	//Recebe dois parâmetros, vetor é o tamanho do vetor
	int i, j, valor, qtd;	//Variáveis auxiliares
	qtd = 0;
	
	int gap = 1;	//Variável gap - determina a distância entre os elementos
	
	do{
		gap = 3 * gap + 1;
	}while(gap < tam);		//Calcular a distancia - Loop até que a condição seja quebrada	(gap ser menor que tam)
	
	do{
		gap /= 3;		//Iremos dividir a gap em 3
		
		for(i=gap; i < tam; i++){ //Iremos utilizar o método parecido od InsertionSort só que passando a partir meio(gap) e fim
			valor = vec[i];		//A variável receberá o primeiro valor do gap
			j = i - gap;  		//A Variável j recebrá (i - gap) 
					5 = 50	3 = 90
			while(j >= 0 && valor < vec[j]){	//Loop vai possuir 2 condições, ("j" tem que maior ou igual 0) é ("valor" tem que ser menor que "vetor[j]")
			5 =80	vec[j + gap] = vec[j]; 	//Se caso as condições forem verdadeiras, iremos somar a varíavel (j + gap) que resultará em um índice que vai receber o valor de índice J
				j -= gap;	//Decrementa em cima do gap, ele vai voltando as casas e verificando com os elementos anteriores, até que a condição do loop seja quebrada
				qtd++;
			}
			vec[j + gap] = valor;	//Alteramos o índice do gap
		}
	}while(gap > 1);	//Condição para que loop seja quebrado
	
	return qtd;
	
	
}


