#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ArchivoEmpleado;   //Archivo que almacena la informacion de los empleados
FILE *ArchivoProyecto;   //Archivo que almacena la informacion del Proyecto
FILE *ArchivoActividad;  //Archivo que almacena la informacion de las Actividades
FILE *ArchivoEmpProyecto;

char *direccionE = "C:\\Users\\Dell\\Desktop\\empleados.txt";    //Archivo que almacena el archivo de los empleados
char *direccionP = "C:\\Users\\Dell\\Desktop\\proyectos.txt";    //Archivo que almacena el archivo de los proyectos
char *direccionA = "C:\\Users\\Dell\\Desktop\\actividades.txt";   //Archivo que almacena el archivo de las actividades
char *direccionEP = "C:\\Users\\Dell\\Desktop\\empleadosProyectos.txt";

int contadorEmpleados = 1;
int contadorProyectos = 1;
int contadorActividad = 1;
int contadorEmpP = 1;


typedef struct empleado{     //Estructura empleado
    int *id;
    char *nombre;
    char *apellido;
    char *departamento;
}Empleado;

typedef struct listaEmpleados{
    Empleado empleado;
    struct listaEmpleados *sig;
}nodoEmpleado;

typedef struct empProyecto{
    char *nombreEmpleado;
    int *idProyecto;
} EmpProyecto;

typedef struct listaEmpProyecto{
    EmpProyecto empProyecto;
    struct listaEmpProyecto *sig;
}nodoEmpProyectos;

typedef struct actividad{
    int *id;
    char *descripcion;
    int *porcentaje;
    int *idProyecto;
}Actividad;

typedef struct listaActvidades{
    Actividad actividad;
    struct listaActvidades * sig;
}nodoActividad;

typedef struct proyecto{
    int *id;
    char *nombre;
    int *inicio;
    int *fin;
}Proyecto;

typedef struct listaProyectos{
    Proyecto proyecto;
    struct listaProyectos * sig;
}nodoProyectos;


nodoEmpleado *cabezaEmpleado = NULL;
nodoActividad *cabezaActivdad = NULL;
nodoEmpProyectos *cabezaEmpProyecto = NULL;
nodoProyectos *cabezaProyecto = NULL;

void agregarEmpleado(Empleado* entrante){
    nodoEmpleado *nuevo = (nodoEmpleado *)malloc(sizeof(nodoEmpleado));

     nuevo->empleado.id = entrante->id;
     nuevo->empleado.nombre = entrante->nombre;
     nuevo->empleado.apellido = entrante->apellido;
     nuevo->empleado.departamento = entrante->departamento;

     if(cabezaEmpleado == NULL){
        cabezaEmpleado = nuevo;
        cabezaEmpleado->sig = NULL;
     }
     else{
        nuevo->sig = cabezaEmpleado;
        cabezaEmpleado = nuevo;
     }
}

void agregarActividad(Actividad* entrante){
    nodoActividad *nuevo = (nodoActividad *)malloc(sizeof(nodoEmpleado));

     nuevo->actividad.id = entrante->id;
     nuevo->actividad.descripcion = entrante->descripcion;
     nuevo->actividad.porcentaje = entrante->porcentaje;
     nuevo->actividad.idProyecto = entrante->idProyecto;

     if(cabezaActivdad == NULL){
        cabezaActivdad = nuevo;
        cabezaActivdad->sig = NULL;
     }
     else{
        nuevo->sig = cabezaActivdad;
        cabezaActivdad = nuevo;
     }
}

void agregarEmpProyecto(EmpProyecto* entrante){
    nodoEmpProyectos *nuevo = (nodoEmpProyectos *)malloc(sizeof(nodoEmpProyectos));

     nuevo->empProyecto.nombreEmpleado = entrante->nombreEmpleado;
     nuevo->empProyecto.idProyecto = entrante->idProyecto;


     if(cabezaEmpProyecto == NULL){
        cabezaEmpProyecto = nuevo;
        cabezaEmpProyecto->sig = NULL;
     }
     else{
        nuevo->sig = cabezaEmpProyecto;
        cabezaEmpProyecto = nuevo;
     }
}

void agregarProyecto(Proyecto* entranteP){
    nodoProyectos *nuevoP = (nodoProyectos *)malloc(sizeof(nodoProyectos));

    nuevoP->proyecto.id = entranteP->id;
    nuevoP->proyecto.nombre = entranteP->nombre;
    nuevoP->proyecto.inicio = entranteP->inicio;
    nuevoP->proyecto.fin = entranteP->fin;

    if(cabezaProyecto == NULL){
        cabezaProyecto = nuevoP;
        cabezaProyecto-> sig = NULL;
    } else  {
        nuevoP->sig = cabezaProyecto;
        cabezaProyecto = nuevoP;
    }
}

