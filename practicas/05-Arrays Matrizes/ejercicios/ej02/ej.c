#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define rangoIA -10
#define rangoIB 10
#define dimY 5  //dimension fila -
#define dimX 8  //dimension columna |

struct fila{

int maximo;
int suma;
float promedio;

};

struct columna{

int maximo;
int suma;
float promedio;

};



void emite_estructurasY(struct fila v[]){

    int i,p_max=0;
    float max=0;

    max=v[0].promedio

    for(i=0;i<dimX;i++)
    {
        printf("Pormedio fila %d = %.2f\n",i,v[i].promedio);

        if(v[i].promedio>=max)
        {
            max=v[i].promedio;
            p_max=i;
        }

    }

    printf("Promedio maximo fila = %d\n",max);

    return;

}

void emite_estructurasX(struct fila v[]){

//Valor maximo de cada columna
    int i;

    for(i=0;i<dimX;i++)
    {
        printf("Valor maximo Columna %d = %d\n",i,v[i].maximo);
        printf("Pormedio Columna %d = %.2f\n",i,v[i].promedio);
    }

}

void carga_matriz(int m[][dimX])
{
    int i,j;

    printf("Ingrese datos: \n");

    for(i=0;i<dimY;i++)
    {
        printf("Fila %d \n",i++);
        for(j=0;j<dimX;j++)
        {

            printf("fila[%d] Columna[%d] = ",i,j);
            scanf("%d",&m[i][j]);

        }
    }

    return;
}

int calcula_ceros(int m[][dimX])
{
    int i,cont=0;

    for(i=0;i<dimY;i++)
    {
        for(j=0;j<dimX;j++)
        {

            if(m[i][j]==0)
            {
                cont++;
            }

        }
    }
    return cont;
}


void calculo_fila(int m[][dimX],struct fila corY[dimY])
{
    int i,j,max,sum;

    for(i=0;i<dimY;i++)
    {
        max=m[i][j];
        sum=0;
        for(j=0;j<dimX;j++)
        {
            sum+=m[i][j];

            if(m[i][j]>max)
            {
                max=m[i][j];
            }

        }
        printf("Maximo fila %d  =  %d\n",i,max);
        corY[i].maximo=max;
        corY[i].suma=sum;
        corY[i].promedio=sum/dimY;
    }

     return;
}

void calculo_columna(int m[][dimX],struct fila corX[dimX])
{
    int i,j,max,sum;

    //es al reves de fila, cambio dimX y dimY de lugar. Ademas doy vuelta j y i.
    for(i=0;i<dimX;i++)
    {
        max=m[j][i];
        sum=0;
        for(j=0;j<dimY;j++)
        {
            sum+=m[j][i];

            if(m[j][i]>max)
            {
                max=m[j][i];
            }

        }
        printf("b) Maximo columna %d  =  %d\n",i,max);
        corX[i].maximo=max;
        corX[i].suma=sum;
        corX[i].promedio=sum/dimX;
    }

     return;
}

void calculo_matriz(int m[][dimX])
{
    int i,j,min,max,sum=0,min_x,min_y,max_x,max_y,c_pos=0,c_neg=0,c_cero=0;

    min=m[0][0];
    max=m[0][0];

    for(i=0;i<dimY;i++)
    {
        for(j=0;j<dimX;j++)
        {

            if(min<m[i][j])
            {
                min=m[i][j];
                min_x=j;
                min_y=i;
            }

            if(max>m[i][j])
            {
                max=m[i][j];
                max_x=j;
                max_y=i;
            }

            if(m[i][j]==0)
            {
                c_cero++;
            }
            if(m[i][j]>0)
            {
                c_pos++;
            }
            if(m[i][j]<0)
            {
                c_neg++;
            }

            sum+=m[i][j];
        }
    }

    printf("g)El elemento mayor y las posiciones en que aparece:\n");
    printf("Mayor = %d\n",max);

    for(i=0;i<dimY;i++)
    {
        for(j=0;j<dimX;j++)
        {

            if(m[i][j]==max)
            {
                printf("Pos Y = %d  |   Pos X = %d\n",i,j);
            }

        }
    }

    printf("c-g) El elemento menor y las posiciones en que aparece:\n");
    printf("Menor = %d\n",min);

    for(i=0;i<dimY;i++)
    {
        for(j=0;j<dimX;j++)
        {

            if(m[i][j]==min)
            {
                printf("Pos Y = %d  |   Pos X = %d\n",i,j);
            }

        }
    }

    printf("d) Promedio matriz = %.2f\n",sum/(dimX*dimY));
    printf("a-h) Cantidad de ceros = %d  | Cantidad de Positivos = %d | Cantidad de Negativos = %d",c_cero,c_pos,c_neg);

     return;
}

//void ALGO(int m[][dimX])
//{
//    int i;
//
//    for(i=0;i<dimY;i++)
//   {
//        for(j=0;j<dimX;j++)
//        {
//
//        }
//    }
//     return;
//}


int main() {

    struct fila coordenada_Y[dimY];
    struct columna coordenada_X[dimX];
    int matriz[dimY][dimX];

    carga_matriz(matriz);

    calculo_fila(matriz,coordenada_y);
    calculo_columna(matriz,coordenada_X);






    system ("pause");

    return 0;

}
