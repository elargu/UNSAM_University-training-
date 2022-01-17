#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int x[3], *puntero,i;      //declaro arreglo y puntero
    x[0]=10;                 //a cada arreglo le asigno un numero entero
    x[1]=20;
    x[2]=30;
    puntero = x;            //le paso la direccion del primero arreglo al puntero para poder recorrerlo con el mismo

    for(i=0;i<3;i++)
    {
        printf("Contenido puntero x[%d] = %d",i,x[i]);
        printf(",  Direccion puntero x[%d] = %x\n",i,&(x[i]));
    }

    printf("\n");

    printf("%p\n",puntero); //imprimo el contenido de puntero que es la direccion del arreglo 0
    puntero = &x[0];        //le asigno la direccion del arreglo 0
    printf("%p\n",puntero);            //vuelvoa imprimir el contenido de puntero, sigue siendo el arreglo 0
    printf("%d\n",puntero[0]);       //imprimo el contenido del arreglo 0 , un 10
    printf("%d\n",*puntero);         //imprimo lo mismo pero cun un puntero, arreglo 0, un 10
    printf("%X\n",&puntero);         //imprimio la direccion del puntero, donde esta en memoria pero el puntero en si, no a donde apunta
    printf("%X\n",&puntero[1]);      //ahora muestro la direccion de arrglo 1
    printf("%d\n",puntero[1]);       //ahora muestro el contenido del arreglo 1; 20
    printf("%d\n",*(puntero+1));       //lo mismo, muestro el contenido del arrelgo 1, 20
    printf("%d\n",*(puntero+2));       //ahora es del dos, 30



    system ("pause");

    return 0;

}
