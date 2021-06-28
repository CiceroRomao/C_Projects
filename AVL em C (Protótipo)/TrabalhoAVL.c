//Nome: Cícero Romão Ribeiro Pereira Filho
//Matrícula: 411674

#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int dados;
    int altura;    
    int fatbal;
    struct avl *direita;
    struct avl *esquerda;
}AVL;
AVL * raiz = NULL;


AVL* cria_NO(int v){
	AVL* no;
	no = malloc(sizeof(AVL));
	no->esquerda = NULL;
	no->direita = NULL;
	no->dados = v;

	return no;
}

void Balancear_AVL(AVL* arv){
	AVL* nova_raiz = NULL;
	nova_raiz = Balancear_NO(raiz);
	if(nova_raiz != raiz){
		raiz = nova_raiz;
	}
}


void inserir(AVL** arv, int v){
	AVL* NO = NULL;
	AVL* prox = NULL;
	AVL* ant = NULL;
    if (raiz == NULL){
		NO = cria_NO(v);
		raiz = NO;
	}else{
		prox = raiz;
		while (prox != NULL){
			ant = prox;
			if(v < prox->dados){
				prox = prox->esquerda;
			}else if(v > prox->dados){
				prox = prox->direita;
			}else if(v == prox->dados){
				return;
			}
		}	
        NO = cria_NO(v);
        if ( v < ant->dados )
			ant->esquerda = NO;

		if ( v > ant->dados )
			ant->direita = NO;
	}
    Balancear_AVL(arv);
}


AVL* remover(AVL* arv, int alt, int dds){// func para remover nós da árvore,, OBS: PASSA A RAIZ P/ PERCORRER A AVL TODA
    if(arv->direita->altura == alt && arv->direita->dados == dds){
        arv->direita->altura = NULL;
        arv->direita->dados = NULL;
        arv->direita = arv->direita->direita; 
    }else if(arv->esquerda->altura == alt && arv->esquerda->dados == dds){
        arv->esquerda->altura = NULL;
        arv->esquerda->dados = NULL;
        arv->esquerda = arv->esquerda->esquerda; 
    }else{
        printf("Nó não encontrado! \n\nCoferir os dados do nó e tentar novamente caso \ncontinue sem ser encontrado é provavel que o NÓ não esteja na AVL\n");
    }
}


//Calcula o fatball usando altura
int fatbal(AVL* arv){
	int fatbal = 0;
	if(arv->esquerda)
	    fatbal += altura(arv->esquerda);

	if(arv->direita)
		fatbal -= altura(arv->direita);

	return fatbal;
}


void imprimir(AVL* arv){//Func para imprimir as AVL's
    
}

int main(){
    return 0;
}