#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cargavec(float *v,int dim);
void sumavec(float *v,int dim,float *sumando);
void printarvec(float *v,int dim);
void printarsuma(float *res);


int main() {

    const int dim=10;
    float vec[dim],suma=0;


    printf("#############  Programa para rellenar un vector:  ##############\n\n");

    cargavec(&vec,dim);
    sumavec(&vec,dim,&suma);
    printarvec(&vec,dim);
    printarsuma(&suma);


    system ("pause");

    return 0;

}

void cargavec(float *v,int dim)
{
    int i=0;
    float dato;

    printf("Ingrese los datos y cuando finalize los sumaremos entre si\n\n");

    while(i<dim)
    {
        printf("Ingrese un numero %d\n",i+1);
        scanf("%f",&dato);
        *v=dato;
        *v++;
        i++;
    }

    return;

}

void sumavec(float *v,int dim, float *sumando)
{
    int i=0;

    while(i<dim)
    {
        (*sumando)=(*sumando)+ (*v);
        *v++;
        i++;
    }

    return;
}


void printarvec(float *v,int dim)
{
    int i=0;

    printf("\n");

    while(i<dim)
    {
        printf("Pos = %d  ||  Num = %.2f\n",i,*v);
        *v++;
        i++;
    }

    return;
}

void printarsuma(float *res)
{
    printf("SUMA = %.2f",*res);

    return;
}
