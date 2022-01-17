#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double * max (double * v, int tam);;

int main() {

    const int dim=10;
    //double arr[]={0,0,0,0,0,0,0,0,0,0},maximo;
    double arr[]={4,10,330,992,40,13,98,5,10,10000};


    printf("el mayor es = %f\n", *max(arr,dim));


    system ("pause");

    return 0;

}


double * max (double * v, int tam)
{
    int i=0;
    double maxim = 0, *p;


    for(i=0;i<tam;i++)
    {

        if(v[i]> maxim)
        {
            maxim=v[i];
            p=(v+i);
        }

    }

    printf("%fd",maxim);
    if(maxim==0)
    {
        p= NULL;
    }


    return p;
}
