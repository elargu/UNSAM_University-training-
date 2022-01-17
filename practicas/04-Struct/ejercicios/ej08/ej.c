#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

struct paciente{

char nomb_pas[11];
char espec_pas[11];

};

struct fichas{

char nomb_doc[11];
char espc_doc[11];
int estado;
int pacien;

};

void caraga_pacientes(struct paciente v[],int d,struct fichas v2[],int dmed);
int buscamedico(char espec[], struct fichas vim[], int dm);
void carga_doctores(struct fichas v[],int d);
void muestra_doc(struct fichas v[],int d);
void muestra_pac(struct paciente v[],int d);




void caraga_pacientes(struct paciente v[],int d,struct fichas v2[],int dmed){

    int i=0,j,flag,flag2=0;
    char nombre_p[11],especialidad[11],salida;

    do
    {
        flag=0;
        printf("Ingrese nombre del paciente : ");
        fflush(stdin);
        gets(nombre_p);

        printf("Ingrese especialidad : ");
        fflush(stdin);
        gets(especialidad);


        flag=buscamedico(especialidad,v2,dmed);


        if(flag==1)
        {
            strcpy(v[i].nomb_pas, nombre_p);
            strcpy(v[i].espec_pas, especialidad);
            i++;

            printf("Cargado con exito!\n");
        }
        else
        {
            printf("No hay medicos disponibles con la especialidad seleccionada, no se gurdaron los datos\n");
        }


        printf("Desea cargar otro dato? S continuar, N salir\n\n");
        fflush(stdin);
        scanf("%c",&salida);

        if((salida=='N')||(salida=='n'))
        {
            flag2=1;
        }

    }while(flag2!=1);




    return;
}

int buscamedico(char espec[], struct fichas vim[], int dm){

    int fl=0,con=0,i,pos,con2=0,f2=0;
    char palab[11];

    for(i=0;i<dm;i++)
    {

        strcpy(palab,(vim[i].espc_doc));

        //printf("%d %s = %s = %s\n",i,espec,palab,vim[i].espc_doc);

        if((strcmp(espec, palab)==0))
        {

            if(vim[i].estado==0)
            {
                con++;
                pos=i;
            }

        }

    }

    if(con>1)
    {
        srand(time(NULL));
        pos = (0) + (rand()%con);
        //pos=0;
        //pos=1;
        i=0;
        do
        {

            if((0==(strcmp(espec, vim[i].espc_doc))))
            {
                if(vim[i].estado==0)
                {
                    if (con2==pos)
                    {
                        pos=i;
                        f2=1;
                    }
                    con2++;
                }

            }

            i++;

        }while(f2!=1);


        con=1;

    }
    //printf("hola\n");
    if(con==0)
    {
        fl=0;
    }
    if(con==1)
    {
        vim[pos].pacien=vim[pos].pacien+1;
        fl=1;

        if(vim[pos].pacien==5)
        {
            vim[pos].estado=1;
        }
    }


    return fl;

}

void carga_doctores(struct fichas v[],int d){

    int i;

    strcpy(v[0].nomb_doc,"CACHO");
    strcpy(v[0].espc_doc,"cabezera");
    v[0].estado=0;
    v[0].pacien=0;

    strcpy(v[1].nomb_doc,"NICK");
    strcpy(v[1].espc_doc,"cirujano");
    v[1].estado=0;
    v[1].pacien=3;

    strcpy(v[2].nomb_doc,"Picapiedra");
    strcpy( v[2].espc_doc,"cabezera");
    v[2].estado=1;
    v[2].pacien=5;

    strcpy( v[3].nomb_doc,"Sofia");
    strcpy(v[3].espc_doc,"cabezera");
    v[3].estado=0;
    v[3].pacien=4;

    strcpy(v[4].nomb_doc,"Roxi");
    strcpy(v[4].espc_doc,"cirujano");
    v[4].estado=1;
    v[4].pacien=5;

    //for(i=0;i<d;i++)
    //{
    //    printf("    %d\n",i+1);
    //    printf("Ingrese\nNombre del doctor/a: ");
    //   fflush(stdin);
    //    gets(v[i].nomb_doc);

    //    printf("Especialidad: ");
    //    fflush(stdin);
    //    gets(v[i].espc_doc);

    //    v[i].estado=0;
    //    v[i].pacien=0;

    //}



    return;
}

void muestra_doc(struct fichas v[],int d){

    int i;

    printf("******************************\n");
    printf("           Medicos\n");
    printf("******************************\n");

    for(i=0;i<d;i++)
    {
        printf("#Doc %d\n",i+1);
        printf("Nombre Doc: %s\n",v[i].nomb_doc);
        printf("Especialidad: %s\n",v[i].espc_doc);
        printf("Estado = %d\n",v[i].estado);
        printf("Pacients = %d\n",v[i].pacien);
        printf("--------------------------\n");
    }


return;
}

void muestra_pac(struct paciente v[],int d){

    printf("******************************\n");
    printf("           Pacientes\n");
    printf("******************************\n");


    int i;

    for(i=0;i<d;i++)
    {
        printf("#Paciente = %d\n",i+1);
        printf("Nombre : %s\n",v[i].nomb_pas);
        printf("Especialidad: %s\n",v[i].espec_pas);
        printf("--------------------------\n");

    }

return;
}

int main() {

    const int dim1=5; //medicos
    const int dim2=8; //pacientes (pongo 8 porque ya simule la carga en "carga dorctores" y me da que hay 17 pacientes ingresados, para 5 medios el maximo son 25
    struct fichas medic[dim1];
    struct paciente cliente[dim2];

    carga_doctores(medic,dim1);
    caraga_pacientes(cliente,dim2,medic,dim1);
    muestra_doc(medic,dim1); //esto es para chequear nomas, no lo pide el ejercicio
    muestra_pac(cliente,dim2);//lo mismo

    system ("pause");

    return 0;

}
