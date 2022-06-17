#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 10    


int lista[tamanho];
int ordenado[tamanho];
int opt = 1;
int qtd;



void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);



int bubbleSort(int vec[]);
int selectionsort(int vec[], int tam);
int insertionsort(int vec[], int tam);
int shellsort(int vec[], int tam);
void troca(int *a, int *b);

int main(){
	srand(time(NULL));
	
	do{
		system("cls");
		lista_mostrar();
		
		lista_mostrar_ordenado();
		menu_mostrar();
		scanf("%d", &opt);
		
		switch(opt){
			
			case 1: 
				lista_gerar();
				lista_limpar();
			break;
			
			case 2:
				lista_ler();
				lista_limpar();
			break;
			
			case 3:
				qtd = bubbleSort(ordenado);
				lista_mostrar_ordenado();
			break;
			
			case 4: 
				qtd = selectionsort(ordenado, tamanho);
				lista_mostrar_ordenado();
			break;
			
			case 5: 
				qtd = insertionsort(ordenado, tamanho);
				lista_mostrar_ordenado();
			break;
			
			case 6: 
				qtd = shellsort(ordenado, tamanho);
				lista_mostrar_ordenado();
			break;
		}
	}while(opt != 0);
	
	system("Pause");
	
	return 0;
	
}


void menu_mostrar(void){
	printf("1 - Gerar lista aleatoria\n");
	printf("2 - Fazer a lista manualmente\n");
	printf("3 - Ordenacao Bubblesort\n");
	printf("4 - Ordenacao Selectionsort\n");
	printf("5 - Ordenacao Insertionsort\n");
	printf("6 - Ordenacao Shellsort\n");
	printf("0 - Sair\n\n");
}

void lista_mostrar(void){
	int i;
	
	printf("[  ");
	for(i=0; i < tamanho; i++){
		printf("%d - ", lista[i]);
	}
	printf("  ] \n\n");
}

void lista_gerar(void){
	int i;
	for(i=0; i < tamanho; i++){
		lista[i] = rand()%50;
	}
}

void lista_ler(void){
	int i;
	
	for(i=0; i < tamanho; i++){
		system("cls");
		lista_mostrar();
		printf("Informe um valor para ser inserido:  ");
		scanf("%d", &lista[i]);
	}
}

void lista_limpar(void){
	int i;
	
	for(i=0; i < tamanho; i++){
		ordenado[i] = lista[i];
	}
	
}

void lista_mostrar_ordenado(){
	int i;
	printf("[  ");
	for(i=0; i < tamanho; i++){
		printf("%d - ", ordenado[i]);
	}
	printf("  ] Tempo = %d iteracoes\n\n", qtd);
	
}


void troca(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;	
}

int bubbleSort(int vec[]){
	int qtd, i, j, tmp;
	qtd = 0;
	
	for(i=0; i < tamanho - 1; i++){
		
		for(j= i+1; j < tamanho; j++){
			if(vec[i] > vec[j]){
				troca(&vec[i], &vec[j]);
			}
			qtd++;
		}
	}
	
	return qtd;
}

int selectionsort(int vec[], int tam){
	int i, j, min, qtd;
	qtd = 0;
	
	for(i=0; i < tam - 1 ; i++){
		min = i;
		for(j = i+1; j < tam; j++){
			if(vec[j] < vec[min]){
				min = j;
			}
			qtd++;
		}
		
		if(i != min){
			troca(&vec[i], &vec[min]);
		}
	}
	
	return qtd;
	
}


int insertionsort(int vec[], int tam){
	int i, j, qtd;
	qtd = 0;
	
	for(i=1; i < tam; i++){
		j = i;
		while((vec[j] < vec[j -1]) && (j!=0)){
			troca(&vec[j], &vec[j - 1]);
			j--;
			qtd++;
		}
	}
	
	return qtd;
}

int shellsort(int vec[], int tam){
	int i, j, valor, qtd;
	qtd = 0;
	
	int gap = 1;
	
	do{
		gap = 3 * gap + 1;
	}while(gap < tam);
	
	do{
		gap /= 3;
		for(i=gap; i < tam; i++){
			valor = vec[i];
			j = i - gap;
			
			while(j >= 0 && valor < vec[j]){
				vec[j + gap] = vec[j];
				j -= gap;
				qtd++;
			}
			vec[j + gap] = valor;
		}
	}while(gap > 1);
	
	return qtd;
	
	
}


