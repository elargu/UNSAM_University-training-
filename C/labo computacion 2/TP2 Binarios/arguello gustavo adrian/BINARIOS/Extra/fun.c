#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define dim 20
struct legajo{;

int id_leg;
char nombre[10];
char categoria;
float sueldo;
int activo;

};

void archivodata();


void archivodata()
{   struct legajo fh[dim];
	struct legajo fh2[dim];
    int i=0;
    FILE *pArchivo;
	FILE *temp;
    pArchivo=fopen("empleados.dat","rb");
	temp= fopen("empleados.tmp","rb");

	printf("************************** empleados.dat **************************\n\n");
    if(pArchivo!=NULL)
    {
        fread(&fh[i],sizeof(struct legajo),1,pArchivo);
        i++;
        while(!feof(pArchivo)){fread(&fh[i],sizeof(struct legajo),1,pArchivo);i++;}
        fclose(pArchivo);
        printf(" leg|     nom    | cat |    suel   | act \n");
        for(i=0;i<dim;i++){printf(" %2d | %10s | %3c | %9.2f | %2d\n",fh[i].id_leg ,fh[i].nombre ,fh[i].categoria ,fh[i].sueldo ,fh[i].activo);}

    }else{printf("Error en la apertura del archivo empleados.dat!\n");}

	i=0;
	printf("\n");
	printf("************************** empleados.tmp **************************\n\n");

    if(temp!=NULL)
    {
        fread(&fh2[i],sizeof(struct legajo),1,temp);
        i++;
        while(!feof(temp)){fread(&fh2[i],sizeof(struct legajo),1,temp);i++;}
        fclose(temp);
        printf(" leg|     nom    | cat |    suel   | act \n");
        for(i=0;i<dim;i++){printf(" %2d | %10s | %3c | %9.2f | %2d\n",fh2[i].id_leg ,fh2[i].nombre ,fh2[i].categoria ,fh2[i].sueldo ,fh2[i].activo);}

    }else{printf("Error en la apertura del archivo empleados.tmp!\n");}

    return;
}

int main(){
	int num=1;
	while(num==1){
		archivodata();
		printf("\nPara actualizar ingrese 1, para salir cualquier otra\n");
		fflush(stdin);
        scanf("%d",&num);
	}

    system ("pause");

    return 0;
}
