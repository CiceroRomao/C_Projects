#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("\n");
    scanf("%d",&n);
    printf("\n");
    int vet[n];
    int vet2[n];
    int a;
    for(int i=0; i<n;i++){
        vet[i] = scanf("%d",&a);
    }
    for(int i=0; i<n;i++){
        if(i==1){
            if(vet[i]==0 && vet[i+1]==0){
                vet2[i]=0;
            }
            else if(vet[i]==0 && vet[i+1]==1){
                vet2[i]=1;
            }
            else if(vet[i]==1 && vet[i+1]==1){
                vet2[i]=2;
            }
        }
        else{
            if(vet[i-1]==0 && vet[i]==0 && vet[i+1] == 1){
                vet2[i]=1;
            }
            else if(vet[i-1]==0 && vet[i]==1 && vet[i+1] == 1){
                vet2[i]=2;
            }
            else if(vet[i-1]==1 && vet[i]==0 && vet[i+1] == 1){
                vet2[i]=2;
            }
            else if(vet[i-1]==1 && vet[i]==0 && vet[i+1] == 0){
                vet2[i]=1;
            }
            else if(vet[i-1]==1 && vet[i]==1 && vet[i+1] == 1){
                vet2[i]=3;
            }
            else if(vet[i-1]==0 && vet[i]==0 && vet[i+1] == 0){
                vet2[i]=0;
            }

        }
    }
    for(int k=0; k< n;k++){
        printf("%d \n",vet2[n]);
    }
    
}