#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;    
    struct no * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

//adicionar na lista encadeada
void add (int valor, int pos){
    if(pos >= 0 && pos <= tam){
        NO * novo = (NO*) malloc (sizeof (NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){ //tam ser igual zero lista vazia // add no inicio com a lista vazia
            inicio = novo;
            fim = novo;
        }
        else if(pos == 0){ //lista nao esta vazia/ add no inicio da lista
            novo->prox = inicio;
            inicio = novo;
        }
        else if(pos == tam){ // no fim da lista
            fim->prox = novo;
            fim = novo;
        }
        else{ // adicionar no meio
            NO * aux = inicio;
              int i;
            for(i = 0; i < pos-1; i++){
                aux = aux -> prox;
            }
            novo -> prox = aux -> prox;
            aux -> prox = novo;
        }
        tam++;
    }
}

//remover da lsta
NO *del(int pos){
    if(pos >= 0 && pos <tam){
        if(pos == 0){// remover inicio
            NO* aux = inicio;
            inicio = inicio -> prox;
            free(aux);
            printf("sinal 1\n");
        }
        else if(pos == tam-1){ // remover fim (forma linear) ---estudar constante
            NO * aux = inicio;
            for(int i = 0; i< tam-1; i++){
                aux = aux -> prox;  
            }
            NO * lixo = fim;
            aux -> prox = NULL;
            fim = aux;
            free(lixo);
            printf("sinal2 \n");
        }
        else{// remover no meio
            NO *aux = inicio;
            for(int i = 0; i <pos-1; i++){
                aux = aux->prox;
            }
            NO *lixo = aux->prox;
            aux = aux->prox = aux->prox;
            free(lixo); 
            printf("sinal 3\n");
        }
    }
}

//imprimir a lista
void imprimir(){
    NO * aux = inicio;
    int i;
    for(i = 0; i < tam; i++){
        printf("%d \n", aux -> valor);
        aux = aux -> prox;
    }
}

int main(){
    add(1,0);
    add(2,1);
    add(3,2);
    add(4,3);
    imprimir();
    del(2);
    printf("apos deletar \n");
    imprimir();
    return 0;
}