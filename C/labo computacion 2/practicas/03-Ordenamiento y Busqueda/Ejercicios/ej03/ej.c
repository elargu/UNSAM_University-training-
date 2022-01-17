#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int secuencial(int v[],int dim,int key);
int bbinaria( const int v[], int keyb, int bajo, int alto, int d );
void respuesta(int ky, int resul);

int main() {

    const int dim=15;
    int vec[]={1,4,5,12,25,27,31,4,43,56,73,76,78,80,99};
    int keyb=27,resultado;


    //a) Búsqueda secuencial.
    resultado=secuencial(vec,dim,keyb);
    respuesta(keyb,resultado);

    //b) Búsqueda binaria
    resultado=bbinaria(vec,keyb,0,14,dim);
    respuesta(keyb,resultado);

    system ("pause");

    return 0;

}


////////////////////////////////////////////
//SECUENCIAL
int secuencial(int v[],int dim,int key)
{
	int i=0, flag=-1;

	while((i<dim)&&(flag<0))
	{
		if(v[i]==key)
		{
			flag=i;
		}

		i++;
	}

	return flag;

}

//////////////////////////////////////
//BUSQUEDA BINARIA


int bbinaria( const int v[], int keyb, int bajo, int alto, int d )
{
   int central, flag;

   while ( bajo <= alto )
   {
		central=( bajo+alto )/2;

		if ( keyb == v[ central ] )
		{
		    flag=central;
		}
		else if ( keyb < v[ central ] )
		{
			alto = central - 1;
		}
		else
		{
			bajo = central + 1;
		}
   }

    flag=central;

    return flag;

}

/////////////////////////////////////////////////////////////////////////////////

///PRINT


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
