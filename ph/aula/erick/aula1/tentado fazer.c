#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct penis{
    char rm;
    int senha[20];
    float media[3];
}
int main(){
    int qtd;
    printf("digite quantas pessoas vao ter a nota registrada: ");
    scanf("%d", &qtd);
    
    struct penis *prettier=malloc(qtd*sizeof*prettier);

    for(int i=0 ;i<qtd ;i++){
        printf("\n🖋️ Aluno %d:\n", i + 1);
        printf("RM: ");
        scanf("%d", &(prettier[i].rm));
    





    } 






}
