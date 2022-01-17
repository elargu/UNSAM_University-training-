#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5

void mystery (int *, int *);

//DUPLICA EL VECTOR X, CON LOS DATOS DEL ARREGLO Y. x[]={2,6,10,14,18}

int main() {
    int i;
    int x[SIZE] = {2,4,6,8,10};
    int y[SIZE] = {1,3,5,7,9};
    int *xPtr = NULL;
    int *yPtr = NULL;

    mystery (x, y);

    for (i=0; i<SIZE; i++)
        { printf ("%d\t", x[i]); }
    printf ("\n");
    for (i=0; i<SIZE; i++)
        { printf ("%d\t", y[i]); }
    printf ("\n");


    system ("pause");

    return 0;

}


void mystery (int *n1, int *n2)
{
    int i;
    for (i=0; i<SIZE; i++)
    {
        *(n1+i) = 2 * *(n2+i);

    }
}
