#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

float mediana (int v[], int dim);
void funrandom_int_vec(int v[],int d, int x, int y);
void printar_vector_entero(int v[],int d);

int main() {

    //const int dim[10];
    const int dim=10;
    int vec_int[dim],x,y;
    float medi;

    printf("Ingrese un rango X y Y 'x<n<y'\n");
    scanf("%d",&x);
    scanf("%d",&y);

    funrandom_int_vec(vec_int,dim,x,y);
    printar_vector_entero(vec_int,dim);
    printf("\n");

    medi=mediana(vec_int,dim);
    printf("La mediana es %.2f\n",medi);

    system ("pause");

    return 0;

}

float mediana (int v[], int dim)
{
    int posA, posB, median;

    if(dim%2==0)
    {

        posA=floor(dim/2);
        posB=posA-1;

        median=((float)(v[posA])+(v[posB]))/(float)2;

    }
    else
    {

        median=v[dim/2];

    }

    return median;
}

void funrandom_int_vec(int v[],int d, int x, int y)
{
    int i,num;

    srand(time(NULL));

    for(i=0;i<d;i++)
    {
        v[i]=(x)+(rand()%y);
    }

    return;

}


void printar_vector_entero(int v[],int d)
{
    int i;

    printf("La secuencia de numeros aleatorios enteros es:\n");

    for(i=0;i<d;i++)
    {
        printf("%d\n",v[i]);
    }

    return;
}
