#include <stdio.h>
#include <stdlib.h>

int pilha[6];
int tam = 0;

void add(int valor){  //adicionar no final
    if(tam < 6){
        pilha[tam] = valor;
        tam++;
    }
}

int del(){ // deleta no final 
    pilha[tam] = 0;
    tam--;
}
void print(){ //mostra a pilha
    for(int i = 0; i < tam; i++){
        printf("%d \n", pilha[i]);
    }
}

int main(){
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    print();
    printf("apaga \n");
    del();
    print();
}