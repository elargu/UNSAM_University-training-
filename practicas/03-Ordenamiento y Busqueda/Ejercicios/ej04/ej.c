#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define rangoIA 0
#define rangoIB 20

void funrandom_int_vec(int v[],int d);
void printar_vector_entero(int v[],int d);
int bbinaria( const int v[], int keyb, int bajo, int alto, int d );
int mayordelista(int v[],int dim);
void porburbuja(int v[], int d);

int main() {

    const int dim=10;
    int vec_int[dim];
    int vecesmaximo,lugar;

    funrandom_int_vec(vec_int,dim);
    printar_vector_entero(vec_int,dim);
    printf("\n");

    porburbuja(vec_int,dim);
    printar_vector_entero(vec_int,dim);
    printf("\n");

    vecesmaximo=mayordelista(vec_int,dim);
    printf("El mayor aparece: %d\n",vecesmaximo);


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


int mayordelista(int v[],int dim)
{
    int i,cont=0,mayor=0;

    for(i=0;i<dim;i++)
    {
        if(v[i]>mayor)
        {
            mayor=v[i];
        }

    }

    printf("mayor %d\n",mayor);

    for(i=0;i<dim;i++)
    {
        if(v[i]==mayor)
        {
            cont++;
        }

    }

    return cont;

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

