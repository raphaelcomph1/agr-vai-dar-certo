//               ordenacao de registros
#fcfca7//pq usar? melhor a leitura, complementa na hora da busca

#f0f085 //structs e chaves Ao ordenar um vetor de struct, definimos uma chave: por exemplo, ordenar por media (decrescente) ou por nome (crescente). 

#f0f085 // um algoritmo é estavel quando mantem a ordem relativa de elementos que tem a mesma chave 

#f0f085 //complexidade assintotica= ordenacao simples como bubble sort e insertion sorte tem pior caso o(n²) e consomem espaco o(1)


#f0f085 //escolhas praticas = Em vetores pequenos (ex.: uma turma), Insertion Sort é simples e rápido o suficiente. Quando o requisito é genérico (ordenar qualquer tipo) e com bom desempenho, usamos qsort com um comparador. Se precisarmos de estabilidade, preferimos um algoritmo estável (ex.: Insertion) ou simulamos estabilidade no comparador com chaves secundárias (ex.: ordenar por média, e em caso de empate, por nome).



// #f0f085 1)quando for usar mto uma struct coloca 
// typedef struct {
//     int a;
//     int b;
//     float c;
// } Aluno;


// //2)
// void imprimir(const Aluno *v, int n, const char *titulo) {
//     printf("\n%s\n", titulo);
//     for (int i = 0; i < n; i++) {
//         printf("RM:%d | Nome:%-10s | Média: %.2f\n", v[i].rm, v[i].nome, v[i].media);
//     }
// }


// // 3)bubble sorte(media decrescente )

// void bubble_media(Aluno*v, int n){
//     int trocou;
//     do{
//         trocou = 0
//         for(int i = 0; i<n ;i++){
//             if(v[i].media<v[i+1].media){//troca so quando for estritamente menor
//             Aluno tmp = v[i];
//             v[i+1] = tmp;
//             trocou = 1;
//             }
//         }
//         n---; //ultimo elemento ja na posicao certa 
//     }while(trocou);
// }


//juntando tudo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int   rm;
    char  nome[32];
    float media;
} Aluno;

void imprimir(const Aluno *v, int n, const char *titulo) {
    printf("\n%s\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("RM:%d | Nome:%-10s | Média: %.2f\n", v[i].rm, v[i].nome, v[i].media);
    }
}

void bubble_media_desc(Aluno *v, int n) {
    int trocou;
    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].media < v[i+1].media) { // troca só quando for estritamente menor
                Aluno tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                trocou = 1;
            }
        }
        n--; // último elemento já está na posição correta
    } while (trocou);
}

void insertion_nome_asc(Aluno *v, int n) {
    for (int i = 1; i < n; i++) {
        Aluno chave = v[i];
        int j = i - 1;
        while (j >= 0 && strcmp(v[j].nome, chave.nome) > 0) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}

int cmp_rm_asc(const void *a, const void *b) {
    const Aluno *x = (const Aluno*)a;
    const Aluno *y = (const Aluno*)b;
    return (x->rm > y->rm) - (x->rm < y->rm); // evita overflow de subtração
}

int busca_binaria_rm(const Aluno *v, int n, int rm) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m].rm == rm) return m;
        if (v[m].rm < rm) l = m + 1; else r = m - 1;
    }
    return -1; // não encontrado
}

int main(void) {
    Aluno turma[] = {
        {321, "Ana",    8.5f},
        {215, "Bruno",  6.7f},
        {405, "Clara",  9.2f},
        {198, "Diego",  6.7f}, // mesma média de Bruno (para ver estabilidade)
        {377, "Eva",    10.0f},
        {142, "Lia",     7.3f}
    };
    int n = (int)(sizeof turma / sizeof turma[0]);

    imprimir(turma, n, "Estado inicial");

    bubble_media_desc(turma, n);
    imprimir(turma, n, "Ordenado por média (decrescente) – Bubble (estável)");

    insertion_nome_asc(turma, n);
    imprimir(turma, n, "Ordenado por nome (crescente) – Insertion (estável)");

    qsort(turma, n, sizeof(Aluno), cmp_rm_asc);
    imprimir(turma, n, "Ordenado por RM (crescente) – qsort");

    int alvo = 198;
    int idx = busca_binaria_rm(turma, n, alvo);
    printf("\nBusca binária por RM=%d → %s (índice %d)\n", alvo,
           (idx >= 0 ? turma[idx].nome : "não encontrado"), idx);

    return 0;
}