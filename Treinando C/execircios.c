#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;    
    struct no * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void add(int valor, int pos){
    NO * novo = (NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    else if(pos == 0){
    novo->prox = inicio;
    inicio = novo;
    }
    else if(pos == tam){
    fim->prox=novo;
    fim = novo;
    }
    else{
        NO *aux = inicio;
        for(int i = 0; i <pos-1; i++){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    tam++;
}

void imp(){
    NO * aux = inicio;
    int i;
    for(i = 0; i < tam; i++){
        printf("%d \n", aux -> valor);
        aux = aux -> prox;
    }
}

int main(){
    printf("rodando \n");
    add(1,0);
    add(5,0);
    add(2,0);
    imp();
    printf("ok \n");
    add(8,3);
    add(77,2);
    imp();
    return 0;
}