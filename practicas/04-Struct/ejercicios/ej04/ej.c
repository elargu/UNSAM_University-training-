#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct sueldo{

char nombre[11];
char sexo;
int hs_trab;
float suel_hora;
float suel_t;

};

void carga(struct sueldo v[],int d, float *hom, float *muj);
void emite(struct sueldo v[],int d,float homb,float muj);

void carga(struct sueldo v[],int d, float *hom, float *muj){

    int i,conth=0,contm=0;

    for(i=0;i<d;i++){

        printf("\n*****************************************************************");
        printf("\n%d - Ingrese nombre empleado: ",i+1);
        fflush(stdin);
        gets(v[i].nombre);

        do
        {
            printf("\n      Ingrese sexo m o f: ");
            fflush(stdin);
            scanf("%c",&v[i].sexo);

            if(v[i].sexo!='m')
            {
                if(v[i].sexo!='f')
                {
                    printf("\n     Dato Erroneo, ingrese de nuevo\n");
                }
            }
        }
        while((v[i].sexo!='m')&&(v[i].sexo!='f'));

        printf("\n      Ingrese Horas Trabajadas: ");
        fflush(stdin);
        scanf("%d",&v[i].hs_trab);

        printf("\n      Ingrese pago por Hora: ");
        fflush(stdin);
        scanf("%f",&v[i].suel_hora);

        v[i].suel_t = v[i].suel_hora * v[i].hs_trab;

        if(v[i].sexo=='m')
        {
            *hom=*hom+v[i].suel_t;
            conth++;
        }
        else
        {
            *muj=*muj+v[i].suel_t;
            contm++;
        }
    }

    *hom=*hom/conth;
    *muj=*muj/contm;

    return;
}

void emite(struct sueldo v[],int d,float homb,float muj){

    int i;
    printf("\n*****************************************************************\n");
    printf("_________________________________________________________________\n");
    printf("                           Totales\n");
    printf("_________________________________________________________________\n");
    for(i=0;i<d;i++){

        printf("\n%d | Nombre : %s | Sueldo mes = %.2f",i+1,v[i].nombre,v[i].suel_t);

    }

    printf("\n-----------------------------------------------------------------\n");
    printf("\nPromedio sueldo: \n Hombres = %.2f || Mujeres = %.2f \n",homb,muj);
    printf("-----------------------------------------------------------------\n\n");

    return;
}

int main() {

    const int dim = 6;
    struct sueldo empleados[dim];
    float suel_homb=0,suel_muj=0;

    printf("               ##############################\n");
    printf("                       El COCHO SRL\n");
    printf("               ##############################\n");
    printf("                      carga de empleados\n");
    printf("_________________________________________________________________\n");


    carga(empleados,dim, &suel_homb, &suel_muj);
    emite(empleados,dim,suel_homb,suel_muj);

    system ("pause");

    return 0;

}
