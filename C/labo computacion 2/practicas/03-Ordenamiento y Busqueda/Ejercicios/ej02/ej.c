#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define rangoIA 0
#define rangoIB 100

void funrandom_int_vec(int v[],int d);
void printar_vector_entero(int v[],int d);
void printar_vector_entero(int v[],int d);
int porburbujachk(int v[], int d);
void porburbuja(int v[], int d);
void orden(int f);

int main() {

    const int dim=20;
    int vec_int[dim],flag=0;

    funrandom_int_vec(vec_int,dim);
    printar_vector_entero(vec_int,dim);
    printf("\n");

    flag=porburbujachk(vec_int,dim);
    orden(flag);

    porburbuja(vec_int,dim);
    printf("Ahora Ordenado!");
    printar_vector_entero(vec_int,dim);
    printf("\n");

    flag=porburbujachk(vec_int,dim);
    orden(flag);







    system ("pause");

    return 0;

}

void funrandom_int_vec(int v[],int d)
{
    int i,num;

    srand(time(NULL));

    for(i=0;i<d;i++)
    {
        v[i]=(rangoIA)+(rand()%rangoIB);
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

int porburbujachk(int v[], int d)
{
	int i, j, aux, cambio,fl=0;

	for(i=0;i<d-1;i++)
	{
		cambio=0;

		for(j=0;j < d-(i+1); j++)
		{
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				cambio = 1;
			}
		}

		if(cambio==1)
        {
            fl=1;
        }

	}


	return fl;

}

void porburbuja(int v[], int d)
{
	int i, j, aux, cambio;

	for(i=0;i<d-1;i++)
	{
		cambio=0;

		for(j=0;j < d-(i+1); j++)
		{
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				cambio = 1;
			}
		}
	}

	return;

}

void orden(int f)
{
    if(f==0)
    {
        printf("Esta Ordenado\n");
    }
    else
    {
        printf("Esta desordenado\n");
    }

    return;
}
