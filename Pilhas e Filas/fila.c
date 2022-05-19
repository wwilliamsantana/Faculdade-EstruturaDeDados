#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define tamanho 5


struct tfila{
	int dados[tamanho];
	int ini;
	int fim;
};


struct tfila fila;
int op;

void menu(){ 
	printf("\n");  
	printf("\n Escolha uma opção : \n\n"); 
	printf("1 - Empilhar um valor \n");
	printf("2 - Desempilhar \n");
	printf("0 - Sair \n");
}


void fila_mostrar(){
	int i;
	for(i = 0; i < tamanho; i++){
		printf("[ %d ] - ", fila.dados[i]);
	};
}

void fila_entrar(){
	if(fila.fim == tamanho){
		printf("Fila está cheia!");
		system("pause");
	}else{
		printf("\nDigite o valor a ser inserido? ");
		scanf("%d", &fila.dados[fila.fim]);
		fila.fim++;
	}
	
}

void fila_sair(){
	if(fila.fim == fila.ini){
		printf("\n A fila está vazia ! - ");
		system("pause");
	}else{
		int i;
		
		for(i = 0; i < tamanho; i++){
			fila.dados[i] = fila.dados[i + 1];
		};
		
		fila.dados[fila.fim] = 0;
		fila.fim--;
	}
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	fila.ini = 0;
	fila.fim = 0;
	op = 1;
	
	while(op != 0){
		system("cls");
		fila_mostrar();
		menu();
		printf("\n");
		scanf("%d", &op);
		
		switch(op){
			case 0:
			break;
			
			case 1: 
				fila_entrar();
			break;
			
			case 2:
				fila_sair();
			break;
			
			default:
				printf("Digite um valor válido!  - ");
				system("pause");
			break;
			
		}
	
	}
	return 0;
}
