#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct materias{

float notas[3];

};

struct notas{

    char nombre[11];
    struct materias calificacion[5]; //son 10 en verdad, lo que pide el ejercicio
    float media;

};

void carga(struct notas v[],int d, int *cont);
void emite(struct notas v[],int d, int cont);

void carga(struct notas v[],int d, int *cont){

    int i,j,k;
    float med,not;

    for(i=0;i<d;i++)
    {
        printf("\nIngrese nombre de alumno %d : ",i+1);
        fflush(stdin);
        gets(v[i].nombre);

        med=0;

        for(j=0;j<2;j++)
        {
            not=0;

            printf("Materia %d \n",j+1);
            for(k=0;k<3;k++)
            {
                printf("\nIngrese nota %d = ",k+1);
                scanf("%f",&v[i].calificacion[j].notas[k]);
                not+=v[i].calificacion[j].notas[k];
            }

            med+=not/3; //dividido la cantidad de notas

        }

        v[i].media=med/2;   //dividido la cantidad de materias

        if(v[i].media>=6)
        {
            *cont=*cont+1;
        }

    }

    return;
}

void emite(struct notas v[],int d, int cont){

    int i;

    for(i=0;i<d;i++)
    {
        printf("%d) %s || media = %.2f\n",i+1,v[i].nombre,v[i].media);
    }

    printf("La cantidad de alumnos que aprueban son: %d\n",cont);

   return;
}

int main() {

    const int dim=3; //aca en verdad son 8, pero pruebo con menos
    struct notas estudiantes[dim];
    int conaprueba=0;


    carga(estudiantes,dim,&conaprueba);
    emite(estudiantes,dim,conaprueba);


    system ("pause");

    return 0;

}
