#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
###################################################################################################################################
# PRODUÇOES 2 HOMENS E MEIO
# EQUIPE :
# 1 - Gabriel Silveira Trentini
#       Matricula: 404497
# 2 - Cíero Romão Ribeiro]
#       Matricula: 411674
###################################################################################################################################

*/

//OBS: COLOCAR "BIBLIOTECAS" E AS FUNÇÕES EM ARQUIVOS.H PARA O CÓDIGO FICAR MAIS LIMPO;

/*
strstr = confere se uma string está contida na outra e da como retorno um ponteiro para a posição;
strlen = retorna o tamanho da string;
strtok = (string1,'limitador') retorna tudo antes do limitador; exemplo--> string = strtok(stringA, ';'), considerando stringA =="p=a;" retorno string = "p=a"
strcpy = copia uma string pra outra, e é fresco que nem um cu deu erro sem motivo essa porra.
*/

//variaveis globais para ajudar
//Axiomas
/*
>) p>(q>p)
>) (p>(q>r))>((p>q)>(p>r))
(∧1) p>(q>(p ∧ q))
(∧2) (p ∧ q)>p
(∧3) (p ∧ q)>q
(∨1) p>(p ∨ q)
(∨2) q>(p ∨ q)
(∨3) (p>r)>((q>r)>((p ∨ q)>r))
(~1) (p>q)>((p>~q)>~p)
(~2) ~p>p
*/

//Biblioteca de siglas
char sigla1[3] = "A1";
char sigla2[3] = "A2";
char sigla3[3] = "A3";
char sigla4[3] = "A4";
char sigla5[3] = "A5";
char sigla6[3] = "A6";
char sigla7[3] = "A7";
char sigla8[3] = "A8";
char sigla9[3] = "A9";
char sigla10[3] = "A10";

//Biblioteca de axiomas
char A1[30] = "(p>(q>p))";
char A2[50] = "(p>(q>r))>((p>q)>(p>r))";
char A3[30] = "p>(q>(p∧q))";
char A4[30] = "(p∧q)>p";
char A5[30] = "(p∧q)>q";
char A6[30] = "p>(p∨q)";
char A7[30] = "q>(p∨q)";
char A8[50] = "(p>r)>((q>r)>((p∨q)>r))";
char A9[30] = "(p>q)>((p>~q)>~p)";
char A10[30] = "~~p>p";

