#include <stdio.h>
int comprimento (char * str);
void copia (char* dest, char* orig );
void concatena(char *dest,char* orig);
int main (void){
    char str[101], str1[51], str2[51];
    printf("digite um sequencia de caractere:");
    scanf (" %50[^\n]", str1);
    printf("digte outra sequencia de caracteres:");
    scanf(" %50[^\n]", str2);
    copia (str, str1);
    concatena (str, str2);
    printf ("comprimento da concatenacao: %d\n", comprimento(str));
    return 0;

}