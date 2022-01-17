#include <stdio.h>		//lib base
#include <stdlib.h>		//lib para usar pause
#include <math.h>		//lib funciones arimeticas
#include <ctype.h>		//lib para el manejo de caracteres
#include <string.h>		//lib para manejo de cadena de textos
#include <time.h>		//lib para hora del sistema, sirve para random
#define rangoIA 0		//Piso de Random (fijarse si esta permitido en el parcial, si no mandarlo por main o en funcion)
#define rangoIB 1000	//Techo de Random (fijarse si esta permitido en el parcial, si no mandarlo por main o en funcion)
#define N 4  //dimension fila - dimY
#define M 6  //dimension columna | dimX

//ej 1
struct competidores{

int id_comp;
char provincia[30];
float tiempos[10];
float prom_time_mes;
float prom_max;

};
//ej 2
struct instructores{

int id_compet;
char nombre_compet[30];
char nombre_instruc[30];

};

void datos_cargados(struct competidores a[],struct instructores b[],int auxray[],float promes[][M]);
void carga_tiempos(struct competidores v[]);
void carga_matriz(float mat[][M]);
void pro_mes_competidor(struct competidores v[]);
void promax_hitorico(struct competidores v[], float mat[][M]);
int cargavar_auxiliar(struct competidores v[],int array[]);
void emitecal_vauxiliar(struct competidores v[],struct instructores w[],int auxi[],int con);
void porburbujeo(struct competidores v[]);


void datos_cargados(struct competidores a[],struct instructores b[],int auxray[],float promes[][M])
{
    int i,j;

    printf("###########################################################################\n");

    printf("\n*****************************************************\n\n");
    printf("                    Competidores\n");
    printf("*****************************************************\n\n");
    //competidores
    for(i=0;i<N;i++)
    {
        printf("------------  %d  --------------\n",i+1);
        printf("id competidor: %d\n",a[i].id_comp);
        printf("Provicia : %s\n",a[i].provincia);

        printf("_____________________________\n");
        printf("           Tiempos\n");
        printf("_____________________________\n");
        for(j=0;j<10;j++)
        {
            printf("Mes %d tiempo: %.2f\n",j+1,a[i].tiempos[j]);
        }
        printf("_____________________________\n");
        printf("Promedio Tiempo Mes = %.2f\n",a[i].prom_time_mes);
        printf("Promedio Maximo = %.2f\n",a[i].prom_max);

    }

    printf("\n*****************************************************\n\n");
    printf("                    Instructores\n");
    printf("*****************************************************\n\n");

    //instructores
    for(i=0;i<N;i++)
    {
        printf("------------  %d  --------------\n",i+1);
        printf("id competidor: %d\n",b[i].id_compet);
        printf("Nombre Competidor: %s\n",b[i].nombre_compet);
        printf("Nombre Instructor: %s\n",b[i].nombre_instruc);
    }

    printf("\n*****************************************************\n\n");
    printf("                   Array de Enteros\n");
    printf("*****************************************************\n\n");

    //array de enteros

    for(i=0;i<N;i++)
    {
        printf("%d) Entero = %d\n",i+1,auxray[i]);
    }

    printf("\n*****************************************************\n\n");
    printf("                    Matriz\n");
    printf("*****************************************************\n\n");


    printf("   ");

    for(j=0;j<M;j++)
    {
        printf(" mes %d |",i+1);
    }

    printf("\n");

    for(i=0;i<N;i++)
    {
        printf("Comp %d |",i+1);

        for(j=0;j<M;j++)
        {
            printf(" %.2f |",promes[i][j]);
        }

        printf("\n");
    }

    printf("###########################################################################\n");

    return;
}

//ej 1 (tiempos)
void carga_tiempos(struct competidores v[])
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<10;j++)
        {
            v[i].tiempos[j]=(rand()%1100)/(float)11;
        }
    }

    return;
}

//ej 4
void carga_matriz(float mat[][M])
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            mat[i][j]=(rand()%770)/(float)11;
        }
    }

    return;
}

