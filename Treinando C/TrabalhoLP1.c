#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char formula[];
    scanf("%s",formula);
    printf("Subformulas:\n");
    printf("%s\n",formula);
    for(int i = 0; formula[i] != '\0'; i++){        
        if(formula[i] == 'p' || 'q' || 'r'){
            printf("%s\n",&formula[i]);
        }
    }
    return 0;
}