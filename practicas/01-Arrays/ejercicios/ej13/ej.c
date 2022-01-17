#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int B[] = {3,4,1,2,7,12,-4},i;                //declaro el vector
    float f = 4.234, *ptf;                      //declaro variable y puntero
    *(B+3) = *B + 15;                           //al B[3] = 3+15 = 18
    ptf = &f;                                   //al puntero le asigno la direccion de f
    *B = (int)(*ptf);                           //apunto al primer arreglo B[0]= 4
    f = *ptf + 20;                              //f= 4,234 + 20 = 24,234
    *(B + 5) = (int)(*ptf); // que emite por pantalla B[], f, ptf? //B[5]=24

    //B[]={4,4,1,18,7,24,-4}
    //f=24,234
    //ptf=direccion de f, *ptf=f

    printf("\n");
    printf("puntero: B[] = {");

    for(i=0;i<7;i++)
    {
        printf("%d",B[i]);
        if(i<7-1)
        {
            printf(",");
        }
    }

    printf("}\n");
    printf("\n");

    printf("# f= %.3f\n",f);
    printf("# direccion de f= %x\n",&f);
    printf("# ptr=%x\n",ptf);
    printf("# *ptr=%.3f\n",*ptf);

    printf("\n");

    system ("pause");

    return 0;

}
