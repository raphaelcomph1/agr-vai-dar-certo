#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definição da estrutura Aluno
struct Aluno {
    int rm;            // Registro do aluno
    char nome[30];     // Nome do aluno
    float notas[3];    // Três notas
};

int main() {
    int n;
    printf("Quantos alunos na turma? ");
    scanf("%d", &n);

    // 2. Alocação dinâmica do vetor de structs
    struct Aluno *turma = malloc(n * sizeof *turma);
    if (!turma) {
        perror("malloc falhou");
        return EXIT_FAILURE;
    }

    // 3. Leitura dos dados dos alunos
    for (int i = 0; i < n; i++) {
        printf("\n🖋️ Aluno %d:\n", i + 1);
        printf("RM: ");
        scanf("%d", &(turma[i].rm));

        printf("Nome: ");
        scanf(" %s29[^\n]", turma[i].nome); // lê até 29 caracteres ou nova linha

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &(turma[i].notas[j]));
        }
    }

    // 4. Cálculo da média e exibição
    printf("\n🌟 Lista final de alunos:\n");
    for (int i = 0; i < n; i++) {
        float soma = 0;
        for (int j = 0; j < 3; j++) {
            soma += turma[i].notas[j];
        }
        float media = soma / 3;

        printf("%d – RM:%d Nome:%s Média:%.2f\n",
               i + 1, turma[i].rm, turma[i].nome, media);
    }

    // 5. Liberação de memória
    free(turma);
    return 0;