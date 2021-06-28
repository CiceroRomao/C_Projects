#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
/*sem_t a;
void main(){
    Sem_init(a,0);
    sem_wait(&a);
    sem_post(&a);
}
*/
#define n_clientes 5;
int pacote, i;
int controle = 0;
void up(int controle){
    controle ++;
    if(controle <= 0){
        Sleep();
    }
}
void down(int controle){
    controle --;
    if(controle < 0){
        wakeup();
    }
}
void recepcao(int pacote){
    printf("Recepção:Atendendo cliente %d pedido %d",i ,pacote);
    up(controle);

}
void servidor(int i){
    printf("SERVIDOR:Atendendo cliente %d",i);


}
void c_thread(){
    
}
int main(){
   printf("SERVIDOR: aguardando pedido");
   scanf("%d",&pacote);
   recepcao(pacote); 


    
    return 0;
}  


/*
pthread_t threads[n_clientes];
    int i, arg[n_clientes];     
    
    for(i=0; i<n_clientes; i++){
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);         
    }
    for(i=0; i<n_clientes; i++)
        pthread_join (threads[i], NULL);
        printf("\n");
     
*/