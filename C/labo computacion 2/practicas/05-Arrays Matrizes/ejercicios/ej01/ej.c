#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define rangoIA 0
#define rangoIB 1000
#define dimY 5  //dimension fila -
#define dimX 5  //dimension columna |

void carga_matriz(int m[][dimX]);
void emite_matriz(int m[][dimX],char ly[][3],char lx[][3]);

void carga_matriz(int m[][dimX])
{
    int i,j,num=0,k=1,flag;


    for(i=0;i<dimY;i++)
    {

        for(j=0;j<dimX;j++)
        {
            flag=0;

            do
            {
                if(k<50)
                {
                    if(k % 2 == 1)
                    {
                        num=k;
                        flag=1;
                    }
                }

                k++;
            }
            while(flag!=1);

            m[i][j]=num;

        }

    }




    return;
}

void emite_matriz(int m[][dimX],char ly[][3],char lx[][3])
{
    int i,j;

    printf("         |");

    for(i=0;i<5;i++)
    {
        printf(" %s |",lx[i]);
    }

    printf("\n");

    for(i=0;i<dimY;i++)
    {
        printf("   %s    |",ly[i]);
        for(j=0;j<dimX;j++)
        {
            if(i==0)
            {
                 printf("  %d |",m[i][j]);
            }
            else
            {
                 printf(" %d |",m[i][j]);
            }

        }

        printf("\n");

    }



    return;
}


int main() {

    // matriz[filas][columnas] es obligatorio poner columnas. Si se omite filas hay que inicializar los elementos.
    int matriz[dimY][dimX];
    char LY[][3]={"Ay","By","Cy","Dy","Ey"};
    char LX[][3]={"Ax","Bx","Cx","Dx","Ex"};



    carga_matriz(matriz);
    emite_matriz(matriz,LY,LX);


    system ("pause");

    return 0;

}
