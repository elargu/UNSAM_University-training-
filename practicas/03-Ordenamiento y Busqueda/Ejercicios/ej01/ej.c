#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define rangoFA 0
#define rangoFB 1000

void funrandom_float_vec(float v[],float d);
void printar_vector_flotante(float v[],float d);

void porseleccion(float v[], int d);
void pasa_ultimo(float v[], int d);
int posicion_max(float v[], int d);
void intercambia (float * x, float * y);

void porburbuja(float v[], int d);

void porinsercion(float v[], int d);



int main()
 {

    const int dim=20;

    float vec_float[dim];

    //Ordenamiento:
    //a)SELECCION
    funrandom_float_vec(vec_float,dim);
    printar_vector_flotante(vec_float,dim);

    printf("Por SELECCION:\n");
    porseleccion(vec_float,dim);
    printar_vector_flotante(vec_float,dim);

    printf("\n\n#######################################################################################\n\n");

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //B)BURBUJEO
    funrandom_float_vec(vec_float,dim);
    printar_vector_flotante(vec_float,dim);
    printf("Por BURBUJEO:\n");

    porburbuja(vec_float,dim);
    printar_vector_flotante(vec_float,dim);

   printf("\n\n#######################################################################################\n\n");

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //a)INSERCION
    funrandom_float_vec(vec_float,dim);
    printar_vector_flotante(vec_float,dim);
    printf("Por INSERCION:\n");

    porinsercion(vec_float,dim);
    printar_vector_flotante(vec_float,dim);



    system ("pause");

    return 0;

}

//////////////////////////////////////////////////////////////////
/////// Entrega Vector con Numeros Flotantes Aleatorios   ///////
/////////////////////////////////////////////////////////////////
void funrandom_float_vec(float v[],float d)
{
    int i;
    float num;

    srand(time(NULL));

    for(i=0;i<d;i++)
    {
        num=rangoFA+(rand()%rangoFB);
        v[i]=(num/11);
    }

    return;

}


void printar_vector_flotante(float v[],float d)
{
    int i;

    printf("La secuencia de numeros aleatorios flotantes es:\n");

    printf("\n");

    for(i=0;i<d;i++)
    {
        printf("%.2f - ",v[i]);
    }

    printf("\n\n");

    return;
}


///###################################################################################################
//a)SELECCION
void porseleccion(float v[], int d)
{
	int cont;

	for (cont=d;cont>1;cont--)
	{
		pasa_ultimo(v, cont);
	}

}

void pasa_ultimo(float v[], int d)
{

	int p;
	p = posicion_max(v, d);

	if (v[p]!= v[d-1])
	{
		intercambia(&v[d-1], &v[p]);
	}
}

int posicion_max(float v[], int d)
{

	int posv, i;
	float mposv;
	mposv = v[0];
	posv = 0;

	for(i=1;i<d;i++)
	{
		if (v[i]> mposv)
		{
			mposv = v[i];
			posv = i;
		}
	}
	return posv;
}

void intercambia (float * x, float * y)
{
	float n;
	n = *y;
	*y = *x;
	*x = n;
}

///###################################################################################################
//b)BURBUJA

void porburbuja(float v[], int d)
{
	int i, j;
	float aux, cambio;

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

///###################################################################################################
//c)INSERCION


void porinsercion(float v[], int d)
{
	int i, j;
	float aux;

	for (i = 1; i<d; i++)
	{
		aux = v[i];
		j = i-1;

		while ((v[j] > aux) && (j>0))
		{
			v[j+1] = v[j];
			j--;
		}


		if (v[j] <= aux)
		{
			v[j+1] = aux;
		}
		else
		{
			v[1] = v[0];
			v[0] = aux;
		}
	}

	return;

}