void imprimirEmpleados(nodoEmpleado* cab){
    nodoEmpleado* actual = cab;
    while(actual != NULL){
        printf("%d\t%s\t%s\t%s\n",actual->empleado.id,actual->empleado.nombre,actual->empleado.apellido,actual->empleado.departamento);
        actual = actual->sig;
    }

}
void crearArchivo(char direccion[], FILE *file){     //crea archivo de texto recibiendo una direccion y un archivo
    file = fopen(direccion,"rb");
    if(file != NULL){
    }
    else{
        file = fopen(direccion,"w");
        printf("Se creo el archivo en la ubicacion: %s\n",direccion);
    }
}

void editarArchivoEmpleado(char *direccion,FILE *file, Empleado *empleado){
    file = fopen(direccion,"a");
    fprintf(file,"%d\t%s\t%s\t%s\n",empleado->id,empleado->nombre,empleado->apellido,empleado->departamento);
    fclose(file);
    printf("\nSe edito el arhivo\n\n");
}

void editarArchivoActividad(char *direccion,FILE *file, Actividad *actividad){
    file = fopen(direccion,"a");
    fprintf(file,"%d\t%s\t%d % \t%d\n",actividad->id,actividad->descripcion,actividad->porcentaje,actividad->idProyecto);
    fclose(file);
    printf("\nSe edito el arhivo\n\n");
}

void editarArchivoEmpProyecto(char *direccion,FILE *file, EmpProyecto *empProyecto){
    file = fopen(direccion,"a");
    fprintf(file,"%s\t%d\n",empProyecto->nombreEmpleado,empProyecto->idProyecto);
    fclose(file);
    printf("\nSe edito el arhivo\n\n");
}

void editarArchivoProyecto(char *direccion, FILE *file, Proyecto *proyecto){
    file = fopen(direccion,"a");
    fprintf(file,"%d\t%s\t%d\t%d\n",proyecto->id,proyecto->nombre, proyecto->inicio, proyecto->fin);
    fclose(file);
    printf("\nSe edito el archivo\n\n");

}


void actualizarTabla(){
char linea[1024];
    FILE *fich;

    fich = fopen(direccionE, "r");

    while(fgets(linea, 1024, (FILE*)fich)){
        printf(linea);
        const char* word = strtok(linea,"\t");
        int atributos = 0;
        Empleado empleado;
        Empleado *ptrEmpleado;
        ptrEmpleado = &empleado;

        int *idE = (int*) malloc(sizeof(int));
        char *nombre = (char*) malloc (sizeof (char));
        char *apellido = (char*) malloc (sizeof (char));
        char *departamento = (char*) malloc (sizeof (char));

        ptrEmpleado->id = *idE;
        ptrEmpleado->nombre = nombre;
        ptrEmpleado->apellido = apellido;
        ptrEmpleado->departamento = departamento;
        while(atributos<4)
            {
            if (atributos == 0){
                 printf("ID: %s\n",word);
                 ptrEmpleado->id = atoi(word);
            }
            if (atributos == 1){
                 printf("Nombre: %s\n",word);
                 strcpy(ptrEmpleado->nombre,word);
            }
            if (atributos == 2){
                 printf("Apellido: %s\n",word);
                 strcpy(ptrEmpleado->apellido,word);
            }
            if (atributos == 3){
                 printf("Departamento: %s\n",word);
                 strcpy(ptrEmpleado->departamento,word);
            }

            atributos++;
            word = strtok(NULL," \t");
            }
        agregarEmpleado(ptrEmpleado);
        contadorEmpleados++;
    }
    fclose(fich);
}



