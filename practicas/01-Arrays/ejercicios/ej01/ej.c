#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void menu ();
char selectchar();
void carga(int v[],int d);
void suma(int v[],int dim,int *sumando);
int buscamin(int v[],int dim);
void superaprom(int v[],int dim,float pro);
void multiplosi(int v[],int dim);
void maxi(int v[],int dim);
void paresfun(int v[],int dim,int n);
void posparesfun(int v[],int dim,int n);
void contarele(int v[],int dim,int numa,int *contaa);
void contarx(int v[],int dim,int numa,int *contaa);
void invertir(int v[],int dim);
void resultado(int res);
void vectorres(int v[],int dim);





int main()
{
	menu();

    system ("pause");

    return 0;

}


void menu ()
{
    int const dim = 10;
    int vector[dim];
	carga(vector,dim);
    //int vector[10]={33,22,5,33,8,4,5,29,22,4}; debuger
    vectorres(vector,dim);

	int sumar=0,min,n,na,contasa=0;
	float prom;
	char c;

	printf("Del siguiente menu ingrese una opcion:\n\n");

	printf("B# Calcula la suma de los elementos del Vector Anterior\n");
	printf("C# Calcula y emite el minimo del Vector\n");
	printf("D# Calcula y emite el promedio de los valores del vector\n");
	printf("E# Emite los valores de aquellos que superan ese promedio\n");
	printf("F# Emite los valores del vector que son multiplos del ultimo numero ingresado en el mismo\n");
	printf("G# Emite el valor maximo e indica la cantidad de veces que aparecio y el numero de orden en que fue ingresado\n");
	printf("H# Emite los valores que son pares\n");
	printf("I# Emite los valores que estan en posiciones impares\n");
	printf("J# Emite aquellos que estan ubicados en posicion par\n");
	printf("K# Cuenta la cantidad de elementos que se han ingresado hasta encontrar 'a'\n");
	printf("L# Devuelve el numero de apariciones del elemento 'X' en el vector\n");
	printf("M# Inviertelos elementos del vector\n");

	printf("Otra letra para salir\n");
	printf("\n\n");

	c = selectchar();

	switch(c)
	{
		case 'B':
			suma(vector,dim,&sumar);
			resultado(sumar);
			break;
		case 'C':
			min=buscamin(vector,dim);
			resultado(min);
			break;
		case 'D':
			suma(vector,dim,&sumar);
			prom=sumar/(float)dim;
			printf("El promedio es: %.2f\n",prom);
			break;
		case 'E':
			suma(vector,dim,&sumar);
			prom=floor(sumar/(float)dim);
			superaprom(vector,dim,prom);
			break;
		case 'F':
			multiplosi(vector,dim);
			break;
		case 'G':
			maxi(vector,dim);
			break;
		case 'H':
			printf("Los numeros pares son: \n");
			n=0;
			paresfun(vector,dim,n);
			break;
		case 'I':
			printf("Los numeros que estan en posicion impar son: \n");
			n=1;
			posparesfun(vector,dim,n);
			break;
		case 'J':
			printf("Los numeros que estan en posicion par son: \n");
			n=0;
			posparesfun(vector,dim,n);
			break;
		case 'K':
			fflush(stdin);
			printf("ingrese A =");
			scanf("%d",&na);
			fflush(stdin);
			contarele(vector,dim,na,&contasa);
			printf("contador=%d\n",contasa);
			break;
		case 'L':
			fflush(stdin);
			printf("ingrese X =");
			scanf("%d",&na);
			fflush(stdin);
			contarx(vector,dim,na,&contasa);
			printf("contador=%d\n",contasa);
			break;
		case 'M':
			printf("Vector Ingresado:\n");
			vectorres(vector,dim);
			invertir(vector,dim);
			printf("Vector Invertido:\n");
			vectorres(vector,dim);
			break;
		default:
			break;
	}

	return;
}


