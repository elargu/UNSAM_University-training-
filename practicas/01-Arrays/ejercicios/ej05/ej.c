#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int impares (int * v, int tam);

int main() {

    const int dim=10;
    int array[]={48,29,58,57,79,36,05,80,96,56},con_par;

    con_par=impares(&array[0],dim);

    printf("Pares = %d\n",con_par);

    system ("pause");

    return 0;

}


int impares (int * v, int tam)
{
    int i=0, cont=0;

    while(i<tam)
    {
        if((*(v+i)%2)==0)
        {
            cont++;
        }

        i++;
    }

    return cont;
}
