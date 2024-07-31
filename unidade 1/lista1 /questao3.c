#include <stdio.h>

int main (void){
    int a,b,c,d; 
    int *p1;
    int * p2=&a a;  // endereco de a
    int *p3=&c;    // endereco de c
    p1=p2;
    *p2=10;       //endereco de a=10 
    b=20;
    int ** pp;    //ponteiro p ponteiro 
    pp = &p1;     //pp ponteiro de ponteiro endereco de p1
    *p3= **pp;    // p3 aponta pp= endereco de p1=p2= 10 
    int *p4= &d; // endereco de d  
    *p4 =b + (*p1) ++; //d=20+10=30; p1(a) +1=11
    printf ("%d \t %d \t %d \t %d \n" , a,b,c,d);
    return 0 
}


//resultado final:
a=11
b=20
c=10
d=30