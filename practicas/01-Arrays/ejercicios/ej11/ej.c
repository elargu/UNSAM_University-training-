#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printarv(int v[],int d);
void concatenar(int v1[],int v2[],int v3[],int da,int db);
void diferencia(int v1[],int v2[],int d,int *p);
void interseccion(int v3[], int db);

int main() {

    const int dima=5,dimb=10;
    int vec1[]={1,1,3,4,10},vec2[]={95,44,8,21,21},vec3[dimb],dif,intera,interb;

    printf("Vector A:\n");
    printarv(vec1,dima);
    printf("Vector B:\n");
    printarv(vec2,dima);
    concatenar(vec1,vec2,vec3,dima,dimb);
    printf("Vector C concatenado:\n");
    printarv(vec3,dimb);

    diferencia(vec1,vec2,dima,&dif);
    printf("La diferencia entre el Arreglo A-B= %d\n",dif);

    intera=vec1[dima-1];
    interb=vec2[0];
    interseccion(vec3,dimb);
    printf("Interseccion A=%d , Inteseccion B=%d\n",intera,interb);


    system ("pause");

    return 0;

}


void concatenar(int v1[],int v2[],int v3[],int da,int db)
{
    int i,j=0,k=0;

    for(i=0;i<db;i++)
    {
        if(i<5)
        {
            v3[i]=v1[j];
            j++;
        }
        else
        {
            v3[i]=v2[k];
            k++;
        }
    }

    return;
}

void diferencia(int v1[],int v2[],int d,int *p)
{
    int i,j,suma=0,sumb=0;

    for(i=0;i<d;i++)
    {
        suma=suma+v1[i];
    }

    for(j=0;j<d;j++)
    {
        sumb=sumb+v2[j];
    }

    *p=suma-sumb;

    return;
}

void interseccion(int v3[], int db)
{
    int i=0,j=1,flag=0;

    while((flag==0)||(i<db-1))
    {

        if(v3[i]==v3[j])
        {
            printf("se repite = %d\n",v3[i]);
            flag=1;
        }

        i++;
        j++;

    }

    return;
}

void printarv(int v[],int d)
{
    int i;

    for(i=0;i<d;i++)
    {
        printf("%d-",v[i]);
        //printf("v[%d] = %d\n",i,v[i]);
    }

    printf("\n\n");
}
