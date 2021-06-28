/*
Componetets:
NOME:Cícero Romão Ribeiro Pereira Filho
MATRÍCULA:411674
NOME:José Victor Miranda Franco
MATRÍCULA:413136
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

//Váriraveis Globais
int pacotes;//recebe o pedido do cliente
int id = 0;//id para cada cliente
int i = 1;//posição a ser lida no vetor
int vet[5];//vetor para armazenar os dados do cliente

//semaforos para controle
sem_t semfo;//faz a thread servidor esperar até um cliente chegar

//thread servidor 
void * servidor(){
    for(;;){
        //printa mensagem inicial e espera ate algum cliente chegar
        printf("SERVIDOR: aguardando pedidos.\n");
        sem_wait(&semfo);
        //apos chegada com cliente printa duas mensagens 
        printf("SERVIDOR:Esperando dados do cliente\n");
        printf("SERVIDOR: Atendendo cliente %d \n",i); //variavel i referente a posição do vetor referente a ordem de chegada 
        sleep(vet[i]); //dorme de acordo com a quantidade de "pacotes" pedida pelo cliente
        printf("CLIENTE %d: Saindo\n",i); 
        i++;//incremente  a posição a ser trabalhada
        if (i == 5){
            for(int j = 0; j <= i; j++){
                vet[j] = 0;
            }
        }    
    }
}

//Thread Cliente
//printa o id do cliente atual e acorda o servidor
void *cliente(){    
    if(id > 5 ){
        printf("CLIENTE %d: Erro: não há vagas.\n", id);
        pthread_exit(* cliente);
        //encerra a thred pois o servidor atingiu o numero maximo de clientes    
    }
    else{
    //cliente printa mensagem e chama o servidor "acorda"
    printf("CLIENTE %d: Esperando servidor me anteder\n",id);
    sem_post(&semfo);
    }
}

//thread RECEPÇÃO
//recebe o pedido dos clientes e cria a thread cliente
void * recepcao(){
    for(;;){
        //fica aguardando a entrada de dados
        scanf("%d", &pacotes);//armazena o pedido na variavel pacotes
        id++;//atualiza o id do cliente
        printf("RECEPÇÃO: Cliente %d chegou e deseja pedido de %d segundos\n", id,pacotes);//printa os dados do cliente
        vet[id] = pacotes;//armazena o pedido do cliente na posição referente ao id
        //cria a thread cliente
        pthread_t cl;
        pthread_create(&cl,NULL,cliente, NULL);       
    }
}

int main(){
    //declara as threads e cria o semaforo utilizado
    pthread_t serv, recep;
    sem_init(&semfo,0,0);
    //cria as threads servidor e recepção
    pthread_create(&serv,NULL,servidor,NULL);    
    pthread_create(&recep,NULL,recepcao,NULL);    
    //aguarda o termino das threads para finalização do codigo
    pthread_join(serv, NULL);
    pthread_join(recep, NULL); 
     
 }