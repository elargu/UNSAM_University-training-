#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//declaro struct
struct sueldos{

char nombre[11];
int categoria;
float suel_ultres[3];
float prome;

};
//declaro funciones

void carga(struct sueldos v[], int d);
void calcula(struct sueldos v[],int d, int *may_ubi);
void emite(struct sueldos v[],int d,int may_ubi);


//armo las funciones
void carga(struct sueldos v[], int d){

    int i,j;

    for(i=0;i<d;i++)
    {
        printf("Ingrese nombre : ");
        fflush(stdin);
        gets(v[i].nombre);

        printf("Ingrese categoria : ");
        fflush(stdin);
        scanf("%d",&v[i].categoria);

        printf("Ingrese ultimos 3 sueldos: \n");
        for(j=0;j<3;j++)
        {
            printf("Sueldo %d : ",j+1);
            fflush(stdin);
            scanf("%f",&v[i].suel_ultres[j]);
        }

        printf("\n");

    }

    return;
}

void calcula(struct sueldos v[],int d, int *may_ubi){

    int i,j;
    float prom,mayor=0;

    for(i=0;i<d;i++)
    {
        prom=0;

        for(j=0;j<3;j++)
        {
            prom+=v[i].suel_ultres[j];
        }

        prom=prom/3;

        if(prom>mayor)
        {
            *may_ubi=i;
            mayor=prom;
        }

        v[i].prome=prom;

    }


    return;
}

void emite(struct sueldos v[],int d,int may_ubi){

    int i;

    printf("a) Mayor ubicacion, primero\n");
    printf("Nombre: %s\n",v[may_ubi].nombre);
    printf("Categoria: %d\n",v[may_ubi].categoria);

    printf("b) Mayor ubicacion, y iguales\n");
    for(i=0;i<d;i++)
    {
        if(v[may_ubi].prome==v[i].prome)
        {
            printf("Nombre: %s\n",v[i].nombre);
            printf("Categoria: %d\n",v[i].categoria);
            printf("Promedio: %f\n",v[i].prome);
        }
    }

    return;
}
//llamo a funciones desde main
int main() {

    const int dim=10;
    struct sueldos trabajadores[dim];
    int mayor;


    carga(trabajadores,dim);
    calcula(trabajadores,dim,&mayor);
    emite(trabajadores,dim,mayor);


    system ("pause");

    return 0;

}
