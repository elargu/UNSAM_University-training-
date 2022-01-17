#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void carga(float v[],int d);
void prinvector(float v[],int d);
void xorear(float v[],int d);



int main() {

	int const N=10;
	float vec[N];

	printf("Programa\nVamos a ingresar un arreglo de 10 posisiones, ingrese la posicion de 0 a 9 y un numero flotante para guardarlo ahi\n");

    xorear(vec,N);
	carga(vec,N);
	prinvector(vec,N);

    system ("pause");

    return 0;

}

void xorear(float v[],int d)
{
    int i=0;

    while(i<d)
    {
        v[i]=0;
        i++;
    }

}



void carga(float v[],int d)
{
	int i,flag=0,j,flag2=0;
	float x;

	while(flag==0)
	{
		do
		{
			printf("\nIngrese una posicion -entero- : ");
			scanf("%d",&i);

			if(i>=d)
			{
				printf("Numero fuera de rango\n");
			}
			else
			{
				if((v[i])==0)
				{
					flag2=1;
                    printf("Ingrese un numero flotante para guardarlo en el Array: ");
                    scanf("%f",&x);

                    v[i]=x;
				}
				else
				{
					printf("La posision esta ocupada, intente de nuevo\n");
					printf("num = %.f",v[i]);
				}


			}
		}
		while(flag2=0);

		flag2=0;

		flag=1;
		j=0;
		while(j<d)
		{

			if(v[j]==0)
			{
				flag=0;
			}

			j++;

		}

	}


}


void prinvector(float v[],int d)
{
	int i=0;

	printf("El arreglo quedo configurado como:\n");

	while(i<d)
	{

		printf("Pos.= %d , Num. = %.2f\n",i,v[i]);

        i++;
	}
}
