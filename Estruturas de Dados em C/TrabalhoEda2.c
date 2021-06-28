//Nome: Cícero Romão Ribeiro Pereira Filho
//Matricula: 411674
#include <stdio.h>
#include <stdlib.h>

//defini as cores como 0 e 1 facilita na contagem e gosto de trabalhar com elas dessa forma;
#define negro = 1;
#define rubro = 0;

typedef struct no{
    int dados;
    int cor; // N para Negro e R para Rubro.
    struct no *pai;
    struct no *direita;
    struct no *esquerda;
}NO;

NO * raiz = NULL;

//Funções
NO alocacao_no(int dados){
    NO * NO_pont;
	NO_pont = malloc(sizeof(NO));
	NO_pont->esquerda = NULL;
	NO_pont->direita = NULL;
	NO_pont->dados = dados;
    NO_pont->pai = NULL;

return NO_pont;
}

void mover_pai(NO * removido, NO * filho){
    filho->pai = removido->pai;
}

void organizar(NO * no_solto, NO * novo_no_pai){ /* durante o remover essa func vai organizar o nó que fica solto ela vai percorrer o nó que toma o lugar do que foi removido e vai checar onde deve inserir o nó solto*/

}

void colorir(NO * raiz){
    if(raiz->cor == negro){
        if(raiz->direita != NULL && raiz->esquerda != NULL){
            raiz->direita = rubro;
            raiz->esquerda = rubro;
            colorir(raiz->direita);
            colorir(raiz->esquerda);    
        }else if(raiz->direita != NULL){
            raiz->direita = rubro;
            colorir(raiz->direita);
        }else if(raiz->esquerda != NULL){
            raiz->esquerda = rubro;
            colorir(raiz->esquerda);
            }
    }else{
        if(raiz->direita != NULL && raiz->esquerda != NULL){
            raiz->direita = negro;
            raiz->esquerda = negro;
            colorir(raiz->direita);
            colorir(raiz->esquerda);    
        }else if(raiz->direita != NULL){
            raiz->direita = negro;
            colorir(raiz->direita);
        }else{
            if(raiz->esquerda != NULL){
                raiz->esquerda = negro;
                colorir(raiz->esquerda);
            }
        }
    }
}

void inserir(NO * raiz, int dados){
    if(raiz == NULL){
        raiz = alocacao_no(dados);
        raiz->cor = negro;
    }else{
        if(dados < raiz->dados){
            if(raiz->esquerda == NULL){
                raiz->esquerda = alocacao_no(dados);
                raiz->esquerda->pai = raiz;
            }else{
                inserir(raiz->esquerda, dados);
            }
        }else if(dados > raiz->dados){
            if(raiz->direita == NULL){
                raiz->direita = alocacao_no(dados);
                raiz->direita->pai = raiz;
            }else{
                inserir(raiz->direita, dados);
            }
        }
    }
    colorir(raiz);
}


void remover(NO * raiz,int valor){
    if(raiz->esquerda->dados == valor){
        if(raiz->esquerda->esquerda != NULL && raiz->esquerda->direita != NULL){
            raiz->esquerda = raiz->esquerda->direita;
            mover_pai(raiz->esquerda, raiz->esquerda->direita);
            organizar(raiz->esquerda->esquerda, raiz->esquerda->direita);
        }else if(raiz->esquerda->esquerda != NULL){
            raiz->esquerda = raiz->esquerda->esquerda;
            mover_pai(raiz->esquerda, raiz->esquerda->esquerda);
        }else if(raiz->esquerda->direita != NULL){
            raiz->esquerda = raiz->esquerda->direita;
            mover_pai(raiz->esquerda,raiz->esquerda->direita);
        }
    }else if(raiz->direita == valor){
        if(raiz->esquerda->esquerda != NULL && raiz->esquerda->direita != NULL){
            raiz->esquerda = raiz->esquerda->direita;
            mover_pai(raiz->esquerda, raiz->esquerda->direita);
            organizar(raiz->esquerda->esquerda, raiz->esquerda->direita);
        }else if(raiz->esquerda->esquerda != NULL){
            raiz->esquerda = raiz->esquerda->esquerda;
            mover_pai(raiz->esquerda, raiz->esquerda->esquerda);
        }else if(raiz->esquerda->direita != NULL){
            raiz->esquerda = raiz->esquerda->direita;
            mover_pai(raiz->esquerda,raiz->esquerda->direita);
        }        
    }
}

int auxilia_a_verificar(NO * raiz){//corrigir isso aqui
    int dir;
    int esq;
    if(raiz->direita->cor == negro){
        dir = 1 + auxilia_a_verificar(raiz->direita);
    }
    if(raiz->esquerda->cor == negro){
       esq = 1 + auxilia_a_verificar(raiz->esquerda);
    }
    
return dir,esq;
}

void verifica(NO * raiz){//verifica se é uma arvore rubro negra
    
}

int contador(NO * raiz, int retorno){
    if(raiz->direita != NULL && raiz->esquerda != NULL){
        retorno = 1 + contador(raiz->direita) + contador(raiz->esquerda);
    }else if(raiz->direita != NULL){
        retorno = 1 + contador(raiz->direita);
    }else if(raiz->esquerda != NULL){
        retorno = 1 + contador(raiz->esquerda);
    }
return retorno;
}

int main(){
    int escolha;
    int valor;
    for( ; ; ){
    printf("Escola a operação a ser realizada:\n");
    printf("1-Inserir\n2-remover\n3-imprimir\n4-contar quantidade de nós\n5-encerrar programa\n");
    scanf("%d",&escolha);
        switch (escolha){
        case 1
            printf("Informe o valor a ser inserido\n");
            scanf("%d",&valor);
            inserir(raiz,valor);
        case 2
            printf("Informo o valor a ser removido\n");
            scanf("%d",&valor);
            remover(raiz,valor);
        case 3
            imprimir(raiz);
        case 4
            contador(raiz);
        case 5
            printf("Encerrando programa..\n.........\n");
            break;
        }
    }
    return 0;
}