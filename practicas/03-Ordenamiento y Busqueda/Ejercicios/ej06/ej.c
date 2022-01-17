#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string.h>
#include <time.h>
#define rangoIA 0
#define rangoIB 20

void modal(int v[],int dim);
void funrandom_int_vec(int v[],int d);
void printar_vector_entero(int v[],int d);
int secuencial(int v[],int d,int keyf);
void porburbuja(int v[], int d);
void respuesta(int ky, int resul);

int main() {

    //const int dim=10;
    //int vec_int[dim];
    int keyb,resbusq;

    const int dim = 15;
    int vec_int[]={72,72,72,75,75,75,78,82,82,82,82,85,85,85,89};

    //funrandom_int_vec(vec_int,dim);
    printar_vector_entero(vec_int,dim);
    printf("Ingrese un numero entero para buscar en la lista\n");
    scanf("%d",&keyb);

    resbusq=secuencial(vec_int,dim,keyb);
    respuesta(keyb,resbusq);
    printf("\n");


    printf("Ordenado por burbuja\n");
    porburbuja(vec_int,dim);
    printar_vector_entero(vec_int,dim);
    printf("\n");

    modal(vec_int,dim);


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


void modal(int v[],int dim)
{
    int i=0,cont1=1,cont2=0,modas,flag;

    for(i=1;i<dim;i++)
    {
        if(v[i-1]=v[i])
        {
            cont1++;
        }
        {
            if(cont1>cont2)
            {
                cont2=cont1;
                modas=v[i-1];
                cont1=1;
            }
            else
            {
                cont1=1;
            }

        }
    }

    if(cont2==1)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }


    if(flag==1)
    {
        printf("No hay Moda\n");
    }
    else
    {
        printf("La moda es: %d\n",modas);
    }

    return;
}

////////////////////////////////////////////
//SECUENCIAL
int secuencial(int v[],int d,int keyf)
{
	int i=0, flag=-1;

	while((i<d)&&(flag<0))
	{
		if(v[i]==keyf)
		{
			flag=i;
		}

		i++;
	}


	return flag;

}


void respuesta(int ky, int resul)
{

	if ( resul != -1 )
	{
      printf( "\n%d se encuentra en la posicion %d del arreglo\n", ky, resul );
	}
	else
	{
      printf( "\n%d no se encuentra\n", ky );
	}

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