//Função que receber a linha original e os atomos separados e a formula para realizar a trocar e conferir se a linha está correta;
int compara(char atomo_p[],char atomo_q[],char atomo_r[],char axioma[],char linha[],int aux){
    char copia[strlen(linha)];
    strcpy(copia,axioma);
    char p[]="p";
    char q[]="q";
    char r[]="r";
    
    printf("p %s\n",atomo_p);
    printf("q %s\n",atomo_q);
    printf("r %s\n",atomo_r);
    printf("linha %s\n",linha);
    printf("axioma %s \n",axioma);
    
    printf("----------------------\n");
    printf("Resultado:\n");
    printf("Entrada recebida: %s\n",linha);
    
    
    if(atomo_r == NULL){
        char backup[strlen(axioma)+strlen(atomo_p)+strlen(atomo_q)];
        strcpy(backup,copia);
        int aux = 0;
        int aux3 = 0;
        int aux4 = 0;
        int aux5 = 0;//usando
        int contadorr = 0;
        int positt[contadorr];
        
        for(int i = 0; i <strlen(backup); i++){
            if(backup[i] == 'p'){
                contadorr++;
            }
        }
        
        for(int i = 0; i < strlen(backup); i++){
            if(backup[i]  == 'p'){
                positt[aux5] = i;
                aux5++;
            }
        }
        
        for(int i = 0; i < contadorr; i++){
            printf("%d\n",positt[i]);
        }
        //troca p
        for(int i = 0; i < strlen(linha); i++){
            if(copia[i] == 'p'){
                aux = i;
                aux3 = positt[aux4] + 1;
                for(int j = 0; j < strlen(atomo_p); j++){
                    copia[aux] = atomo_p[j];
                    aux++;
                    printf("troca :%s\n",copia);
                }
                aux4++;
                for(int k = aux; k < strlen(linha); k++){
                    copia[k] = backup[aux3];
                    aux3++;
                    printf("ajuste :%s\n",copia);
                }
            }
        }
        printf("dps de trocar o p %s \n", copia);
        aux = 0;
        aux3 = 0;
        aux4 = 0;
        aux5 = 0;//usando
        contadorr = 0;
        positt[contadorr];
        strcpy(backup,copia);// salva as modificações no backup
        printf("copia: %s \n", copia);
        printf("brackup: %s \n", backup);
        
        for(int i = 0; i <strlen(backup); i++){
            if(backup[i] == 'q'){
                contadorr++;
            }
        }
        
        for(int i = 0; i < strlen(backup); i++){
            if(backup[i]  == 'q'){
                positt[aux5] = i;
                aux5++;
            }
        }
        
        for(int i = 0; i < contadorr; i++){
            printf("%d\n",positt[i]);
        }
        
        //troca q
        for(int i = 0; i < strlen(linha); i++){
            if(copia[i] == 'q'){
                aux = i;
                aux3 = positt[aux4] + 1;
                for(int j = 0; j < strlen(atomo_q); j++){
                    copia[aux] = atomo_q[j];
                    aux++;
                    printf("troca :%s\n",copia);
                }
                aux4++;
                for(int k = aux; k < strlen(linha); k++){
                    copia[k] = backup[aux3];
                    aux3++;
                    printf("ajuste :%s\n",copia);
                }
            }
        }
        
        printf("dps de trocar o q %s \n", copia);
        
    }else if(atomo_p != NULL && atomo_q != NULL && atomo_r != NULL){//r != NULL
        char backup[strlen(axioma)+strlen(atomo_p)+strlen(atomo_q)+strlen(atomo_r)];
        //strcpy(backup,copia);
        for(int i = 0; copia[i] != '\0';i++){
            backup[i] = copia[i];
        }
        int aux = 0;
        int aux3 = 0;
        int aux4 = 0;
        int aux5 = 0;//usando
        int contadorr = 0;
        int positt[contadorr];
        
        for(int i = 0; i <strlen(backup); i++){
            if(backup[i] == 'p'){
                contadorr++;
            }
        }
        
        for(int i = 0; i < strlen(backup); i++){
            if(backup[i]  == 'p'){
                positt[aux5] = i;
                aux5++;
            }
        }
        
        for(int i = 0; i < contadorr; i++){
            printf("%d\n",positt[i]);
        }
        //troca p
        for(int i = 0; i < strlen(linha); i++){
            if(copia[i] == 'p'){
                aux = i;
                aux3 = positt[aux4] + 1;
                for(int j = 0; j < strlen(atomo_p); j++){
                    copia[aux] = atomo_p[j];
                    aux++;
                    printf("troca :%s\n",copia);
                }
                aux4++;
                for(int k = aux; k < strlen(linha); k++){
                    copia[k] = backup[aux3];
                    aux3++;
                    printf("ajuste :%s\n",copia);
                }
            }
        }
        printf("dps de trocar o p %s \n", copia);
        aux = 0;
        aux3 = 0;
        aux4 = 0;
        aux5 = 0;//usando
        contadorr = 0;
        positt[contadorr];
        printf("copia A:%s\n",copia);
        printf("backup A:%s\n",backup);
        //strcpy(backup,copia);// salva as modificações no backup
        for(int i = 0; copia[i] != '\0';i++){
            backup[i] = copia[i];
        }
        printf("copia D:%s\n",copia);
        printf("backup D:%s\n",backup);
        
        for(int i = 0; i <strlen(backup); i++){
            if(backup[i] == 'q'){
                contadorr++;
            }
        }
        
        for(int i = 0; i < strlen(backup); i++){
            if(backup[i]  == 'q'){
                positt[aux5] = i;
                aux5++;
            }
        }
        
        for(int i = 0; i < contadorr; i++){
            printf("%d\n",positt[i]);
        }
        
        //troca q
        for(int i = 0; i < strlen(linha); i++){
            if(copia[i] == 'q'){
                aux = i;
                aux3 = positt[aux4] + 1;
                for(int j = 0; j < strlen(atomo_q); j++){
                    copia[aux] = atomo_q[j];
                    aux++;
                    printf("troca :%s\n",copia);
                }
                aux4++;
                for(int k = aux; k < strlen(linha); k++){
                    copia[k] = backup[aux3];
                    aux3++;
                    printf("ajuste :%s\n",copia);
                }
            }
        }
        
        printf("dps de trocar o q %s \n", copia);
        
        printf("copia : %s\n",copia);
        printf("backup : %s\n",backup);
        strcpy(backup,copia);
        printf("copia : %s\n",copia);
        printf("backup : %s\n",backup);
        aux = 0;
        aux3 = 0;
        aux4 = 0;
        aux5 = 0;
        contadorr = 0;
        positt[contadorr];
        
        
        for(int i = 0; i <strlen(backup); i++){
            if(backup[i] == 'r'){
                contadorr++;
            }
        }
        
        for(int i = 0; i < strlen(backup); i++){
            if(backup[i]  == 'r'){
                positt[aux5] = i;
                aux5++;
            }
        }
        
        for(int i = 0; i < contadorr; i++){
            printf("%d\n",positt[i]);
        }
        
        printf("copia : %s\n",copia);
        printf("backup : %s\n",backup);
        //troca r
        for(int i = 0; i < strlen(linha); i++){
            if(copia[i] == 'r'){
                aux = i;
                aux3 = positt[aux4] + 1;
                for(int j = 0; j < strlen(atomo_r); j++){
                    copia[aux] = atomo_r[j];
                    aux++;
                    printf("troca :%s\n",copia);
                }
                aux4++;
                for(int k = aux; k < strlen(linha); k++){
                    copia[k] = backup[aux3];
                    aux3++;
                    printf("ajuste :%s\n",copia);
                }
            }
        }
        
        printf("dps de trocar o r %s \n", copia);
    }
    printf("copia %s\n",copia);
    printf("original %s\n",linha);
    if(strstr(linha,copia)){
        printf("Após analise conseguimos: %s\n",copia);
        printf("----------------------\n");
        return(aux + 1);
    }else{
        return -1;
    }
}


