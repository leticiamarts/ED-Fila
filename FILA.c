#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No{
    char nome[41];
    struct No *proximo;
};

struct Fila{
    struct No *inicio, *fim;
};

void Qinit(struct Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enqueue(struct Fila *fila){
    struct No *novoNo;
    char nomeAux[41];

    while(strcmp(nomeAux, "FIM")){
        novoNo = (struct No*) malloc (sizeof(struct No)); 
        printf("Insira o nome:\n");
        scanf(" %40[^\n]s", nomeAux);
        scanf("%*[^\n]");
        scanf("%*c");
        if(strcmp(nomeAux, "FIM") != 0){
            strcpy(novoNo->nome, nomeAux);
            novoNo->proximo = NULL;

            if(fila->inicio == NULL){
                fila->inicio = novoNo;
                fila->fim = novoNo;
            }
            else{
                fila->fim->proximo = novoNo;
                fila->fim = novoNo;
            }
        }
        else{
            break;
        }
    }
}

void showAll(struct Fila *fila){
    struct No *aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
        printf("%s\n", aux->nome);
    }
}

int main(){
    struct Fila fila;
    Qinit(&fila);
    enqueue(&fila);
    showAll(&fila);

    return 0;
}