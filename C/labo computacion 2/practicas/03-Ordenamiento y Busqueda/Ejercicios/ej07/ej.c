#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//falla el busqueda
struct sueldo{

char nombre[11];
char sexo;
int hs_trab;
float suel_hora;
float suel_t;

};

void carga(struct sueldo v[],int d, float *hom, float *muj);
void emite(struct sueldo v[],int d,float homb,float muj);
int menu();
void porburbuja(struct sueldo v[], int d);
int busquedaBinaria( struct sueldo b[], char claveDeBusqueda[], int bajo, int alto);


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


int menu()
{

    int var,opcion;

    printf("ingrese una opcion: \n");
    printf("1-Carga Datos\n");
    printf("2-Emite Calculo\n");
    printf("3-Ordenar en lista\n");
    printf("4-Buscar en lista\n");
    printf("0-Salir\n");
    scanf("%d",&var);

    switch(var)
    {
        case 0:
            break;
        case 1:
            opcion=1;
            break;
        case 2:
            opcion=2;
            break;
        case 3:
            opcion=3;
            break;
        case 4:
            opcion=4;
            break;
        default:
            break;
    }

   return opcion;
}

void porburbuja(struct sueldo v[], int d)
{
	int i, j, cambio;
	struct sueldo temp;

	for(i=0;i<d-1;i++)
	{
		cambio=0;

		for(j=0;j < d-(i+1); j++)
		{
			if(strcmp(v[j].nombre,v[j+1].nombre)>0)
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


int busquedaBinaria( struct sueldo b[], char claveDeBusqueda[], int bajo, int alto){
   int central,resul=-1;

    while ( bajo <= alto ) {
        central = ( bajo + alto ) / 2;
        if (strcmp(claveDeBusqueda,b[central].nombre)==0)
        {
            resul = central;
        }
        else
        {
            if (strcmp(claveDeBusqueda,b[central].nombre)<0)
            {
                alto = central - 1;
            }
            else
            {
                bajo = central + 1;
            }
        }
    }
   return resul;
}


int main() {

    const int dim = 6;
    struct sueldo empleados[dim];
    float suel_homb=0,suel_muj=0;
    int selc_menu,flag=0,resull,bajo=0;
    char llave[11];

    printf("               ##############################\n");
    printf("                       El COCHO SRL\n");
    printf("               ##############################\n");
    printf("                      carga de empleados\n");
    printf("_________________________________________________________________\n");

    do
    {


        selc_menu=menu();

        if (selc_menu==1)
        {
            carga(empleados,dim, &suel_homb, &suel_muj);
            emite(empleados,dim,suel_homb,suel_muj);
            flag=1;
        }
        if (selc_menu==2)
        {
            if (flag==1)
            {
                emite(empleados,dim,suel_homb,suel_muj);
            }
            else
            {
                printf("No cargo los datos de los empleados!!\n");
            }

        }
        if(selc_menu==3)
        {

            if (flag==1)
            {
                printf("******************* Viejo  ***********************\n\n");
                emite(empleados,dim,suel_homb,suel_muj);
                printf("******************* Nuevo  ***********************\n\n");
                porburbuja(empleados,dim);
                emite(empleados,dim,suel_homb,suel_muj);
            }
            else
            {
                printf("No cargo los datos de los empleados!!\n");
            }

        }
        if(selc_menu==4)
        {
            if (flag==1)
            {
                printf("Ingrese llave : ");
                fflush(stdin);
                gets(llave);
                resull=busquedaBinaria(empleados,llave,bajo,dim);
                printf("resull 0 %d\n",resull);
                if(resull>=0)
                {
                    printf("Nombre = %s\n",empleados[resull].nombre);
                    printf("Sexo = %c\n",empleados[resull].sexo);
                    printf("horas trabajadas = %d\n",empleados[resull].hs_trab);
                    printf("Sueldo p. hora = %f\n",empleados[resull].suel_hora);
                    printf("Sueldo p. hora = %f\n",empleados[resull].suel_t);
                    printf("\n\n");

                }
                else
                {
                    printf("No se ha encontrado el resultado o fallo en la busqueda\n");
                }

            }
            else
            {
                printf("No cargo los datos de los empleados!!\n");
            }


        }

    }while(selc_menu!=0);

    system ("pause");

    return 0;

}