int substitui_atomos(char linha[], char regra[],int retorno){
    //procura oq vem a seguir
    int receberetorno = 0;
    char * auxp = "p=";
    char * auxq = "q=";
    char * auxr = "r=";
    char aux1[strlen(linha)];
    char aux2[strlen(linha)];
    char aux3[strlen(linha)];
    
    char linha_p[strlen(linha)];
    strcpy(linha_p, linha);
    
    char linha_q[strlen(linha)];
    strcpy(linha_q, linha);
    
    char linha_r[strlen(linha)];
    strcpy(linha_r, linha);
    
    //if "p=" estiver na string ele manipula strings até conseguir só o atomo a exemplo "p=a";
    if(strstr(linha_p,auxp)){
        char * atomosp = strstr(linha_p,auxp);
        char * auxif1 = strtok(atomosp, ";");
        auxif1 = strtok(auxif1,"p=");
        strcpy(aux1,auxif1);

        //mesma coisa para "q=";
        if(strstr(linha_q,auxq)){//ta retornando null provavelmente por conta do strstr anterior;
            char * atomosq = strstr(linha_q,auxq);
            char * auxif2 = strtok(atomosq, ";");
            auxif2 = strtok(auxif2, "q=");
            strcpy(aux2,auxif2);
            
            //mesma coisa para "r=";
            if(strstr(linha_r,auxr)){
                char * atomosr = strstr(linha_r,auxr);
                char * auxif3 = strtok(atomosr, ";");
                auxif3 = strtok(auxif3, "r=");
                strcpy(aux3,auxif3);
                //passa p q r
                receberetorno = compara(aux1,aux2,aux3,regra,linha,retorno);
                return(receberetorno);    
            }else{
                //chamar a função passando somente os atomos p e q
                receberetorno = compara(aux1,aux2,NULL,regra,linha,retorno);
                return(receberetorno);
            }
        }else{
            //retornar erro atomos insuficientes ou n declarados de forma correta
            printf("ERRO!!! - Foi encontrado somente o o atomo p na formula, checar se a formula está bem escrita.\n");
            return -1;
        }
    }else{
        //retornar erro atomos insuficientes ou n declarados de forma correta
        printf("ERRO!!! - Nenhum atomo foi encontrado na formula, checar se a formula está bem escrita.\n");
            return -1;
    }
    
}

//Essa função procura uma sigla de axioma na string dada de entrada
int procura_sigla_da_regra(char linha[],int retorno){
    if(strstr(linha,sigla1)){
        int receberetorno = substitui_atomos(linha,A1,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla2)){
        int receberetorno = substitui_atomos(linha,A2,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla3)){
        int receberetorno = substitui_atomos(linha,A3,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla4)){
        int receberetorno = substitui_atomos(linha,A4,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla5)){
        int receberetorno = substitui_atomos(linha,A5,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla6)){
        int receberetorno = substitui_atomos(linha,A6,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla7)){
        int receberetorno = substitui_atomos(linha,A7,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla8)){
        int receberetorno = substitui_atomos(linha,A8,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla9)){
        int receberetorno = substitui_atomos(linha,A9,retorno);
        return(receberetorno);
    }else if(strstr(linha,sigla10)){
        int receberetorno = substitui_atomos(linha,A10,retorno);
        return(receberetorno);
    }else{
        printf("Erro nenhuma sigla encontrada.\n");
    }
}

