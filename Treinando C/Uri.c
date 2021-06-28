#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){ 
    double raio;
    float pi = 3.14159;
    float area;
    scanf("%lf",&raio);
    area = pi*(raio*raio);
    printf("A=%.4f\n",area);
    return 0;
}