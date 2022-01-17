#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//a) ¿Cuál es el valor de x?
//a. 1, 2, 3 ó 4?

//Rta=1

//b) ¿Cual es el valor de array[1]?
//a. 2, 4, 6 ú 8?

//Rta=8

int main() {

    int array[] = {1,2,3,4,5,6};
    int i;

    printf("\narray: ");
    for(i=0;i<6;i++)
    {
        printf("%d-", array[i]);
    }

    printf("\n");

    int *puntero, x;
    puntero = array;
    puntero++;                  //puntero queda en 1, tiene el 2
    *puntero = *puntero + 6;   //guardo en la posicion 1 el 6+2=8
    puntero = puntero + 3;      //puntero se mueve a posiion 4
    puntero = puntero-puntero[-2];    // en posicion 4 p=5, p[-2]=3 == 4-3=1 me muevo a posicion 1
    x = puntero - array;            // puntero esta en posicion 1 p=2, array esta en posicion 0


    printf("puntero %d\n",*puntero);
    printf("Array %d\n",*array);
    printf("%d\n",x); //posicion 1 + posicion 0 = posicion 1

    for(i=0;i<6;i++)
    {
        printf("\npos = %d ||  num = %d", i, array[i]);
    }





    system ("pause");

    return 0;

}
