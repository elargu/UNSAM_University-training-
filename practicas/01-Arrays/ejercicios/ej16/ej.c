#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu(int v[],int d);
void lectura(int *p);
void printarv(int v[],int dim);
void xoreador(int v[],int d);
void buscar(int v[],int dim,int num);
int cambio(int v[],int dim,int num);


int main() {

    const int N=11;
    int vec[]={29,31,32,33,35,36,37,38,39,40,0};
    int num;

    //num=34; //el que hay que correr la lista
    //num=32; //el que ya esta y no hay que hacer nada

    num=menu(vec,N);

    system ("pause");

    return 0;

}

int menu(int v[],int d)
{
    int n,num;

    printf("Programa \n");
    printf("Vamos a buscar un numero en el Array:\n");
    printf("Ingrese una opcion:\n");
    printf("#1 Buscar\n");
    printf("#2 ver el array cargado\n");
    printf("#3 salir\n");

    do
    {
        lectura(&n);
        if((n<1)||(n>3))
        {
            printf("No existe esa opcion!");
        }
    }
    while((n<1)||(n>3));

    switch(n)
	{
		case 1:
            lectura(&num);
            buscar(v,d,num);
            break;
        case 2:
            printarv(v,d);
            break;
        case 3:
            break;
	}

	return num;
}

void lectura(int *p)
{
    int nume;


        printf("Ingrese un numero\n");
        scanf("%d",&nume);

    *p=nume;

    return;

}


void buscar(int v[],int dim,int num)
{
    int i,flag=0,newpos;

    for(i=0;i<dim;i++)
    {
        if(v[i]==num)
        {
            printf("La posicion del numero %d buscado es array=%d, en cristiano=%d\n",num,i,i+1);
            flag=1;
        }
    }

    if(flag==0)
    {
        newpos=cambio(v,dim,num);

        printf("No esta, La nuevo posicion del numero %d : array = %d, critiano= %d\n",num,newpos,(newpos+1));

        printarv(v,dim);
    }

}

int cambio(int v[],int dim,int num)
{
    int i,posm,aux,aux2,aux3,reto;

    for(i=0;i<dim;i++)
    {
        if((num>v[i])&&(v[i]!=0))
        {
            posm=i;
        }
    }

    reto=posm+1;
    aux=v[posm+1];
    v[posm+1]=num;

    aux2=aux;
    aux=v[posm+2];
    v[posm+2]=aux2;

    for(i=(posm+3);i<dim;i++)
    {

        if(i!=(dim))
        {
            aux2=v[i];
            v[i]=aux;
        }

        aux3=aux;
        aux=aux2;
        aux2=aux3;

    }






    return reto;

}


void xoreador(int v[],int d)
{
    int i;

    for(i=0;i<d;i++)
    {
        v[i]=0;
    }
}

void printarv(int v[],int dim)
{
	int i;

	printf("El vector es\n");

	for(i=0;i<dim;i++)
	{
		printf("%d-",v[i]);
	}

	printf("\n");

	return;

}
