#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void combinado2(int va[],int vb[], int vc[], int vd[], int da, int db);
void vectorres(int v[],int dim);


int main() {

    const int dima=5,dimb=10;
    int vecA[]={10,22,32,34,35};
    int vecB[]={11,12,22,24,34};
    int vecC[dimb];
    int vecD[dimb];

    xoreador(vecC,dimb);
    xoreador(vecD,dimb);
    combinado2(vecA,vecB,vecC,vecD,dima,dimb);
    vectorres(vecA,dima);
    printf("\n");
    vectorres(vecB,dima);
    printf("\n");
    vectorres(vecC,dimb);
    printf("\n");
    vectorres(vecD,dimb);
    printf("\n");

    system ("pause");

    return 0;

}


void xoreador(int v[],int d)
{
    int i;

    for(i=0;i<d;i++)
    {
        v[i]=0;
    }
}

void combinado2(int va[],int vb[], int vc[], int dv[], int da, int db)
{
    int i,j=0,k=0,flag=0,aux;


    for(i=0;i<da;i++)
    {
        for(j=0;j<da;j++)
        {
            if(va[i]==vb[j])
            {
                vb[j]=0;
            }
        }
    }

    j=0;

    for(i=0;i<db;i++)
    {
        if(i<5)
        {
            vc[i]=va[j];
            j++;
        }
        else
        {
            vc[i]=vb[k];
            k++;
        }
    }

    j=0;
    k=0;

    do
    {
        flag=0;

        for(i=0;i<db;i++)
        {
            if(vc[i]<vc[i+1])
            {
                if((vc[i+1]!=0)&&((i+1)!=db))
                {
                    aux=vc[i];
                    vc[i]=vc[i+1];
                    vc[i+1]=aux;
                    flag=1;
                }
            }
        }

    }
    while(flag==1);


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