int aux_mp(int num_linha, int lin1, int lin2){//confere qual o maior dentre os 3;
    if(num_linha > lin1 && num_linha > lin2){
        return 1;
    }else{
        return 0;
    }
}

//essa função vai separar as os numeros das linhas que foram usadas no MP.
int mp(char linha[],int retorno){
    int num_linha = NULL;//numero da linha em que o mp foi feito.
    int lin1 = NULL;
    int lin2 = NULL;
    int confere_retorno = 0;
    
    //atoi converte string para inteiro;
    //isdigit confere se aquele caractere é um digito;
    for(int i = 0; i < strlen(linha); i++){ //percorre a string procurando os números das linhas;
        if(isdigit(linha[i])){
            if(num_linha == NULL && lin1 == NULL && lin2 == NULL){//considerando que o primeiro numero na string vai ser o numero da linha;
                num_linha = atoi(linha[i]);
            }else if(lin1 == NULL && lin2 == NULL){
                lin1 = atoi(linha[i]);
            }else if(lin2 == NULL){
                lin2 = atoi(linha[i]);
            }else{
                printf("ErRRO!!! - mais de duas linhas foram informadas no MP, ou algum atomo invalido foi inserido\n");
                retorno = -1;
            }
        }
    }
    
    if(num_linha == NULL || lin1 == NULL || lin2 == NULL){
        printf("ERRO!!! - Faltou informar alguma linha ou nem uma linha foi informada\n");
        retorno = -1;
    }else{
        confere_retorno = aux_mp(num_linha,lin1,lin2);//chama a função auxiliar do MP;
        if(confere_retorno == 1){
            
            //Confere o MP chamando as linhas e usando strstr;
            
            retorno = 0;
        }else{//no caso de a linha em que o MP está sendo realizado ter uma valor menor que as linhas usadas no MP;
            retorno = -1;
        }
    }
    
    return retorno;
}

//função para conferir se o MP está presente na linha
int confere_MP(char linha[]){
    char mp[] = "MP";
    if(strstr(linha,mp)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int linha = 0;
    int aux = 0;
    for(; ;){
        if(aux == -1 || aux == -2){
            if(aux == -1){
                printf("Erro encontrado na linha: %d", linha);
                break;
            }else if(aux == -2){
                printf("Execução encerrada por um dos dois motivos:\n");
                printf("1-Todas as linhas foram lidas.\n");
                printf("2-Houve quera de linha entre as linhas do arquivo dado de entrada.\n");
                break;
            }                   // 3 (a>a)>((a>a)>((a∨a)>a)) A8 p=a;q=a;r=a;
        }else{                  // 1 ((a>a)>(a>a))>(((a>a)>a)>((a>a)>a)) A2 p=(a>a);q=a;r=a;
            char stringteste[] = "1 ((a>a)>(a>a))>(((a>a)>a)>((a>a)>a)) A2 p=(a>a);q=a;r=a;";//erro na linha 2 da entrada segundo o documento do trabalho q != a e sim q==(a>a)
            int confere = confere_MP(stringteste);
            if(confere == 0){
                aux = procura_sigla_da_regra(stringteste,aux); 
                linha = linha + 1;
                if(aux >= 0){
                    printf("Deu certo\n");
                    break;//só por enquanto já que é só pra uma linha;
                }else{
                    printf("deu errado kk\n");
                }
            }else if(confere == 1){
                //chama função para resolver o MP
                aux = mp(stringteste,aux);//só para inicializar a função dps ajeitar isso aqui
                if(aux == 0){
                    printf("Deu certo o MP\n");
                }else{
                    printf("Deu errado o MP\n");
                }
            }
        }
    }
    return 0;
}

/*

###################################################################################################################################
# PRODUÇOES 2 HOMENS E MEIO
# EQUIPE :
# 1 - Gabriel Silveira Trentini
#       Matricula: 404497
# 2 - Cíero Romão Ribeiro]
#       Matricula: 411674
###################################################################################################################################

*/
