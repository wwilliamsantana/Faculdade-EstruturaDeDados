# Faculdade - Matéria Estrutura De Dados I

<strong>Atividades relacionadas a faculdade!  -   Utilizando linguagem C</strong>
<hr />

## Ponteiros  ↗️

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
 
 ### Alocação dinâmica de memória 
  
Na alocação dinâmica podemos alocar espaços durante a execução de um programa, ou seja, a alocação dinâmica é feita em tempo de execução. Isto é bem interessante do ponto de vista do programador, pois permite que o espaço em memória seja alocado apenas quando necessário. Além disso, a alocação dinâmica permite aumentar ou até diminuir a quantidade de memória alocada.

Utilizamos a função <b>malloc</b> que reserva um espaço na memória do tamanho do <b>sizeof</b> que estamos trabalhando.

#### Exmplos : <br>

![Screenshot 2022-05-17 at 14-40-30 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168878262-0260a747-b806-4217-aec6-1f13371d78fb.png)<br><hr>
![Screenshot 2022-05-17 at 14-40-35 a9963a9390bacc768c18830c916608e119f6efb8fd2f5e97bfbcba1654f8a8f8a878490086adcc4e7bfe172663de0e37d085c2694398fdd2ede23b403ce8d062 pdf](https://user-images.githubusercontent.com/84254929/168878246-35ffbf4c-20d4-4ba7-8b66-8b0181d85040.png)


 ```
 Obs: O Valor: 3673280 é um lixo de memória.. e ela só vai sumir quando atribuirmos conteúdo (<b>*ptr = 10</b>) ao endereço. 
 ```
 Após atribuirmos valor ao ponteiro, nota-se que o endereço vai continuar inalterado.

