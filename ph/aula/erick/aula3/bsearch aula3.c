//perguntar pro erick

// usar isso para ordenar com o qsort usando um gerador 
//bsearch faz busca bianria em vetor ja ordenado conforme o msm comparador(vao funfar em vetores pequeno) 
//
//ent pra fazer busca binaria precisa ordenar primeiro 
//etsudar todos os modos modos de ordenacao pra fazer isso q a gtn fez agr 
//tabela simples e fazer a melhor combinacao com e sem ordenacao gerando um relatario  
//
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int   rm;
    char  nome[32];
    float media;
} Aluno;

int cmp_rm_asc(const void *a, const void *b) {
    const Aluno *x = (const Aluno*)a;
    const Aluno *y = (const Aluno*)b;
    return (x->rm > y->rm) - (x->rm < y->rm);
}

int busca_linear_rm(const Aluno *v, int n, int alvo_rm, long *comps) {
    for (int i = 0; i < n; i++) {
        if (comps) (*comps)++;
        if (v[i].rm == alvo_rm) return i;
    }
    return -1;
}

void ordenar_por_rm(Aluno *v, int n) {
    qsort(v, (size_t)n, sizeof(Aluno), cmp_rm_asc);
}

int busca_binaria_rm(const Aluno *v, int n, int alvo_rm, long *comps) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (comps) (*comps)++;                              //ele faz log do big O
        if (v[m].rm == alvo_rm) return m;                   //ele compara o alvo com o rm c for igual ele retorn o m 
        if (v[m].rm < alvo_rm) l = m + 1; else r = m - 1;   //ele retorna 1 pro comeco e reseta fznd a busca de nv 
    }
    return -1;
}

int buscar_com_bsearch(const Aluno *v, int n, int alvo_rm) {    //
    Aluno chave = { .rm = alvo_rm };
    const Aluno *p = bsearch(&chave, v, (size_t)n, sizeof(Aluno), cmp_rm_asc);      //
    return p ? (int)(p - v) : -1;                                                   //? é um if c for verdadeiro ele exibi o primeiro c for o falso ele faz o segundo(ternario)
}

void imprimir(const Aluno *v, int n, const char *titulo) {
    printf("\n%s\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("RM:%d | Nome:%-10s | Média: %.2f\n", v[i].rm, v[i].nome, v[i].media);
    }
}

