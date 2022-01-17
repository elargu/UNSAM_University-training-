//Alumno: ARGUELLO GUSTAVO ADRIAN, DNI 31987342 -Laboratorio de Computacion 2- 2do Parcial - 09 Noviembre 2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define N 4   //dimension fila -
#define M 6   //dimension columna |

//ej 1 datos
struct sucursales{

int id_suc;
char ciudad[20];
float descuento_mes[30];                                     //////<__30 Se puede cambiar por un numero mas chico para probar la suma
float total_desmes;
float prom_desc;

};

//ej 2 datos
struct gerentes{

int id_gerente;
int id_sucursal;
char nombre_ger[30];

};


void datos_cargados(struct sucursales a[],struct gerentes b[],int auxray[],float mdesc[][M]);
void carga_vectordesc(struct sucursales v[]);
void carga_matriz(float mat[][M]);
int menu();
void fun_descuentomes(struct sucursales v[]);
void promedio_hitorico(struct sucursales v[], float mat[][M]);
int cargavar_auxiliar(struct sucursales v[],int array[]);
void emiteval_vauxiliar(struct sucursales v[],struct gerentes w[],int auxi[],int con);
void porburbujeo(struct sucursales v[]);


void datos_cargados(struct sucursales a[],struct gerentes b[],int auxray[],float mdesc[][M]){
    int i,j;

    printf("###########################################################################\n");

    printf("\n*****************************************************\n\n");
    printf("                    Sucursales\n");
    printf("*****************************************************\n\n");
    //sucursales
    for(i=0;i<N;i++)
    {
        printf("\n\n");
        printf("    --------------------------------\n");
        printf("    id sucursal: %d\n",a[i].id_suc);
        printf("    Ciudad     : %s\n",a[i].ciudad);

        printf("    ___________________________________\n");
        printf("              Descuentos Mes %d \n",i+1);
        printf("    ___________________________________\n");
        for(j=0;j<30;j++)                                               //////<__30 Se puede cambiar por un numero mas chico para probar la suma
        {
            printf("    Dia %d | Descuento: %.2f\n",j+1,a[i].descuento_mes[j]);
        }
        printf("    ___________________________________\n");
        printf("    Total descuento Mes = %.2f\n",a[i].total_desmes);
        printf("    Promedio Descuento = %.2f\n",a[i].prom_desc);

    }

    printf("\n*****************************************************\n\n");
    printf("                    Gerentes\n");
    printf("*****************************************************\n\n");

    //Gerentes
    for(i=0;i<N;i++)
    {
        printf("------------  %d  --------------\n",i+1);
        printf("id gerente        : %d\n",b[i].id_gerente);
        printf("id sucursal       : %d\n",b[i].id_sucursal);
        printf("Nombre Gerente    : %s\n",b[i].nombre_ger);
    }

    printf("\n*****************************************************\n\n");
    printf("                   Vector de Enteros\n");
    printf("*****************************************************\n\n");

    //Vector de enteros

    for(i=0;i<N;i++)
    {
        printf("%d) Entero = %d\n",i+1,auxray[i]);
    }

    //matriz
    printf("\n*****************************************************\n\n");
    printf("                    Matriz\n");
    printf("*****************************************************\n\n");


    printf("        ");

    for(j=0;j<M;j++)
    {
        printf("  mes_%d   |",j+1);
    }

    printf("\n");

    for(i=0;i<N;i++)
    {
        printf(" Suc_%d |",i+1);

        for(j=0;j<M;j++)
        {
            printf(" %.2f |",mdesc[i][j]);
        }

        printf("\n");
    }

    printf("###########################################################################\n");


    return;
}

void carga_vectordesc(struct sucursales v[]){
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<30;j++)                                        //////<__30S e puede cambiar por un numero mas chico para probar la suma
        {
            v[i].descuento_mes[j]=(rand()%12000)/(float)11;
        }
    }

    return;
}

void carga_matriz(float mat[][M]){
    int i,j;
    float res;

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            res=(165000)+(rand()%400000);
            mat[i][j]=res/(float)11;
        }
    }

    return;
}

