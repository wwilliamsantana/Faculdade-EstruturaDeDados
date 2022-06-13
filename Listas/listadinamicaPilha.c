// Exemplo livro, pag 82-83 -- Estrutura de dados I
// O que difere de uma lista dinâmica para um lista dinâmica em formato de pilha, é as regras de entrada e saída.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct no {         //Criação da estrutura da lista
	int dado;
	struct no *proximo;
};

typedef no *ptr_no;       // Definindo as variáveis
ptr_no pilha;
int op;

//Prototipação das funções

void menu_mostrar();
void menu_selecionar(int op);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);

//Implementação


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	srand(time(NULL));   //Inicialização dos números randômicos
	op = 1;
	
	pilha = (ptr_no) malloc(sizeof (no));     //Criação da nossa lista em formato de pilha - (Alocando espaço na memória)
	pilha->dado = 10;               //Adicionado um valor a ele
	pilha->proximo = NULL;          //Informando que o proximo elemento é NULL
	
	while(op != 0){           // Loop para nosso Menu
		
		system("cls");        //Limpar a tela
		menu_mostrar();         //Chamar a função de monstrar menu
		scanf(" %d", &op);        //Vamos pegar o elemento que o usúario digitou
		menu_selecionar(op);      // Aqui vai entrar na função de seleção onde temos um switch (Estrutura condicional)
	}
	
	system("Pause");            // Função para Pausar por alguns segundos
	return 0;
	
	
}

//Funções

void menu_mostrar(){
	pilha_mostrar(pilha);         //Chamando a função que vai imprimir na tela todos os No's existentes
  
  //Menu para escolha 
  
	printf("\n\n Escolha uma das opções:\n");       
	printf(" 1- Inserir no final da pilha\n");
	printf(" 2- Remover um item da pilha\n");
	printf(" 0 - Sair\n\n");
}



void menu_selecionar(int op){

  //Estrutura condicional para realizar a opção que foi digitada pelo usúario 
  
  switch(op){
		case 1: 
			pilha_inserir(pilha);     //Chamada da função de inserir um NO - Onde passamos como parâmetro o NO inicial
		break;
		
		case 2: 
			pilha_remover(pilha);       //Chamada da função para remover um NO - Passamos o parâmetro do NO inicial
		break;
	}
}


void pilha_inserir(ptr_no pilha){     //Parâmetro tipo é o NO qeu vai receber
	
	while(pilha->proximo != NULL){    //Loop para encontramos o último NO
		pilha = pilha->proximo;           //Condição para o LOOP funcionar - Vai funcionar até que último elemento da lista seja encontrado "proximo-> NULL"
  
	}

	pilha->proximo = (ptr_no)malloc(sizeof(no));   //Criamos um novo espaço na mémoria para este NO 
	pilha = pilha->proximo;     //Atribuimos o novo NO a variável "pilha"
	pilha->dado = rand()%100;   //Usamos o método randômico para adicionar um número na pilha->dado
	pilha->proximo = NULL;      //Dizemos que o proximo endereço armazenado no NO atual é NULL 

}


void pilha_remover(ptr_no pilha){     //Passamos o tipo de dados que nossa função irá receber
	  
	ptr_no atual;   // Criamos um ponteiro para ser um auxiliar da nossa aplicação 
	
	atual = (ptr_no)malloc(sizeof(no));   //Atribuimos espaço para ele na memória
	
	while(pilha->proximo != NULL){  // Loop para ir até o ultimo elemento
		atual = pilha;            //Vai armazenar o penúltimo NO 
		pilha = pilha->proximo;    //Condição para funcionar nosso LOOP - Vai atribuindo o "proximo" NO até que seja NULL
	}
	
	atual->proximo = NULL;      //Como temos o penúltimo NO vamos eliminar o proximo NO
                              // Seguindo a condição de pilha LIFO (Last in, first out) = Último a entrar é o primeiro a sair!
}


void pilha_mostrar(ptr_no pilha){   //Passamos o tipo de dados que irá receber como parâmetro
	
	while(pilha->proximo != NULL){    //Loop para impressão dos nossos NO's na tela
		
		printf(" %d - ", pilha->dado);    //Impressão
		pilha = pilha->proximo;           // Condição para funcionar nosso LOOP 
	}
	
	printf(" %d - ", pilha->dado);    //Loop irá parar quando chegar no último elemento, só que ele não irá imprimir o dado do último elemento, pois isso a necessidade de colocar essa impressão a mais
	            
}
