# Faculdade - Matéria Estrutura De Dados I

<strong>Atividades relacionadas a faculdade!  -   Utilizando linguagem C</strong> <br>

<hr />

## Sumário

- [Ponteiros](#ponteiros)
- [Alocação dinâmica de memória](#alocacao_dinamica)
- [Pilhas e Filas](#pilhas_filas)
- [Métodos de Ordenação](#ordenacao)

<hr>

## Ponteiros  ↗️ <a name="ponteiros"></a>

<p>Ponteiros ou apontadores, são variáveis que armazenam o endereço de memória de outras variáveis.<br>Dizemos que um ponteiro “aponta” para uma varíável quando contém o endereço da mesma.<br>Os ponteiros podem apontar para qualquer tipo de variável. Portanto temos ponteiros para int, float, double, etc.</p>



#### Exmplos : <br>

![Screenshot 2022-05-17 at 14-03-00 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168870302-8de677bb-7a84-43e8-a86d-9e77c9eb697b.png) <br><br>
![Screenshot 2022-05-17 at 14-02-31 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168870371-38dd5aa9-aa6f-4ff9-856c-f34b5d66e456.png)<br><br>
![Screenshot 2022-05-17 at 14-02-05 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168870367-7a677b8c-0f80-4cf4-a550-9fdf2047936e.png)

<strong> Ordem de impressão na tela : </strong>
<ul>
  <li> xi =  Vai monstrar o <strong>valor</strong> do xi</li>
  <li> &xi = Imprimi o <strong>endereço</strong> de memória do xi</li>
  <li> ptr_xi  = Vai apontar para o <strong>endereço</strong> da variável xi </li>
  <li> *ptr_xi  = Vai apontar para o <strong>conteúdo</strong> da variável xi</li>
 </ul>
 
```
Obs:  & => Quando se quer trabalhar com ENDEREÇOS
      *  => Quando se quer trabalhar com CONTEÚDOS
 ```
 <hr>
 
 ## Alocação dinâmica de memória <a name="alocacao_dinamica"></a>
  
Na alocação dinâmica podemos alocar espaços durante a execução de um programa, ou seja, a alocação dinâmica é feita em tempo de execução. Isto é bem interessante do ponto de vista do programador, pois permite que o espaço em memória seja alocado apenas quando necessário. Além disso, a alocação dinâmica permite aumentar ou até diminuir a quantidade de memória alocada.

Utilizamos a função <b>malloc</b> que reserva um espaço na memória do tamanho do <b>sizeof</b> que estamos trabalhando.

#### Exemplos : <br>

![Screenshot 2022-05-17 at 14-40-30 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168878262-0260a747-b806-4217-aec6-1f13371d78fb.png)<br><hr>
![Screenshot 2022-05-17 at 14-40-35 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168878246-35ffbf4c-20d4-4ba7-8b66-8b0181d85040.png)


 ```
 Obs: O Valor: 3673280 é um lixo de memória.. e ela só vai sumir quando atribuirmos conteúdo ( *ptr = 10 ) ao endereço. 
 ```
 Após atribuirmos valor ao ponteiro, nota-se que o endereço vai continuar inalterado.
 
 <hr>
 
 ## Pilhas e Filas <a name="pilhas_filas"></a>
 
Uma pilha é um tipo de estrutura de dado, que é uma maneira de se organizar e usar dados, informações.
A regra das pilhas é famoso LIFO - Last In, First Out, ou seja, o **último a entrar é o primeiro a sair** da estrutura.

A fila é uma estrutura de dados que armazena os dados na ordem FIFO (First In First Out), em português **Primeiro a Entrar Primeiro a Sair**. A recuperação de dados será feita na ordem de inserção
 
 <hr>
 
  
 ## Métodos de Ordenação <a name="ordenacao"></a>
 
 ### Bubblesort
 - A técnica de ordenação Bubblesort também é conhecida por ordenação por
 flutuação ou por método da bolha. Ela é de simples implementação e de alto
 custo computacional. Começando na primeira posição do vetor, compara-se o
 valor dela com todos os demais elementos, trocando caso o valor da posição
 atual seja maior do que o valor verificado. Os valores mais altos vão flutuando
para o final do vetor, criando a ordenação da estrutura. Esse processo se repete
para cada uma das posições da tabela.

 ### Selectionsort
 - A técnica também é de simples implementação e de alto consumo computacional.
A partir da primeira posição, procura-se o menor valor em todo o vetor. Chegando
no final da estrutura, trocamos o menor valor encontrado com a primeira posi-
ção. Em seguida, ele parte para a segunda posição e passa a procurar o segundo
menor valor do vetor até o final da tabela, fazendo a troca de posição dos valores.
 ### Insertionsort
 - A ordenação Insertionsort também é conhecida como ordenação por inser-
ção. É de implementação simples e traz bons resultados. A técnica consiste em
remover o primeiro elemento da lista, e procurar sua posição ideal no vetor e
reinseri-lo na tabela. O processo é repetido para todos os elementos.
A princípio o Insertionsort é muito parecido com o Bubblesort e o
Selectionsort, já que todos os três trazem dois laços de repetição aninhados,
porém os dois últimos percorrem sempre os dois laços por inteiro. Esse é o
motivo do Insertionsort ser mais rápido do que os outros dois
 ### Shellsort
 - Ao invés de tratar o arquivo como um todo, ele divide a tabela em segmentos
menores e em cada um deles é aplicado o Insertionsort. Ele faz isso diversas
vezes, dividindo grupos maiores em menores até que todo o vetor esteja ordenado.Ele
possui uma variável chamada gap. O gap determina a distância entre os elemen-
tos que serão removidos do vetor original. Ao subvetor aplica-se o algoritmo de
Insertionsort, e o subvetor é novamente inserido no vetor original. O processo
se repete até atingir todos os elementos.

