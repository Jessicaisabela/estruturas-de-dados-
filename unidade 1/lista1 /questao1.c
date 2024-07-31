int x, y, *p;

y = 0; 
p = &y; //endereço de y
x = *p; // valor de p 
x = 4; 

(*p)++; // y passa a ser 1 
--x; // x passa a ser 3 (4 - 1)
(*p) += x; // 1 + 3 = 4 (*p é o endereço de y;)

/*RESULTADO FINAL DE:
x = 3;
y = 1;
p = endereço de y; 
*/