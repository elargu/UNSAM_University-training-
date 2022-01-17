#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int v[3] = {10,20,30};
    int *p,i;
    p = v;

    for(i=0;i<3;i++)
    {
        printf("array %d= %d , posicion memoria= %x\n",i,v[i],&v[i]);
    }

    printf("\n");

    (*p)++; printf("a) %d  ,%x\n", *p,p);  //11  Le sumo 1 a la posision 0
    *(p++); printf("b) %d  ,%x\n", *p,p);  //20  Se movio un lugar a la posision 2
    *p++; printf("c) %d  ,%x\n", *p,p);    //30  como ya se habia movido a la posicion 2 ahora se volvio a mover a la 3


    system ("pause");

    return 0;

}
