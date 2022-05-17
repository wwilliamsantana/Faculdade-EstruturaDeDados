int main(int argc, char *argv[]) {
	
	int *ptr; //criação do ponteiro
	
	ptr = (int *)malloc(sizeof (int));  //Fazendo alocação dinâmica !!
	
	*ptr = 54;  //Atribuindo um valor a memória 
	
	printf("Endereco: %p \n\nValor : %d", ptr, *ptr);  //Imprimimos na tela o endereço do ponteiro e o valor contido nele
	
	
	
	return 0;
}
