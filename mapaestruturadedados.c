#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_pilha{
    char nucleot;
    struct no_pilha *prox;
}no_pilha;

typedef struct Pilha{
    no_pilha *topo;
}Pilha;

no_pilha *aux;


Pilha* create_pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;
    }
    return pi;
}

void addToStack(Pilha* pi, char nucleot){
    no_pilha *novo = (no_pilha*)malloc(sizeof(no_pilha));
    
    novo->nucleot = nucleot;
    novo->prox = pi->topo;
    pi->topo = novo;
    
}


void printStack(Pilha* pi){
    if(pi->topo == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    else{
        aux = pi->topo;
        do{
            printf("%c",aux->nucleot);
            aux = aux->prox;
        }while(aux != NULL);
    }
}

typedef struct no_fila{
    char nucleot;
    struct no_fila *prox;   
}no_fila;

typedef struct Fila{
    struct no_fila *inicio;
    struct no_fila *fim;
}Fila;

no_fila *aux2;

Fila* cria_fila(){
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void enqueue(Fila* fi, char nucleot){
    no_fila* novo = (no_fila*)malloc(sizeof(no_fila));
    novo->nucleot = nucleot;
    novo->prox = NULL;

    if(fi->inicio == NULL){
        fi->fim = novo;
        fi->inicio = novo;
    }
    else{
        fi->fim->prox = novo;
        fi->fim = novo;
    }
}

void dequeue(Fila* fi){
    if(fi->inicio == NULL){
        printf("\nFila vazia!\n");
    }
    else{
        aux2 = fi->inicio;
        fi->inicio = fi->inicio->prox;
        free(aux2);
    }
}

void printQueue(Fila* fi){
    if(fi->inicio == NULL){
        printf("Fila vazia!\n");
        return;
    }
    else{
        aux2 = fi->inicio;
        do{
            printf(" %d ",aux->nucleot);
            aux2 = aux2->prox;
        }while(aux2 != NULL);
    }
}

int main(){
    Fila* fi = cria_fila();
    Pilha* pi = create_pilha();
    char combinacao[100];

    printf("Digite a combinacao de nucleotideos: ");
    scanf("%s", combinacao);

    int tamanho = strlen(combinacao);

    for (int i = 0; i < tamanho; i++) {
        enqueue(fi, combinacao[i]);
    }
    while (fi->inicio != NULL) {
        char nucleot = fi->inicio->nucleot;
        dequeue(fi);

        switch (nucleot) {
            case 'A':
                addToStack(pi, 'T');
            break;
            case 'T':
                addToStack(pi, 'A');
            break;
            case 'C':
                addToStack(pi, 'G');
            break;
            case 'G':
                addToStack(pi, 'C');
            break;
            default:
                printf("Nucleotideo inválido: %c\n", nucleot);
            break;
        }
    }
    printf("Fila: ");
    printQueue(fi);
    printf("Pilha: ");
    printStack(pi);
    return 0;
}