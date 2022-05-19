#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define tamanho 5               //Criando uma constante com valor 5

struct tpilha{
	int dados[tamanho];           //Criando a estrutra da nossa pilha
	int ini;
	int fim;
}; 

struct tpilha pilha;          //Definindo algumas variáveis globais. 
int op;


//Aqui abaixo temos nossas funções que estamos declarando.

//Função de Menu.
void menu(){ 
	printf("\n");  
	printf("\n Escolha uma opção : \n\n"); 
	printf("1 - Empilhar um valor \n");
	printf("2 - Desempilhar \n");
	printf("0 - Sair \n");
}

//Função de mostrar o conteúdo da pilha
void pilha_mostrar(){
	int i;
	for(i = 0; i < tamanho; i++){             //Laço de repetição que vai percorrer nossa array e vai mostrar na tela
		printf("[ %d ] - ", pilha.dados[i] );
	};
}

//Função de empilhamento - Adicionar um elemento ao final da pilha

void pilha_entrar(){
	
	if(pilha.fim == tamanho){               //Possuimos uma condição para verificar se a pilha está cheia ( Comparando o tamanho da pilha com nossa constante )
		printf("\n A pilha está cheia!! - ");   //Caso seja true essa condição vai entrar nessa condição.
		system("pause");
	}else{                                    //Caso seja false vamos entrar no else, onde será empilhado.    
		printf("\nDigite o valor a ser empilhado? ");       
		scanf("%d", &pilha.dados[pilha.fim]);   //Aqui estamos atribuindo o valor digitado pelo usuário, na pilha(array) de dados. 
		pilha.fim++;    //**O elemento foi adicionado na array no índice 0, mas nosso índice do fim será 1** (isso será muito importante, mais a frente.)
	};
}

//Função de desempilhamento - Retirar o último elemento da pilha

void pilha_sair(){
	
	if(pilha.fim == pilha.ini){             //Aqui possuímos uma condição, para verificar se a pilha está vazia. (Comparando o tamanho da pilha com nossa variavel inicial(0))
		printf("\n A pilha está vazia ! - ");
		system("pause");
	}else{                            //Caso seja false a condição acima entrará no else.
		pilha.dados[pilha.fim - 1] = 0;   // Aqui estamos pegando o último elemento - 1 e atribuindo o 0 (Lembra que a variável fim, está um valor a frente do índice do nosso dado?) reveja isso na linha 46
		pilha.fim--;                      //Aqui decrementando o variável fim, já que tiramos um elemento.
	};
		
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	pilha.ini = 0;      //Inicialização das variáveis
	pilha.fim = 0;      
	op = 1;
	
	while(op != 0){      // Iremos utilizar um while para manter um loop repetidamente até que o usuário deseja finalizar (Quando digitar 0)
		system("cls");     //Limpar a tela
		pilha_mostrar();   // Vai Exibir nossa pilha
		menu();            //Vai trazer o menu
		printf("\n");       
		scanf("%d", &op);   //Aqui vai pegar o valor digitado na solicitação do menu
		
		switch(op){        //Utilizamos um switch para fazer as chamadas de acordo com o que foi digitado pelo usuário
     
			case 0:     //Fiz essa condição apenas pra evitar que entre no *default* (Condição feita para que se o usuário digitar um valor diferente do valores do menu, entre no defalut)  
				break;     //Vale fazer o teste ai na sua máquina, sem esse *case*
        
			case 1:           //De acordo com o menu e o valor digitado pelo usuário, entrará nessa condição.
				pilha_entrar();     //Chamada da função
			break;
			
			case 2:           //De acordo com o menu e o valor digitado pelo usuário, entrará nessa condição.
				pilha_sair();     //Chamada da função
			break;
			
			default:          //Caso o usuário digite um valor diferente das condições acima, entrará aqui.
				printf("\n**Informe um valor válido**\n\n");
				system("pause");
			break;
		}	
	}
	
	return 0;	
}



