#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int v[5];       //declaro vector
    int *p,i;       //declaro puntero y variable

    p = &v[0];      //asigno la primera posiion del vecctor al puntero
    *p = 1;         //lleno cada posision del vector con el puntero
    *(p+1) = 2;
    *(p+2) = 3;
    *(p+3) = 8;
    *(p+4) = 7;

    //recorro el arreglo para imprimir los numeros guardados
    for(i=0;i<5;i++)
    {
        printf("%d\n",*(p+i));
    }


    system ("pause");

    return 0;

}
