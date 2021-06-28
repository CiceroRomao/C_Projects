#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;    
    struct no * prox;
}NO;

NO *inicio = NULL;
int tam = 0;

//adicionar no inicio da pilha 
void add (int valor){
        NO *novo = (NO*) malloc (sizeof (NO));
        novo->valor = valor;
        novo->prox = NULL;
        inicio = novo;
        tam++;
}

//remover da pilha
int del(){
    // remover inicio
    NO* aux=inicio;
    inicio=inicio->prox;
    free(aux);
    printf("sinal 1\n");
}
        

//imprimir a lista
void imprimir(){
    NO *aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("%d \n", aux -> valor);
        aux = aux -> prox;
    }
}

int main(){
    add(1);
    add(2);
    add(3);
    add(4);
    imprimir();
    del(2);
    printf("apos deletar \n");
    imprimir();
    return 0;
}