//ej 5
void pro_mes_competidor(struct competidores v[])
{
    int i,j;
    float suma;

    for(i=0;i<N;i++)
    {
        suma=0;

        for(j=0;j<10;j++)
        {
            suma=suma+v[i].tiempos[j];
        }

        //cargo "promedio tiempo mes"
        v[i].prom_time_mes=suma/10;
    }

    return;
}

//ej 6
void promax_hitorico(struct competidores v[], float mat[][M])
{
    int i,j;
    float max=-1;

    for(i=0;i<N;i++)
    {
        max=-1;

        for(j=0;j<M;j++)
        {
            if(mat[i][j]>max)
            {
                max=mat[i][j];
            }
        }

        v[i].prom_max=max;

    }


    return;
}

//ej 7
int cargavar_auxiliar(struct competidores v[],int array[])
{
    int i,j=0;

    for(i=0;i<N;i++)
    {
        if(v[i].prom_time_mes<v[i].prom_max)
        {
            array[j]=i;
            j++;
        }
    }

    return j;

}

//ej 8
void emitecal_vauxiliar(struct competidores v[],struct instructores w[],int auxi[],int con)
{
    int i,j=0,k;

    printf("Competidores que superaron el promedio historico: \n");

    for(i=0;i<con;i++)
    {
        k=auxi[i];

        for(j=0;j<N;j++)
        {
            if(v[k].id_comp==w[j].id_compet)
            {
                printf("Provincia : %s\n",v[k].provincia);
                printf("Nombre competidor : %s\n", w[j].nombre_compet);
                printf("Nombre Instructor : %s\n", w[j].nombre_instruc);

            }
        }
    }

    return;

}

//ej 9
void porburbujeo(struct competidores v[])
{
	int i, j, cambio;
	struct competidores temp;

	for(i=0;i<N-1;i++)
	{
		cambio=0;

		for(j=0;j < N-(i+1); j++)
		{
			if(strcmp(v[j].provincia,v[j+1].provincia)<0)
			{
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				cambio = 1;
			}
		}
	}

	return;

}

int main() {

    struct competidores A_COMP[N]={{1,"Cordoba",0,0,0},{2,"Buenos Aires",0,0,0},{3,"Santa Fe",0,0,0},{4,"Mendoza",0,0,0}};
    struct instructores B_INST[N]={{1,"Pepe","Lepu"},{2,"Juan","Topo"},{3,"Bart","Simpsonitos"},{4,"Elvis","Cocho"}};

    int auxi_array[N]={-1,-1,-1,-1};
    int cont;

    float promensual[N][M];
    srand(time(NULL)); //Yo soy de cargarlo en la funcion, pero es lo mismo

    //muestro datos cargados hasta aca
    datos_cargados(A_COMP,B_INST,auxi_array,promensual);

    //cargo datos que faltaban
    carga_tiempos(A_COMP);
    carga_matriz(promensual);
    //muestro datos cargados hasta aca
    datos_cargados(A_COMP,B_INST,auxi_array,promensual);

    //cargo el promedio mes del competidor
    pro_mes_competidor(A_COMP);
    //busco el maximo historico de cada competidor en la matriz y lo guardo en su correspondiente lugar de struct
    promax_hitorico(A_COMP,promensual);
    //busco aquellos competidores que el promedio mes no supera al promedio maximo, si los hay se guarda su posicion en la variable auxliar. Finalmente la funcion devuelve un contador de aquellos que complen la condicion
    cont=cargavar_auxiliar(A_COMP,auxi_array);
    //muestro datos cargados hasta aca
    datos_cargados(A_COMP,B_INST,auxi_array,promensual);

    //emito aquellos competidores que superaron su promedio historico:
    emitecal_vauxiliar(A_COMP,B_INST,auxi_array,cont);

    //organizo el struck competidores por burbujeo:
    porburbujeo(A_COMP);
    //muestro datos cargados hasta aca
    datos_cargados(A_COMP,B_INST,auxi_array,promensual);




	    system ("pause");

    return 0;

}
