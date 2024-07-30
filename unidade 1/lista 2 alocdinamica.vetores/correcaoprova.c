#include <stdio.h>

int main() {
    int n; 
    float notaAluno[10]; 
    int numAprovados = 0; 

    printf("Informe o número de questões: ");
    scanf("%d", &n);
    char *gabarito = (char *) malloc(n * sizeof(char));
    if (gabarito == NULL) {
        printf("erro na alocação de memoria\n");
        return 1; 
    }

    printf("Informe o gabarito da prova: ");
    scanf("%s", gabarito);

    char **respostas = (char **) malloc (10 * sizeof(char *));
    if(respostas == NULL){
        printf("erro na alocação de memoria\n");
        free(gabarito);
        return 1;
    }

    for (int i = 0; i < 10; i++){
        respostas[i] = (char *) malloc((n+ 1) *sizeof(char));
        if(respostas[i] == NULL){
            printf("erro na alocação de memoria\n");
            for(int j = 0; j < i; j++){ //libera memoria
                free(respostas[j]);
            }
            free(respostas);
            free(gabarito);
            return 1;
        }
    }
    printf("Informe as respostas dos 10 alunos:\n");
    for(int i = 0; i < 10; i++){
        scanf("%s", respostas[i]);
    }
    float notaPorQuestao = 10.0 / n;

    for(int i = 0; i < 10; i++){
        float nota = 0.0;
        for(int j = 0; j < n; j++){
            if(respostas[i][j] == gabarito[j]){
                nota += notaPorQuestao;
            }
        }
        notaAluno[i] = nota;
        if(nota >= 6.0){
            numAprovados++;
        }
        printf("nota do aluno %d %.2f\n", i + 1, nota);
    }
    float porcentagemAprovacao = (numAprovados / 10.0) * 100.0;
    printf("Porcentagem de aprovaçao: %.2f%%\n", porcentagemAprovacao);

    for(int i = 0; i < 10; i++){ //libera memoria 
        free(respostas[i]);
    }
    free(respostas);
    free(gabarito);

    return 0;
}