int menu(){

    int var;

    printf("\n###########################################################################\n\n");
    printf("ingrese una opcion: \n");
    printf("1-Carga Campo 'total_desmes', Struc Sucursales\n");
    printf("2-Carga Campo 'prom_desc', Struc Sucursales\n");
    printf("3-Carga 'vec_aux' y devuelve los valores contados de main\n");
    printf("4-Emite Ciudad y Nombre de Gerente\n");
    printf("5-Ordena Struc Sucursales por burbujeo -Desendente-\n");
    printf("0-Salir\n");
    fflush(stdin);
    scanf("%d",&var);

   return var;

}

void fun_descuentomes(struct sucursales v[]){
    int i,j;
    float suma;

    for(i=0;i<N;i++)
    {
        suma=0;

        for(j=0;j<30;j++)                                    //////<__30   Se puede cambiar por un numero mas chico para probar la suma
        {
            suma=suma+v[i].descuento_mes[j];
        }

        //cargo "suma"
        v[i].total_desmes=suma;
    }

    return;
}

void promedio_hitorico(struct sucursales v[], float mat[][M]){
    int i,j;
    float sum;

    for(i=0;i<N;i++)
    {
        sum=0;

        for(j=0;j<M;j++)
        {

            sum=sum+mat[i][j];

        }

        v[i].prom_desc=sum/M;

    }


    return;
}

int cargavar_auxiliar(struct sucursales v[],int array[]){
    int i,j=0;

    for(i=0;i<N;i++)
    {
        if(v[i].total_desmes<v[i].prom_desc)
        {
            array[j]=i;
            j++;
        }
    }

    return j;

}

void emiteval_vauxiliar(struct sucursales v[],struct gerentes w[],int auxi[],int con){
    int i,j=0,k;

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Sucursales que superaron los descuentos historicos: \n");
    printf("\n");
    for(i=0;i<con;i++)
    {
        k=auxi[i];

        for(j=0;j<N;j++)
        {
            if(v[k].id_suc==w[j].id_sucursal)
            {
                printf("_______________________\n");
                printf("Ciudad         : %s\n",v[k].ciudad);
                printf("Nombre Gerente : %s\n", w[j].nombre_ger);

            }
        }
    }

    return;

}

void porburbujeo(struct sucursales v[]){
	int i, j, cambio;
	struct sucursales temp;

	for(i=0;i<N-1;i++)
	{
		cambio=0;

		for(j=0;j < N-(i+1); j++)
		{
			if(strcmp(v[j].ciudad,v[j+1].ciudad)<0)
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

int main(){
    //ej 1-2 datos: carga parcial de struct
    struct sucursales A_SUC[N]={{1,"Moron",0,0,0},{2,"Tigre",0,0,0},{3,"Vicente Lopez",0,0,0},{4,"San Isidro",0,0,0}};
    struct gerentes B_GER[M]={{1,3,"Aramando"},{2,2,"Estaban"},{3,1,"Quito"},{4,4,"Rojo"}};
    int vec_aux[N]={-1,-1,-1,-1},opcion,cont;
    float matriz_desc[N][M]={0.0};

    //funcion srand para randomizar
    srand(time(NULL));

    //emito los datos cargados hasta este punto, estan vacios
    datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);

    //ej 3 datos: Cargo en el struc Sucursales el vector "descuento_mes"
    carga_vectordesc(A_SUC);
    //ej 4 datos: Cargo en la matriz los decuentos historicos
    carga_matriz(matriz_desc);

    //emito los datos cargados hasta este punto, estan parcialmente cargados.
   datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);

    do
    {
        opcion=menu();

        switch(opcion)
        {
            case 0:
                break;
            case 1:
                //ej 1 requerimientos
                fun_descuentomes(A_SUC);
                datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);
                break;
            case 2:
                //ej 2 requerimientos
                promedio_hitorico(A_SUC,matriz_desc);
                datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);
                break;
            case 3:
                //ej 3 requerimientos
                cont=cargavar_auxiliar(A_SUC,vec_aux);
                datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);
                break;
            case 4:
                //ej 4 requerimientos
                emiteval_vauxiliar(A_SUC,B_GER,vec_aux,cont);
                break;
            case 5:
                //ej 5 requerimientos
                porburbujeo(A_SUC);
                datos_cargados(A_SUC,B_GER,vec_aux,matriz_desc);
                break;
            default:
                break;
        }

    }
    while(opcion!=0);


	    system ("pause");

    return 0;

}
