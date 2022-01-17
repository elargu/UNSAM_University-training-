#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void concatenar(int v1[],int v2[],int v3[],int da,int db);
void intercalar(int v1[],int v2[],int v3[],int da,int db);
void printarv(int v[],int d);

int main() {

    const int dima=5,dimb=10;
    //int vec1[]={1,2,3,4,5},vec2[]={6,7,8,9,10},vec3[dimb];
    int vec1[]={2,56,7,8,30},vec2[]={7,80,2,4,13},vec3[dimb];

    printf("Vector A:\n");
    printarv(vec1,dima);
    printf("Vector B:\n");
    printarv(vec2,dima);
    concatenar(vec1,vec2,vec3,dima,dimb);
    printf("Vector C concatenado:\n");
    printarv(vec3,dimb);
    intercalar(vec1,vec2,vec3,dima,dimb);
    printf("Vector C intercalado:\n");
    printarv(vec3,dimb);


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

void intercalar(int v1[],int v2[],int v3[],int da,int db)
{
    int i,j=0,k=0;

    for(i=0;i<db;i++)
    {
        if(i%2==0)
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
