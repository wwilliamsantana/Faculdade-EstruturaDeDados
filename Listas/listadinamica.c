// Exemplo livro, pag 77-80 -- Estrutura de dados I


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct no {                         //Criação da estrutura da lista
	int dado;
	struct no *proximo;
};

typedef no *ptr_no;   // Definindo as variáveis
ptr_no lista;
int op;


//Prototipação das funções

void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);


//Implementanção

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	srand(time(NULL));    //Inicialização dos números randômicos
	op = 1;
	
	lista = (ptr_no) malloc(sizeof (no));   //Criando nossa lista (NO - ponteiro)
	lista->dado = 10;       //Atribuindo um valor inicial para nosso NO
	lista->proximo = NULL;    // Informando que o prox é NULL
	
	while(op != 0){       //Loop para nosso menu
		
		system("cls");        //Limpar a tela
		menu_mostrar();        //Função de monstrar o menu
		scanf(" %d", &op);    //Pegar o elemento que foi selecionado na função anterior
		menu_selecionar(op);  // Aqui entra em uma função que possui um switch (estrutura de condicional)
	}
	
	system("Pause");    //Função para Pausar a aplicação por alguns segundos
	return 0;
	
	
}

//Funções

void menu_mostrar(){
	lista_mostrar(lista);   // Chamando a função que irá imprimir os dados dos NO's existentes.
  
  //Menu para a escolha do que fazer
  
	printf("\n\n Escolha uma das opções:\n");  
	printf(" 1- Inserir no final da lista\n");
	printf(" 2- Remover um item da lista\n");
	printf(" 0 - Sair\n\n");
}

void menu_selecionar(int op){   //Aqui vai receber como parâmetro o op (elemento extraído do menu)
  
  //Estrutura condicional para realizar a opção que foi selecionado na função monstrar
  
	switch(op){
		case 1: 
			lista_inserir(lista); // Aqui vai chamar a função que irá inserir um NO
		break;
		
		case 2: 
			lista_remover(lista); // Aqui vai chamar a função que irá remover uma função
		break;
	}
}

void lista_inserir(ptr_no lista){ //Aqui vai receber o NO inicial
	
	while(lista->proximo != NULL){    //Aqui é um loop, onde vai pegar o ultimo elemento da nossa lista de NO
		lista = lista->proximo;         //O Loop vai funcionar até que o ultimo elemento tenha "->proximo" como NULL
	}
	
	lista->proximo = (ptr_no) malloc(sizeof (no));    // Aqui adicionamos um novo NO, no NO que pegamos dentro do While
	lista = lista->proximo;           //Atribuimos o novo NO a variável "lista" 
	lista->dado = rand()%100;       // Atribuimos um elemento aleatório (0 - 100) 
	lista->proximo = NULL;	        // Adicionamos que o proximo NO é NULL
} 



void lista_remover(ptr_no lista){   // Aqui vai receber o NO inicial
	
	int dado;     // Variavel para pegarmos o dado desejado
	ptr_no atual;     //Criamos um ponteiro auxiliar 
	atual = (ptr_no) malloc(sizeof (no));   // Faremos uma locação dinâmica ao ponteiro
	
	printf("\n\n Escolha um dos itens: ");            //Aqui pedimos ao usuário o dado que ele deseja remover
	scanf(" %d", &dado);        
	
	while(lista->dado != dado){     // Vai rodar o loop, até que a condição seja false, que será quando o elemento for encontrado
    
    // Verificação - Se o lista->proximo for NULL, ele encerra o loop (significa que ele não encontrou o elemento)
		if(lista->proximo == NULL){
			break;
		}
	
		atual = lista;    // Ele passa o NO (lista) para nosso PONTEIRO auxiliar é armazena.
		lista = lista->proximo;   // Para continuação do loop
	}
	
	if(lista->dado == dado){      //Aqui vai verificar se o dado do NO (lista) encontrado no while, é o mesmo dado que desejamos eleminar (dado passado pelo usuário)
		atual->proximo = lista->proximo;      //Aqui ele vai atribuir o NO -> do nosso ponteiro auxiliar para o proximo elemento da lista (dessa forma eliminando o que estava no meio)
	}                                       //NO auxiliar (atual->proximo) vai pegar o proximo endereço do NO que possui o dados (sugerido pelo usuário)
	
	free(lista);        //Limpa a memória  (alocação dinâmica)
	
	

}


void lista_mostrar(ptr_no lista){     //Função para imprimir os dados (NO) na tela
	system("cls");  // Função para Limpar a tela
	
	while(lista->proximo != NULL){    //Um Loop que vai funcionar até pegar o elemento que possua o NULL como proximo
		printf("%d - ", lista->dado);   //Vai imprimir o dado atual
		lista = lista->proximo;         //Condição para movimentarnosso loop funcionar
	}
	
	printf("%d, ", lista->dado );   // Loop irá parar quando chegar ao último elemento, mas sairá do loop sem imprimir o dado do ultimo NO, por isso a necessidade deese printf (para impressão do dado do último NO)
}









