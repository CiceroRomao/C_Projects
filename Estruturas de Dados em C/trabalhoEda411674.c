/*
Nome:Cícero Romão Ribeiro Pereira Filho
Matricula:411674
*/
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
int cont = 0;
//toração profunda da esquerda
AVL* rotacionar_esquerda_esquerda (AVL* arv){
	AVL* tmp = arv;
	AVL* esquerda_aux = tmp->esquerda;

	tmp->esquerda = esquerda_aux->direita;
	esquerda_aux->direita = tmp;

	return esquerda_aux;
}


//rotação para esquerda menos profunda
AVL* rotacionar_esquerda_direita (AVL* arv){
	AVL* tmp = arv;
	AVL* esquerda_aux = tmp->esquerda;
	AVL* direita_aux = esquerda_aux->direita;

	tmp->esquerda = direita_aux->direita;
	esquerda_aux->direita = direita_aux->esquerda;
	direita_aux->esquerda = esquerda_aux;
	direita_aux->direita = tmp;

	return direita_aux;
}

//rotação a direita menos profunda
AVL* rotacionar_direita_esquerda(AVL* arv){
	AVL* tmp = arv;
	AVL* direita_aux = tmp->direita;
	AVL* esquerda_aux = direita_aux->esquerda;

	tmp->direita = esquerda_aux->esquerda;
	direita_aux->esquerda = esquerda_aux->direita;
	esquerda_aux->direita = direita_aux;
	esquerda_aux->esquerda = tmp;

	return esquerda_aux;
}

//rotação para a direita mais profunda
AVL* rotacionar_direita_direita (AVL* arv){
	AVL* tmp = arv;
	AVL* direita_aux = tmp->direita;

	tmp->direita = direita_aux->esquerda;
	direita_aux->esquerda = tmp;

	return direita_aux;
}

int max(int x, int y) {//maior dos dois ves
    if (x>y){
        return x;
    }else{
        return y;
    }
}

//Calcula a altura
int altura(AVL * arv){
	int altura_esquerda = 0;
	int altura_direita = 0;
	if (arv->esquerda)
		altura_esquerda = altura(arv->esquerda);

	if (arv->direita)
		altura_direita = altura(arv->direita);

	return max(altura_direita, altura_esquerda)+1;
}

//Calcula o fatball usando altura
int fatbal(AVL* arv){
	int fat = 0;
	if(arv->esquerda)
	    fat += altura(arv->esquerda);

	if(arv->direita)
		fat -= altura(arv->direita);

	return fat;
}

//Func para balancear a AVL com base em qual rotação pe necessaria para cada caso
AVL* Balancear_NO (AVL* arv){
	AVL* NO_aux = NULL;
	if( arv->esquerda)
		arv->esquerda = Balancear_NO(arv->esquerda);

	if (arv->direita)
		arv->direita = Balancear_NO(arv->direita);

	int fat = fatbal(arv);

	if(fat >= 2){
		//pesando pra esquerda
		if (fatbal(arv->esquerda) <= -1){
			NO_aux = rotacionar_esquerda_direita(arv);
        }else{
			NO_aux = rotacionar_esquerda_esquerda(arv);
        }
	}
	else if (fat <= -2){
		//pesando pra direita 
		if(fatbal(arv->direita) >= 1 ){
			NO_aux = rotacionar_direita_esquerda(arv);
        }else{
			NO_aux = rotacionar_direita_direita(arv);
        }
	}
	else{
		NO_aux = arv;
	}
	return NO_aux;
}

//Func para balancear a AVL
void Balancear_AVL(AVL* arv){
	AVL* nova_raiz = NULL;
	nova_raiz = Balancear_NO(raiz);
	if(nova_raiz != raiz){
		raiz = nova_raiz;
	}
}

AVL* cria_NO(int v){
	AVL* no;
	no = malloc(sizeof(AVL));
	no->esquerda = NULL;
	no->direita = NULL;
	no->dados = v;

	return no;
}

//Func para inserir os nós na AVL

void inserir_arv(AVL* arv, int valor){
	if(arv == NULL){
		AVL* NO = cria_NO(valor);
		arv = NO;
	}else{
		if(valor < arv->dados){
			inserir_arv(arv->esquerda, valor);
		}else if(valor > arv->dados){
			inserir_arv(arv->direita, valor);
		}
	}
}
void inserir(int valor){
	inserir_arv(raiz, valor);
	Balancear_AVL(raiz);

}
/*
void inserir_arvss(AVL** arv, int v){
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
*/
/*
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
*/
void remover_arv(AVL* arv, int valor){
	if(arv->dados == valor){
		arv = NULL;
		Balancear_AVL(arv);
	}else{
		if(valor < arv->dados){
			remover_arv(arv->esquerda, valor);
		}else if (valor > arv->dados){
			remover_arv(arv->direita, valor);
		}
	}
}
void remover(int valor){
	remover_arv(raiz->direita, valor);
	remover_arv(raiz->esquerda, valor);
}

AVL* verificaAVL(AVL* arv){// Func para verificar se a Arvore é AVL
    if(arv->altura < -1 && arv->altura > 1){
        printf("Não é avl\n");
        return 0;
    }else{
        verificaAVL(arv->direita);
        verificaAVL(arv->esquerda);
    }
}

int contador(AVL* arv){ //Func para contar a quantidade de nós na árvore apartir do nó raiz
    if(arv != NULL){
        return 1 + (contador(arv->direita)) + (contador(arv->esquerda));
    }else{
        return 0;
    }
}

void imprimir(AVL* arv){//Func para imprimir as AVL's
    if (arv != NULL) {
        printf("No = %d, altura = %d, FATBAL = %d\n", arv->dados, arv->altura, arv->fatbal);
        imprimir(arv->esquerda);
        imprimir(arv->direita);
    }
}

// COLOCAR RESTANTE DAS OPÇÕES COMO CONTADOR E VERIFICAR AVL
int main(){
    int op;
    int v;
    for( ; ; ){
        int op;//v referente a operação a ser realizada
        printf("Escolha a operação a ser realizada:\n 1 - Inserir\n 2 - Imprimir AVL\n 3 - Remover Nó\n 4 - Sair\n");
        scanf("%d",&op);
        if(op == 1){
            printf("Informe os dados:\n");
            scanf("%d", &v);
            inserir(&raiz, v);
        }else if(op == 2){
            if(raiz == NULL){
                printf("\n| Arvore vazia!\n\n");
            } else {
                printf("\n");
                imprimir(raiz);
                printf("\n\n");
            }
        }else if(op == 3){        
                printf("Informe o nó a ser removido\n");
                //implementar o restante com base na func remover
                //definir os dados necessarios para remover o nó da AVL
        }else if(op == 4){
            printf("Programa encerrado\n");
            break;      
        }else{
            printf("Opção INVALIDA!!!\n");
            main();
        }
    }
    return 0;
}

