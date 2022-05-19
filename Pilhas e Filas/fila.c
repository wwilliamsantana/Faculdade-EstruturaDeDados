//A principal diferença entre essa estrutura e a Pilhas é a forma de saida! 


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define tamanho 5 			//Criando uma constante com valor 5


struct tfila{
	int dados[tamanho];		 //Criando a estrutra da nossa fila
	int ini;
	int fim;
};


struct tfila fila;			//Definindo algumas variáveis globais. 
int op;	

//Aqui abaixo temos nossas funções que estamos declarando.

//Função de Menu.

void menu(){ 
	printf("\n");  
	printf("\n Escolha uma opção : \n\n"); 
	printf("1 - Incluir na fila \n");
	printf("2 - Excluir da fila \n");
	printf("0 - Sair \n");
}

//Função de mostrar o conteúdo da fila

void fila_mostrar(){
	int i;
	for(i = 0; i < tamanho; i++){			//Laço de repetição que vai percorrer nossa array e vai mostrar na tela
		printf("[ %d ] - ", fila.dados[i]);
	};
}

//Função de adicionar um elemento ao final da fila

void fila_entrar(){
	if(fila.fim == tamanho){
		printf("Fila está cheia!");  //Possuimos uma condição para verificar se a fila está cheia ( Comparando o tamanho da fila com nossa constante )
		system("pause");	    //Caso seja true essa condição vai entrar nessa condição.
	}else{
		printf("\nDigite o valor a ser inserido? ");
		scanf("%d", &fila.dados[fila.fim]); //Aqui estamos atribuindo o valor digitado pelo usuário, na fila de dados (array). 
		fila.fim++;	//**O elemento foi adicionado na array no índice 0, mas nosso índice do fim será 1** (isso será muito importante, mais a frente.)
	}
	
}

void fila_sair(){
	if(fila.fim == fila.ini){ //Aqui possuímos uma condição, para verificar se a fila está vazia. (Comparando o tamanho da fila com nossa variavel inicial(0))
		printf("\n A fila está vazia ! - ");
		system("pause");
	}else{
		int i;
		
		for(i = 0; i < tamanho; i++){		//Fazemos um laço de repetição para percorrer nossa array.
			fila.dados[i] = fila.dados[i + 1];	//Ele vai fazer nossa fila andar, falando de um grosso modo. 
							//Ele vai pegar o proximo elemento da array e vai atribuir ao índice inicial da nossa array.
							//Índice 1 passar a se tornar 0 => Índice 2 passa a se tornar 1 .... é assim sucessivamente
	
		};
		
		fila.dados[fila.fim] = 0;	// Aqui ele vai zerar o último índice da fila
		fila.fim--;			//Decrementamos a variável fim.
	}
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	fila.ini = 0;
	fila.fim = 0;		//Inicialização das variáveis
	op = 1;
	
	while(op != 0){		// Iremos utilizar um while para manter um loop repetidamente até que o usuário deseja finalizar (Quando digitar 0)
		system("cls"); //Limpar a tela
		fila_mostrar(); // Vai Exibir nossa fila
		menu(); 	//Vai trazer o menu
		printf("\n");
		scanf("%d", &op);  //Aqui vai pegar o valor digitado na solicitação do menu
		
		switch(op){ 	 //Utilizamos um switch para fazer as chamadas de acordo com o que foi digitado pelo usuário
				
			case 0:	//Fiz essa condição apenas pra evitar que entre no *default* (Condição feita para que se o usuário digitar um valor diferente do valores do menu, entre no defalut)  
			break;	//Vale fazer o teste ai na sua máquina, sem esse *case*
			
			case 1: 	//De acordo com o menu e o valor digitado pelo usuário, entrará nessa condição.
				fila_entrar();	//Chamada da função
			break;
			
			case 2: //De acordo com o menu e o valor digitado pelo usuário, entrará nessa condição.
				fila_sair();  //Chamada da função
			break;
			
			default:  //Caso o usuário digite um valor diferente das condições acima, entrará aqui.
				printf("Digite um valor válido!  - ");
				system("pause");
			break;
			
		}
	
	}
	return 0;
}
