#include <stdio.h>

int main (void) {
    int x, *p; // p, ponteiro para inteiro
    x = 100;
    p = x; 
    printf("Valor de p = %p \t Valor de *p=%d", p, *p);
}


/*ALTERNATIVA a) Esta mensagem é de erro ou advertência?

Na segunda linha do código, foi declarado o ponteiro p que receberá um endereço de um valor inteiro (4 bytes), 
mas ele recebe um valor inteiro normal e não um endereço de memória o que não será erro de compilação, já que existe espaço suficiente 
no endereço que o ponteiro p está para receber um valor inteiro, deste modo o motivo para advertência.

Na função printf o compilador está recebendo dois ponteiros, o primeiro(p) mostra o endereço para onde aponta e o segundo(*p) mostra
 o conteúdo deste endereço. Porém, o programa espera um endereço de memória como conteúdo. Assim, ao tentar acessar o conteúdo de um 
 endereço de memória inesxistente, irá gerar um erro. Finalizando o programa sem a execução. */

/*ALTERNATIVA b) Por que o compilador emite tal mensagem?

O compilador vai mostrar uma advertência porque foi designado o valor da variável x ao ponteiro p, que é um valor inteiro e não um endereço.
O erro da última linha acontece porque o compilador espera um ponteiro para um endereço, como foi atribuído um valor inteiro, o endereço e o conteúdo não existem. 
Fazendo com o que a função printf não seja executada corretamente, finalizando o programa.
*/

/*ALTERNATIVA c) Compile e execute o progama. A execução foi bem sucedida?

Aparece a advertência e o printf não é exibido. Depois o programa é encerrado, desta forma a execução não é bem sucedida.
*/

/*ALTERNATIVA d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.

#include <stdio.h> //

int main (void) {
    int x, *p; // p, ponteiro para inteiro
    x = 100;
    p = &x; // adicionado "&" operador de endereço
    printf("Valor de p = %p \t Valor de *p = %d", p, *p);
    return 0; //sair da função main
}
*/

/*ALTERNATIVA e) Compile e execute novamente o programa. A execução foi bem sucedida?

O programa foi compilado e executado corretamente como esperado.
Valor de p = 0061FEF8    Valor de *p = 100
*/