char selectchar()
{

	char letramin[]={'b','c','d','e','f','g','h','i','j','k','l','m'};
	char letramay[]={'B','C','D','E','F','G','H','I','J','K','L','M'};
	char ch;
	int i;

	fflush(stdin);
	scanf("%c",&ch);
	fflush(stdin);

	for(i=0;i<12;i++)
	{
		if (ch==letramin[i])
		{
			ch=letramay[i];
		}
	}

	return ch;

}


void carga(int v[],int d)
{
	int i;

	printf("Ingrese valores enteros :\n");

	for(i=0;i<d;i++)
	{
		printf("valor %d = ",i);
		scanf("%d",&v[i]);
	}

    printf("\n");

	return;
}


void suma(int v[],int dim,int *sumando)
{
	int i=0;

	while(i<dim)
	{
		*sumando=*sumando+v[i];
		i++;
	}

	return;
}


int buscamin(int v[],int dim)
{
	int min, i=1;
	min = v[0];

	while(i<dim)
	{
		if (min>v[i])
		{
			min=v[i];
		}

		i++;

	}

	return min;

}

void superaprom(int v[],int dim,float pro)
{
	int i,m;
	m=(int)pro;
	printf("Los que son mayores al promedio %d :\n\n",m);

	for(i=0;i<dim;i++)
	{
		if(v[i]>m)
		{

			printf("%d-",v[i]);

		}
	}

	printf("\n");

	return;

}


void multiplosi(int v[],int dim)
{
	int i=0;

	printf("Multiplos del ultimo numero ingresado en el vector: %d\n",v[dim-1]);

	while(i<(dim-1))
	{
		if((v[i])%(v[dim-1]) == 0)
		{

			printf("%d\n",v[i]);

		}

		i++;
	}

	printf("\n");

	return;

}


void maxi(int v[],int dim)
{
	int i, mx, omx, cmx=0;
	mx=v[0];
	omx=0;

	for(i=1;i<dim;i++)
	{
		if(v[i]>(mx))
		{
			mx=v[i];
		}
	}

	printf("Numero maximo = %d\n",mx);
	printf("Numero de orden en que fue ingresado el maximo\n");

	for(i=0;i<dim;i++)
	{
		if(v[i]==mx)
		{
			printf("%d-",i);
			cmx++;
		}
	}

	printf("\nCantidad de veces que aparecio ese numero max = %d\n",cmx);

	return;
}


void paresfun(int v[],int dim,int n)
{
	int i;

	for(i=0;i<dim;i++)
	{
		if(((v[i])% 2 ) == n)
		{

			printf("%d\n",v[i]);

		}

	}

	return;

}


void posparesfun(int v[],int dim,int n)
{
	int i=0;

	if(n==0)
	{
		printf("Numero = %d , Posicion = %d\n",v[i],i);
	}

	for(i=1;i<dim;i++)
	{
		if((i % 2 ) == n)
		{

			printf("Numero = %d , Posicion = %d\n",v[i],i);

		}

	}

	return;

}



void contarele(int v[],int dim,int numa,int *contaa)
{

	int i=0,flag=0;

	while(flag==0)
	{
		if ((v[i])!=numa)
		{
			(*contaa)++;
			i++;
		}
		else
		{
			flag=1;
		}

		if (i==dim-1)
		{
			flag=1;
		}

	}

}



void contarx(int v[],int dim,int numa,int *contaa)
{
	int i=0;

	while(i<dim)
	{
		if ((v[i])==numa)
		{
			(*contaa)++;
		}
		i++;
	}

}



void invertir(int v[],int dim)
{
	int i=0,j,n,auxi;
	j=(dim-1);
	n=floor(dim/2);

	for(i=0;i<n;i++)
	{
		auxi=v[i];
		v[i]=v[j];
		v[j]=auxi;

		j--;

	}

	return;

}



void resultado(int res)
{
	printf("El resultado es %d\n",res);

	return;
}


void vectorres(int v[],int dim)
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