int main(){
    crearArchivo(direccionE,ArchivoEmpleado);
    crearArchivo(direccionP,ArchivoProyecto);
    crearArchivo(direccionA,ArchivoActividad);
    crearArchivo(direccionEP,ArchivoEmpProyecto);

    actualizarTabla();


    int salir;

    while(salir!=5){

        int respuesta;

        printf("Proyecto Programado 1\n\n"
                "--Digite 1 si desea agregar\n\n"
                "--Digite 2 si desea modificar activdad\n\n"
                "--Digite 3 si desea consultar proyecto\n\n"
                "--Digite 4 si desea consiltar empleado\n\n"
                "--Digite 5 si desea salir\n\n");
        printf("Respuesta:  ");
        scanf("%d",&respuesta);
        system("cls");

        if(respuesta==1){
            int agregar;
            printf("--Digite 1 para agregar Empleado\n\n"
                    "--Digite 2 para agregar Proyecto\n\n"
                    "--Digite 3 para agregar Actividad\n\n");
            printf("Respuesta:  ");
            scanf("%d",&agregar);
            system("cls");

            if(agregar==1){
                Empleado empleado;
                Empleado *ptrEmpleado;
                ptrEmpleado = &empleado;

                int *idCliente = &contadorEmpleados;


                char *nombre = (char*) malloc (sizeof (char));
                char *apellido = (char*) malloc (sizeof (char));
                char *departamento = (char*) malloc (sizeof (char));

                printf("Indique Nombre:");
                scanf("%s",nombre);
                printf("\nIndique Apellido:");
                scanf("%s",apellido);
                printf("\nIndique Departamento:");
                scanf("%s", departamento);

                ptrEmpleado->id = *idCliente;
                ptrEmpleado->nombre = nombre;
                ptrEmpleado->apellido = apellido;
                ptrEmpleado->departamento = departamento;

                agregarEmpleado(ptrEmpleado);
                contadorEmpleados++;
                editarArchivoEmpleado(direccionE,ArchivoEmpleado,ptrEmpleado);
            }
            if(agregar==2){
               if (contadorEmpleados >2){
                    Proyecto proyecto;
                    Proyecto *ptrProyecto;
                    ptrProyecto = &proyecto;

                    int *idProyecto = &contadorProyectos;

                    char *nombre = (char*) malloc (sizeof (char));
                    int *inicio = (int*) malloc (sizeof (int));
                    int *fin = (int*) malloc (sizeof (int));
                    char *nombreEmpleado = (char*) malloc (sizeof(char));
                    int contador =0;
                    int cantidad;

                    printf("Indique Nombre del proyecto: ");
                    scanf("%s",nombre);
                    printf("\nIndique el ano de inicio: ");
                    scanf("%d",inicio);
                    printf("\nIndique el ano de finalizacion: ");
                    scanf("%d" ,fin);
                    printf("\nIndique la cantidad de empleados: ");
                    scanf("%d", &cantidad);

                    ptrProyecto->id = *idProyecto;
                    ptrProyecto->nombre = nombre;
                    ptrProyecto->inicio = *inicio;
                    ptrProyecto->fin = *fin;
                    editarArchivoProyecto(direccionP,ArchivoProyecto,ptrProyecto);

                    agregarProyecto(ptrProyecto);

                    while(contador <= cantidad) {

                    printf("\nIndique el nombre del empleado: ");
                    scanf("%s",nombreEmpleado);

                    EmpProyecto empProyecto;
                    EmpProyecto *ptrEmpProyecto;
                    ptrEmpProyecto= &empProyecto;
                    ptrEmpProyecto->nombreEmpleado = nombreEmpleado;
                    ptrEmpProyecto->idProyecto = *idProyecto;

                    nodoEmpleado* actual;
                        actual = cabezaEmpleado;
                        int encontrado;
                            while(actual != NULL && encontrado!=1){
                                if (actual->empleado.nombre == nombreEmpleado){
                                    printf("\n El empleado con el nombre (%s) existe", nombreEmpleado);
                                    agregarEmpProyecto(ptrEmpProyecto);
                                    system("cls");
                                    editarArchivoEmpProyecto(direccionEP,ArchivoEmpProyecto,ptrEmpProyecto);
                                    contador++;
                                    encontrado = 1;
                                    }
                                    actual = actual->sig;
                            }
                        if (encontrado == 0){
                            printf("\n Empleado no encontrado");
                        }
           }} else{
                printf("\n Se necesitan al menos 2 empleados previamente registrados para inserta un proyecto");
        }
               }


            if(agregar==3){
                Actividad actividad;
                Actividad *ptrActividad;
                ptrActividad = &actividad;

                int *idActividad = &contadorActividad;


                char *descripcion = (char*) malloc (sizeof (char));
                int *porcentaje = (char*) malloc (sizeof (char));
                int *idProyecto= (char*) malloc (sizeof (char));

                printf("Indique Descripcion:");
                scanf("%s",descripcion);
                printf("\nIndique Porcentaje:");
                scanf("%d",porcentaje);
                printf("\nIndique Numero de Proyecto");
                scanf("%d",idProyecto);

                ptrActividad->id = *idActividad;
                ptrActividad->descripcion = descripcion;
                ptrActividad->porcentaje = *porcentaje;
                ptrActividad->idProyecto = *idProyecto;

                agregarActividad(ptrActividad);
                contadorActividad++;
                system("cls");
                editarArchivoActividad(direccionA,ArchivoActividad,ptrActividad);
            }
        }
        if(respuesta==2){
            imprimirEmpleados(cabezaEmpleado);
        }

        if(respuesta==3){
        }
        if(respuesta==4){
        }
        if(respuesta==5){
            printf("Final del programa");
            break;
        }
    }
}

