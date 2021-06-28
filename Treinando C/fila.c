#include <stdio.h>
#include <stdlib.h>


int tam = 0;
int fila[6];

void add(int valor){ //adicionar no final
    if(tam < 6){
        fila[tam] = valor;
        tam++;
    }
}

int del(){  //remover no inicio
   int retorno = fila[0];
   for(int i = 0; i < tam-1; i++){
       fila[i] = fila[i + 1];
   }
   tam--; 
}
void imprimir(){
    for(int i = 0 ;i < tam; i++ ){
        printf("%d ",fila[i]);
    }
}

int main(){
    printf("inicio...\n");
    add(10);
    add(2);
    add(1);
    add(17);
    add(9);
    printf("del \n");
    del();
    printf("imprimir \n");
    imprimir();
    printf("\n");

}