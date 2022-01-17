#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define dim 20

struct legajo{
int id_leg;
char nombre[10];            //El usuario puede ingresar 9 letras maximo.
char categoria;
float sueldo;
int activo;
};

void creo_archivodata();
int fun_menu();
void carga_archivodata();
void leo_activospasivos();
void leo_activos();
void lista_menu();
int aux_buslegajo();
void buscapor_legajo();
void buscapor_nombre();
void busca_menu();
void aux_modifica(float *sueldo,char *cate);
void modificax_legajo();
void modificax_nombre();
void modifica_menu();
void actualizo_sueldo();
void fun_bajalogica(char *psp);
void fun_bajafisica();

//menu principal
int fun_menu(){
    int selc;
    do
    {   printf("Menu:\n");
        printf("    1 -Crear archivo empleados.dat\n");
        printf("    2 -Alta de empleados\n");
        printf("    3 -Listar los datos en pantalla\n");
        printf("    4 -Buscar Datos de un Empleado\n");
        printf("    5 -Modificar Datos de un Empleado\n");
        printf("    6 -Actualizar sueldos\n");
        printf("    7 -Baja Logica a un empleado\n");
        printf("    8 -Baja Fisica\n");
        printf("    0 -para salir\n\n");
        printf("Ingrese: ");
        fflush(stdin);
        scanf("%d",&selc);
        printf("\n");
    }while((selc>8)||(selc<0));
    return selc;
}

