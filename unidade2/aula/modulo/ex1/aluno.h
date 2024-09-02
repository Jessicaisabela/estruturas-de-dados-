/*Arquivo cabeçalho para tipo abstrato de dados (TAD) Aluno*/

/*Tipo exportado*/
typedef struct aluno Aluno;

/*Função para preencher uma struct Aluno. A função recebe um 
endereço para aluno*/
void preenche(Aluno * aluno);

/*Função para imprimir uma struct Aluno. A função recebe um 
endereço para aluno e imprime os dados*/
void imprime(Aluno * aluno);

/*Função que alooca dinamicamente uma struct aluno na memoria*/
Aluno * alocaAluno(void);