int main(void) {
    Aluno turma[] = {
        {101, "Alice", 7.5f},
{102, "Beto", 8.0f},
{103, "Carlos", 9.1f},
{104, "Diana", 6.3f},
{105, "Eduardo", 7.8f},
{106, "Fernanda", 6.5f},
{107, "Gabriel", 8.4f},
{108, "Heloísa", 7.6f},
{109, "Igor", 8.7f},
{110, "Júlia", 9.3f},
{111, "Kátia", 7.0f},
{112, "Lucas", 6.9f},
{113, "Márcia", 8.1f},
{114, "Neto", 9.0f},
{115, "Olga", 6.8f},
{116, "Paulo", 7.2f},
{117, "Quésia", 8.9f},
{118, "Rafael", 7.1f},
{119, "Sofia", 9.4f},
{120, "Tiago", 6.4f},
{121, "Ursula", 8.2f},
{122, "Vitor", 7.9f},
{123, "Wanda", 8.6f},
{124, "Xuxa", 9.5f},
{125, "Yara", 7.4f},
{126, "Zé", 8.3f},
{127, "Amanda", 7.9f},
{128, "Bruna", 9.0f},
{129, "Cecília", 6.2f},
{130, "Daniel", 8.5f},
{131, "Emília", 9.1f},
{132, "Fábio", 6.7f},
{133, "Gustavo", 7.8f},
{134, "Helena", 8.4f},
{135, "Igor", 7.1f},
{136, "João", 8.0f},
{137, "Karine", 7.3f},
{138, "Lúcia", 9.2f},
{139, "Mário", 6.6f},
{140, "Natália", 8.2f},
{141, "Omar", 7.0f},
{142, "Patrícia", 8.7f},
{143, "Quintino", 6.9f},
{144, "Raíssa", 9.3f},
{145, "Silvio", 8.1f},
{146, "Tatiane", 7.6f},
{147, "Uéliton", 9.4f},
{148, "Vânia", 6.5f},
{149, "Wellington", 8.9f},
{150, "Ximena", 7.7f},
{151, "Yasmin", 8.0f},
{152, "Zilda", 9.6f},
{153, "André", 6.8f},
{154, "Beatriz", 7.4f},
{155, "Carlos", 8.6f},
{156, "Daniele", 7.2f},
{157, "Ezequiel", 9.0f},
{158, "Flávia", 8.0f},
{159, "Geraldo", 6.3f},
{160, "Helder", 8.8f},
{161, "Ísis", 7.5f},
{162, "Jorge", 9.1f},
{163, "Kleber", 7.9f},
{164, "Luciana", 8.3f},
{165, "Mário", 9.4f},
{166, "Nádia", 7.0f},
{167, "Olga", 8.1f},
{168, "Paula", 6.6f},
{169, "Queila", 8.7f},
{170, "Rogério", 7.8f},
{171, "Samuel", 9.2f},
{172, "Tânia", 6.9f},
{173, "Ulisses", 8.4f},
{174, "Viviane", 7.5f},
{175, "Wilma", 8.2f},
{176, "Xandra", 9.5f},
{177, "Yuri", 7.3f},
{178, "Zélia", 8.6f},
{179, "Adriana", 7.9f},
{180, "Bárbara", 8.1f},
{181, "Cláudio", 9.0f},
{182, "Diego", 6.7f},
{183, "Esther", 7.8f},
{184, "Filipe", 9.3f},
{185, "Gabriela", 8.3f},
{186, "Hélio", 7.4f},
{187, "Irene", 8.2f},
{188, "Janaína", 6.5f},
{189, "Karla", 9.4f},
{190, "Leonardo", 7.1f},
{191, "Marcos", 8.0f},
{192, "Nico", 7.6f},
{193, "Olga", 9.1f},
{194, "Pedro", 8.3f},
{195, "Queila", 6.8f},
{196, "Raul", 9.5f},
{197, "Sérgio", 7.0f},
{198, "Tatiane", 8.6f},
{199, "Ubirajara", 8.7f},
{200, "Valéria", 7.9f},
{201, "Walter", 9.0f},
{202, "Xuxa", 8.8f},
{203, "Yago", 6.4f},
{204, "Zita", 8.2f},
{205, "Ana", 8.1f},
{206, "Bruno", 7.5f},
{207, "Clara", 9.4f},
{208, "Diego", 8.7f},
{209, "Eva", 7.2f},
{210, "Lia", 9.0f},
{211, "Fernanda", 6.6f},
{212, "Igor", 7.9f},
{213, "Jonas", 8.0f},
{214, "Karine", 7.4f},
{215, "Lúcia", 8.9f},
{216, "Mariana", 9.3f},
{217, "Neto", 7.2f},
{218, "Olga", 8.5f},
{219, "Pedro", 7.8f},
{220, "Quélia", 6.3f},
{221, "Rogério", 9.0f},
{222, "Sandra", 8.0f},
{223, "Tatiane", 8.3f},
{224, "Valter", 7.5f},
{225, "Wellington", 9.4f},
{226, "Ximena", 7.6f},
{227, "Yara", 8.1f},
{228, "Zilda", 6.9f},
{229, "Arthur", 8.8f},
{230, "Bárbara", 9.5f},
{231, "César", 7.0f},
{232, "Davi", 8.3f},
{233, "Eliana", 8.7f},
{234, "Felipe", 6.7f},
{235, "Giovana", 9.1f},
{236, "Hugo", 8.2f},
{237, "Íris", 7.9f},
{238, "Juliano", 9.0f},
{239, "Kiko", 6.4f},
{240, "Lúcia", 8.5f},
{241, "Marcio", 7.2f},
{242, "Nádia", 8.6f},
{243, "Oscar", 7.1f},
{244, "Pâmela", 9.2f},
{245, "Quésia", 8.9f},
{246, "Rogério", 7.4f},
{247, "Sabrina", 6.8f},
{248, "Tatiane", 9.3f},
{249, "Uélton", 8.1f},
{250, "Vera", 7.0f}

    };
    int n = (int)(sizeof turma / sizeof turma[0]);

    imprimir(turma, n, "Estado inicial (não ordenado)");

    long c_lin = 0;
    int alvo = 240;
    int i_lin = busca_linear_rm(turma, n, alvo, &c_lin);
    printf("\nLinear: alvo=%d -> idx=%d | comparações=%ld\n", alvo, i_lin, c_lin);
    
    
    
    ordenar_por_rm(turma, n);                           //para fazer ocmparacao precisa ser feita outra funcao(la em cima)
    imprimir(turma, n, "Ordenado por RM (qsort)");      // sendo semp necesaariro acompanhar esses itens 

    long c_bin = 0;                                     //
    int i_bin = busca_binaria_rm(turma, n, alvo, &c_bin);//
    printf("Binária: alvo=%d -> idx=%d | comparações=%ld\n", alvo, i_bin, c_bin);

    int i_bs = buscar_com_bsearch(turma, n, alvo);
    printf("bsearch: alvo=%d -> idx=%d\n", alvo, i_bs);
    return 0; 
}