//a)Crea "empleados.dat" : creo_archivodata
void creo_archivodata(){
	struct legajo fic[dim];
    int i;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","wb");
    if(pArchivo!=NULL)
    {
        for(i=0;i<dim;i++)
        {
            fic[i].id_leg=0;
            strcpy(fic[i].nombre,"0");
            fic[i].categoria='0';
            fic[i].sueldo=0;
            fic[i].activo=0;
            fwrite(&fic[i],sizeof(struct legajo),1,pArchivo);
        }
        fclose(pArchivo);
        printf("El archivo se creo con exito!\n");
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}

//b)Alta de Empleados : carga_archivodata
void carga_archivodata(){
	struct legajo ficc;
    int lg;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","r+b");
    if(pArchivo!=NULL){
    //aca hay un problema, si el legajo estuviera completo nunca saldria de este bucle, ya que nunca daria cero, lo ideal seria poner un caracter de salida por ejemplo el CERO 0,ademas de agregar algun if extra para que no vaya a buscar en el binario y modificar el do while.
    //Pero como la consigna no lo pide, no lo agregue.

	   do{
            do{
                printf("\nIngrese numero de legajo -1 a 20-: ");
                fflush(stdin);
                scanf("%d",&lg);

                if((lg>20)||(lg<1)){printf("fuera de rango\n");}
            }while((lg>20)||(lg<1));

            lg=lg-1;

            fseek(pArchivo,0,SEEK_SET);                                     //ubico el puntero en la primera posicion
            fseek(pArchivo,lg*sizeof(struct legajo),SEEK_CUR);             //ubico el puntero en la posicion buscada
            fread(&ficc,sizeof(struct legajo),1,pArchivo);             //copio el contenido en el struct

            if(ficc.id_leg!=0){printf("Error! el nro de legajo esta ocupado. Ingrese otro..\n");}    //si el contenido del id_leg es distinto de cero la posicion esta ocupada y no se puede escribir
            else{                                                                                       //si es igual cero agregamos los datos
                    //este fseek el codebolcks da warning, no se si es un problema del codebloks, dice que da overflow, puede ser porque en esta parte del codigo todavia no esta cargado lg y el codebolcks piensa que puede dar error, intente incializar lg=0 y sigue dando warning. intente con long int, long unsigned int, unsigned int pero nada.
                    fseek(pArchivo,-sizeof(struct legajo),SEEK_CUR);                                    //muevo el puntero para atras, porque la accion de lectura me adelanto el puntero.
                    ficc.id_leg=lg+1;                                                              //cargo los datos primero en el struct y lugo los paso al binario
                    printf("\nIngrese Nombre : ");
                    fflush(stdin);
                    gets(ficc.nombre);
                    do{
                        printf("\nIngrese Categoria -a,b,c- : ");
                        fflush(stdin);
                        scanf("%c",&ficc.categoria);
                        if(!((ficc.categoria=='a')||(ficc.categoria=='b')||(ficc.categoria=='c'))){printf("Opcion no valida, intente de vuelta\n");}
                    }while(!((ficc.categoria=='a')||(ficc.categoria=='b')||(ficc.categoria=='c')));

                    do{
                        printf("\nIngrese Sueldo : ");
                        fflush(stdin);
                        scanf("%f",&ficc.sueldo);
                        if(ficc.sueldo<0){printf("No puede ser un numero negativo, ingrese de nuevo\n");}
                    }while(ficc.sueldo<0);

                    ficc.activo=1;																	//activo al empleado

		            fseek(pArchivo,0,SEEK_SET);                                     //ubico el puntero en la primera posicion
					fseek(pArchivo,lg*sizeof(struct legajo),SEEK_CUR);             //ubico el puntero en la posicion buscada
                    fwrite(&ficc,sizeof(struct legajo),1,pArchivo);                                 //paso el dato al binario
                    printf("\ndato guardado con exito!\n");
                    ficc.id_leg=0;                                                                  //aca tengo que ponerlo en cero para salir del bucle, una ves cargado los datos
                }

        }while(ficc.id_leg!=0);

        fclose(pArchivo);                                                                                //cierro el archivo, una ves agregado al empleado.
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}

//c)Lista los datos por pantalla : leo_activospasivos / leo_activos / lista_menu
void leo_activospasivos(){
    struct legajo vf[dim];
    int i=0,j=0;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");
    if(pArchivo!=NULL)
    {
        fread(&vf[i],sizeof(struct legajo),1,pArchivo);
        while(!feof(pArchivo))
        {   if(vf[i].id_leg!=0){i++;}
            fread(&vf[i],sizeof(struct legajo),1,pArchivo);
        }
        fclose(pArchivo);
        if(i!=0){printf("Activos y Pasivos:\n");printf(" leg|     nom    | cat |    suel   | act \n");}
        while(j<i){printf(" %2d | %10s | %3c | %9.2f | %2d\n",vf[j].id_leg ,vf[j].nombre ,vf[j].categoria ,vf[j].sueldo ,vf[j].activo);j++;}
    }
    else{printf("Error en la apertura del archivo!\n");}

    return;
}
void leo_activos(){
    struct legajo varf[dim];
    int i=0,j=0;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");
    if(pArchivo!=NULL)
    {   fread(&varf[i],sizeof(struct legajo),1,pArchivo);
        if(varf[i].activo==1){i++;}
        while(!feof(pArchivo))
        {   fread(&varf[i],sizeof(struct legajo),1,pArchivo);
            if(varf[i].activo==1){i++;}
        }
        fclose(pArchivo);
        if(i!=0){printf("Solo Activos:\n");printf(" leg|     nom    | cat |    suel   | act \n");}
        while(j<i){printf(" %2d | %10s | %3c | %9.2f | %2d\n",varf[j].id_leg ,varf[j].nombre ,varf[j].categoria ,varf[j].sueldo ,varf[j].activo);j++;}
    }
    else{printf("Error en la apertura del archivo!\n");}

    return;
}
void lista_menu(){
    int op;
    do{ printf("Seleccione: \n");
        printf("    1-Listar Activos y Pasivos\n");
        printf("    2-Listar solo Activos\n");
        printf("    0-menu principal\n");
        printf("Ingrese: ");
        fflush(stdin);
        scanf("%d",&op);
        if((op>2)||(op<0)){printf("Opcion no valida, intente de vuelta\n");}
    }while((op>2)||(op<0));
    switch(op)
    {   case 0:
            break;
        case 1:
            leo_activospasivos();break;
        case 2:
            leo_activos();break;
        default:
            break;
    }

    return;
}

//d)Buscar Empleado : buscapor_legajo / buscapor_nombre / busca_menu / aux_buslegajo
int aux_buslegajo(){
	 int num;
	 do{printf("Ingrese numero de legajo -1 a 20- : ");
        fflush(stdin);
        scanf("%d",&num);
        if((num>dim)||(num<0)){printf("Fuera de rango, ingrese de vuelta\n");}
    }while((num>dim)||(num<0));

	return num;
}
void buscapor_legajo(){
    struct legajo bus;
    int num;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");
	num=aux_buslegajo();
    num=num-1;
    if(pArchivo!=NULL)
    {   fseek(pArchivo,0,SEEK_SET);
        fseek(pArchivo,num*sizeof(struct legajo),SEEK_CUR);
        fread(&bus,sizeof(struct legajo),1,pArchivo);
        if(bus.id_leg==0){printf("\nEl nro de legajo esta vacio\n");}
        else{printf(" leg|     nom    | cat |    suel   | act \n");printf(" %2d | %10s | %3c | %9.2f | %2d\n",bus.id_leg ,bus.nombre ,bus.categoria ,bus.sueldo ,bus.activo);}
        fclose(pArchivo);
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}
void buscapor_nombre(){
    struct legajo busn;
    int flag=0;
    char busca_nombre[10];
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");
    printf("Ingrese nombre : ");
    fflush(stdin);
    gets(busca_nombre);
    if(pArchivo!=NULL)
    {   fread(&busn,sizeof(struct legajo),1,pArchivo);
        if(strcmp(busn.nombre,busca_nombre)==0){flag=1;}

        while((!feof(pArchivo))&&(flag==0)){fread(&busn,sizeof(struct legajo),1,pArchivo);if(strcmp(busn.nombre,busca_nombre)==0){flag=1;}}
        fclose(pArchivo);

        if(flag==0){printf("\nNo se encontro a nadie con ese nombre\n");}
        else{printf(" leg|     nom    | cat |    suel   | act \n");printf(" %2d | %10s | %3c | %9.2f | %2d\n",busn.id_leg ,busn.nombre ,busn.categoria ,busn.sueldo ,busn.activo);}
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}
void busca_menu(){
    int op;
    do{
        printf("Seleccione Buscar: \n");
        printf("    1-Por Legajo\n");
        printf("    2-Por Nombre\n");
        printf("    0-menu principal\n");
        printf("Ingrese: ");
        fflush(stdin);
        scanf("%d",&op);
        if((op>2)||(op<0)){printf("Opcion no valida, intente de vuelta\n");}
    }while((op>2)||(op<0));

    switch(op)
    {
        case 0:
            break;
        case 1:
            buscapor_legajo();
            break;
        case 2:
            buscapor_nombre();
            break;
        default:
            break;
    }

    return;
}

//e)Modificar Categoria y Sueldo de Un empleado : modificax_legajo / modificax_nombre  / modifica_menu / aux_modifica
void aux_modifica(float *sueldo,char *cate){
	float dinero;
	char letra;
	do{	printf("\nIngrese Nuevo Sueldo : ");
        fflush(stdin);
        scanf("%f",&dinero);
        if(dinero<0){printf("No puede ser un numero negativo, ingrese de nuevo\n");}
    }while(dinero<0);
	*sueldo=dinero;
    do{ printf("\nIngrese Categoria -a,b,c- : ");
		fflush(stdin);
		scanf("%c",&letra);
		if(!((letra=='a')||(letra=='b')||(letra=='c'))){printf("Opcion no valida, intente de vuelta\n");}
    }while(!((letra=='a')||(letra=='b')||(letra=='c')));
	*cate=letra;

	return;
}
void modificax_legajo(){
    struct legajo persona;
    char confirmar;
    int num;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","r+b");
	num=aux_buslegajo();
    num=num-1;
    if(pArchivo!=NULL)
    {   fseek(pArchivo,0,SEEK_SET);
        fseek(pArchivo,num*sizeof(struct legajo),SEEK_CUR);
        fread(&persona,sizeof(struct legajo),1,pArchivo);
        if(persona.id_leg==0){printf("\nEl nro de legajo esta vacio\n");}
        else{   aux_modifica(&persona.sueldo,&persona.categoria);
			    printf("Esta seguro que quiere modificar los datos de %s ? -y=si/n=no- : ",persona.nombre);
				fflush(stdin);
				scanf("%c",&confirmar);
				if(confirmar=='y')
                {   fseek(pArchivo,0,SEEK_SET);
                    fseek(pArchivo,num*sizeof(struct legajo),SEEK_CUR);
                    fwrite(&persona,sizeof(struct legajo),1,pArchivo);
                    printf("Datos Actualizados!\n");
                }
                else{printf("\noperacion cancelada\n");}
            }
        fclose(pArchivo);
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}
void modificax_nombre(){
    struct legajo persona;
    int flag=0,i=0;
    char busca_nombre[10],confirmar;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb+");
    printf("Ingrese nombre : ");
    fflush(stdin);
    gets(busca_nombre);
    if((pArchivo!=NULL))
    {   fread(&persona,sizeof(struct legajo),1,pArchivo);
		while((!feof(pArchivo))&&(flag==0))
		{   if(strcmp(persona.nombre,busca_nombre)==0){flag=1;}
			if(flag==0){i++;fread(&persona,sizeof(struct legajo),1,pArchivo);}
		}
		if(flag==1){
			aux_modifica(&persona.sueldo,&persona.categoria);
			printf("Esta seguro que quiere modificar los datos de %s ? -y=si/n=no- : ",persona.nombre);
			fflush(stdin);
			scanf("%c",&confirmar);
			if(confirmar=='y')
            {   fseek(pArchivo,-sizeof(struct legajo),SEEK_CUR);
                fwrite(&persona,sizeof(struct legajo),1,pArchivo);
                printf("Datos Actualizados!\n");
            }else{printf("\noperacion cancelada\n");}
		}else{if(flag==0){printf("\nNo se encontro a nadie con ese nombre\n");}}
        fclose(pArchivo);
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}
void modifica_menu(){
    int selct;
    do{ printf("Seleccione modificar legajo: \n");
        printf("    1-por Legajo\n");
        printf("    2-por Nombre\n");
        printf("    0-menu principal\n");
        printf("Ingrese: ");
        fflush(stdin);
        scanf("%d",&selct);
        if((selct>2)||(selct<0)){printf("Opcion no valida, intente de vuelta\n");}
    }while((selct>2)||(selct<0));
    switch(selct)
    {   case 0:
            break;
        case 1:
            modificax_legajo();break;
        case 2:
            modificax_nombre();break;
        default:
            break;
    }
    return;
}

//f)Actualizo porcentaje sueldo -paritarias- : actualizo_sueldo
void actualizo_sueldo(){
    struct legajo ve[dim];
    int porcA,porcB,porcC,vporc[3],i=0,j=0;
    char cat[4]={"abc"};
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");           //Primero hago una pasada para buscar los datos que considen, si considen los modifico en un vector de struct
    printf("Ingrese el porcentaje de aumento de paritaria -un numero entero-:\n");
    while(j<3)
    {   do{ printf("Categoria %c : ",cat[j]);
            fflush(stdin);
            scanf("%d",&vporc[j]);
        if(porcA<0){printf("El porcentaje ingresado tiene que ser mayor a cero 0\n");}
        }while(porcA<0);j++;
    }j=0;            //como voy a volver a usar j mas adelante lo reinicio.
    if(pArchivo!=NULL)
    {   fread(&ve[i],sizeof(struct legajo),1,pArchivo);
        while(!feof(pArchivo))
        {   if(ve[i].categoria=='a'){ve[i].sueldo=ve[i].sueldo+((ve[i].sueldo*vporc[0])/100);}
            if(ve[i].categoria=='b'){ve[i].sueldo=ve[i].sueldo+((ve[i].sueldo*vporc[1])/100);}
            if(ve[i].categoria=='c'){ve[i].sueldo=ve[i].sueldo+((ve[i].sueldo*vporc[2])/100);}
            i++;
            fread(&ve[i],sizeof(struct legajo),1,pArchivo);
        }fclose(pArchivo);
    }else{printf("Error en la apertura del archivo!\n");}
    pArchivo=fopen("empleados.dat","wb+");                                   //lo unico que me funcion fue reventar el binario, lo que hace wb+, pisar el archivo.
//NOTA -> LEER!>>>>>la idea original era compararlo con (!feof(pArchivo)) hacer un "fwrite" cada ves que leo y actualizo una fila(paso a paso). Pero pincha por todos lados, no se porque, tira pantallazo de error.
//Solo me pasa con "fwrite", en el video monica nos dice que cuando hacemos "fread" o "fwrite" el cursor se ponde delante y hay que moverlo para atras (eh intentado hacer lo mismo y no funciona). Asi que me tuve que quemarme el bocho
//y lo unico que me funco es esto: primero leer el binario, pasar los datos un vector struct, luego cerrar el binario y abrirlo de nuevo con wb+, pisando el archivo.
//Si me piden una opinion diria que CodeBlocks cuando hace "fwrite" no adelanta el cursor, por eso pincha. Eso o hay algo que hago mal y no me doy cuenta (posiblemente esto ultimo).
    if(pArchivo!=NULL)
    {  fwrite(ve,sizeof(struct legajo),dim,pArchivo);
        //esto que esta abajo no me funciono (el binario se abria como r+b y un ):
        //fwrite(&ve[j],sizeof(struct legajo),1,pArchivo);while(!feof(pArchivo)){j++;fwrite(&ve[j],sizeof(struct legajo),1,pArchivo);}
        fclose(pArchivo);
        printf("Datos Actualizados!\n");
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}

//g)baja logica : fun_bajalogica
void fun_bajalogica(char *psp){
    struct legajo persona;
    char confir;
    int num;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","r+b");
	num=aux_buslegajo();
	num=num-1;
    if(pArchivo!=NULL)
    {   fseek(pArchivo,0,SEEK_SET);
        fseek(pArchivo,num*sizeof(struct legajo),SEEK_CUR);
        fread(&persona,sizeof(struct legajo),1,pArchivo);
        if(persona.activo==0){printf("\nError! El empleado no esta activo\n");}
        else{   printf(" leg|     nom    | cat |    suel   | act \n");
                printf(" %2d | %10s | %3c | %9.2f | %2d\n",persona.id_leg ,persona.nombre ,persona.categoria ,persona.sueldo ,persona.activo);
                printf("Esta seguro que quiere dar de baja logica a este empleado? -y=si/n=no- : ");
                fflush(stdin);
                scanf("%c",&confir);
                if(confir=='y')
                {   persona.activo=0;
                    *psp='y';
                    fseek(pArchivo,-sizeof(struct legajo),SEEK_CUR);
                    fwrite(&persona,sizeof(struct legajo),1,pArchivo);
                    printf("Datos Actualizados!\n");
                }else{printf("\noperacion cancelada\n");}
            }fclose(pArchivo);
    }else{printf("Error en la apertura del archivo!\n");}

    return;
}

//h)baja Fisica: fun_bajafisica
void fun_bajafisica(){
    char confp;
    struct legajo bfisica;
    struct legajo auxbfisica;
    FILE *temp;
    FILE *pArchivo;
    pArchivo=fopen("empleados.dat","rb");
    fseek(pArchivo,0,SEEK_SET);
    auxbfisica.id_leg=0;
    strcpy(auxbfisica.nombre,"0");
    auxbfisica.categoria='0';
    auxbfisica.sueldo=0;
    auxbfisica.activo=0;

    printf("Desea proceder con la Baja Fisica de la base de datos?\nSe creara o sobreescribira un nuevo archivo 'empleados.tmp'\ny=si otro=no : ");
    fflush(stdin);
    scanf("%c",&confp);
    if(confp=='y'){
        temp= fopen("empleados.tmp","w+b");
        if(pArchivo!=NULL)
        {   if(temp!=NULL)
            {   while(fread(&bfisica,sizeof(struct legajo),1,pArchivo)==1)
                {	if(bfisica.activo==1){fwrite(&bfisica,sizeof(struct legajo),1,temp);}
                    else{fwrite(&auxbfisica,sizeof(struct legajo),1,temp);}
                }
                printf("Operacion terminada con Exito!\n");
                fclose(temp);
            }else{printf("Error en la apertura del archivo!\n");}
            fclose(pArchivo);
        }else{printf("Error en la apertura del archivo!\n");}
    }else{printf("Operacion cancelada\n");}

    return;
}


int main() {
    int opcion;char preg='n';char confirm;
    do{ opcion=fun_menu();
        switch(opcion)
        {   case 0:
                    break;
            case 1:
					do{ printf("ATENCION!: se esta por crear un nuevo archivo 'empleados.dat'\nSi el archivo existe se perdera la informacion anterior.\n\nDesea continuar?...\n'y'=si, 'n'=no : ");
						fflush(stdin);scanf("%c",&confirm);
                    }while(!((confirm=='y')||(confirm=='n')));
                    if(confirm=='y'){creo_archivodata();}else{printf("Operacion abortada, no se producjo ningun cambio.\n");}break;
            case 2:
                    carga_archivodata();break;
            case 3:
                    lista_menu();break;
            case 4:
                    busca_menu();break;
            case 5:
                    modifica_menu();break;
            case 6:
                    actualizo_sueldo();break;
            case 7:
                    fun_bajalogica(&preg);
                    if(preg=='y'){leo_activos(dim);}  //LEER!!!  ESTE CODEBLOKS ESTA LOCO!!! JAJAJA : creo que lo estoy sobre exigiendo, intente hacer un flag de validacion con un flag entero y me pincha el programa. Si pongo un entero o un flotante como bandera para entrar a este if me modifica la variable "opcion" y me la pone en cero! -es la unica variable con ese nombre en el codigo-)
                    preg='n';break;
            case 8:
                    fun_bajafisica();break;
            default:
                    break;
        }
    }while(opcion!=0);

    system ("pause");

    return 0;
}

