// Exemplo livro, pag 85-87 -- Estrutura de dados I
// O que difere de uma lista dinâmica para um lista dinâmica em formato de fila, é as regras de entrada e saída.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no{            //Criação da estrutura da fila
	int dado;
	struct no *proximo;
};

typedef no *ptr_no;       //Definindo as variáveis
ptr_no fila;
int op;

//Prototipação

void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);


//Implementação

int main(){
	
	srand(time(NULL));          //Inicialização dos números randômicos
	op = 1;               
	
	fila = (ptr_no)malloc(sizeof(no));        //Alocação de espaço na memória
	fila->dado = 0;                 //Adicionando valor da nosso NO
	fila->proximo = NULL;           //Informando que o proximo NO é NULL
	
	while(op != 0){     //Loop para nosso Menu
		system("cls");      //função para limpara tela
		menu_mostrar();      //Chamada para nossa função de mostrar o menu
		scanf("%d", &op);      //Pegar o valor inserido pelo usúario
		menu_selecionar(op);   // Aqui vai entrar na função de seleção onde temos um switch (Estrutura condicional)
	}
	
	system("Pause");    //Funçãp para Pausar nossa aplicação durante alguns segundos

	return 0;	
	
}

//Funções

void menu_mostrar(){    
	fila_mostrar(fila);   //Vai chamar a função que vai imprimir na tela todos os NO's existentes.
	
  //Menu para escolha das opções
  
	printf("\n\n Escolha uma das opcoes: \n");
	printf("1 - Inserir no final da fila\n");
	printf("2 - Remover no inicio da fila\n");
	printf("0 - Sair\n\n");
	
	
}


void menu_selecionar(int op){   //Função para chamar a função escolhida pelo usúario
	switch(op){
		case 1:
			fila_inserir(fila);   //chamada da função para inserir - Parâmetro -> fila (NO inicial)
		break;
		
		case 2: 
			fila_remover(fila);  //chamada da função para remover - Parâmetro -> fila (NO inicial)
		break;
	}
	
}


void fila_inserir(ptr_no fila){   //Função para inserir um elemento
	
	while(fila->proximo != NULL){   //Loop para pegar o último elemento (NO)    
		fila = fila->proximo;         // Condição para o LOOP Funcionar
	}
	
	fila->proximo = (ptr_no)malloc(sizeof(no));   //Criamos um novo espaço na memória
	fila = fila->proximo;         //Atribuimos o novo NO para a váriavel "fila"
	fila->dado = rand()%100;      //Usamos o método randômico para adicionar um valor ao nosso NO
	fila->proximo = NULL;         //Dizemos que proximo edereço de mémoria será NULL
	
}


void fila_remover(ptr_no fila){   //Função para remover um elemento da nossa fila
	ptr_no atual; //Criamos um ponteiro para nós auxiliar na aplicação
	atual = (ptr_no)malloc(sizeof(no));   //atribuimos um espaço na mémoria para ele
	atual = fila;           //Aqui vamos atribuir o mesmo NO inicial para o NO auxiliar
	
	if(fila->proximo != NULL){  //Verificação para saber se nossa fila possui mais de um NO
		fila = fila->proximo;  // Vamos atribuir o endereço do próximo NO para a variavel fila
		atual->proximo = fila->proximo; // Aqui vamos atribuir o "proximo" endereço da varíavel "atual" - linkando - com o "proximo" endereço da varíavel "fila"
                        //Seguindo as condições da fila FIFO (First in, first out) - Primeira a entra é o primeiro a sair.
	}
}

void fila_mostrar(ptr_no fila){ //Função para impressão dos NO's existentes
	
	while(fila->proximo != NULL){   //Loop até o último NO - até que o proximo seja NULL
		printf("%d - ", fila->dado);   //Impressão do NO atual
		fila = fila->proximo;   //condição para LOOP funcionar
	}
	
	printf("%d - ", fila->dado);  //Loop irá parar quando chegar no último elemento, só que ele não irá imprimir o dado do último elemento, pois isso a necessidade de colocar essa impressão a mais
	            
}

	
}


