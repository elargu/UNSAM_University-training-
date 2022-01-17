#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cargadatos(float v[],int d);
void diamini(float v[],int d,int mtp);

int main() {

    const int dim=30;
    float tem[dim],mi;

    mi=cargadatos(tem,dim);
    diamini(tem,dim,mi);

    system ("pause");

    return 0;

}

float cargadatos(float v[],int d)
{
    int i;
    float minimo=99;

    printf("Ingrese Datos de las temperaturas por dia: \n");

    for(i=0;i<d;i++)
    {
        printf("Junio dia %d, C = ",i+1);
        scanf("%f",&v[i]);

        if(v[i]<minimo)
        {
            minimo=v[i];
        }
    }

    printf("Temperatura Minima Registrada : %.2f C\n",minimo);

    return minimo;

}

void diamini(float v[],int d,int mtp)
{
    int i;

    printf("dia/dias con menor temperatura:\n");

    for(i=0;i<d;i++)
    {
        if(v[i]==mtp)
        {
            printf("Junio %d\n",i+1);
        }
    }

    return;

}
