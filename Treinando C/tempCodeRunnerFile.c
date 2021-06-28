#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;    
    struct no * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void add(int valor){
    printf("entro add");
    NO * novo = (NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = inicio;
    inicio = novo;
}

void imp(){
    printf("entro imprimir");
    NO * aux = inicio;
    int i;
    for(i = 0; i < tam; i++){
        printf("%d \n", aux -> valor);
        aux = aux -> prox;
    }
}

int main(){
    printf("rodando \n");
    add(1);
    add(5);
    add(2);
    imp();
    printf("ok \n");
    add(8);
    imp();
    return 0;
}