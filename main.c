#include <stdio.h>
#include <stdlib.h>


FILE *ArchivoEmpleado;   //Archivo que almacena la informacion de los empleados
FILE *ArchivoProyecto;   //Archivo que almacena la informacion del Proyecto
FILE *ArchivoActividad;  //Archivo que almacena la informacion de las Actividades

char *direccionE = "C:\\Users\\Dell\\Documents\\empleados.txt";    //Archivo que almacena el archivo de los empleados
char *dirrecionP = "C:\\Users\\Dell\\Documents\\proyectos.txt";    //Archivo que almacena el archivo de los proyectos
char *direccionA = "C:\\Users\\Dell\\Documents\\actividades.txt";   //Archivo que almacena el archivo de las actividades

int contadorEmpleados = 1;
int contadorProyectos = 1;
int contadorActividad = 1;


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

typedef struct actividad{
    int *id;
    char *descripcion;
    int *porcentaje;
}Actividad;

typedef struct listaActvidades{
    Actividad* actividad;
    struct listaActvidades * sig;
}nodoActividad;

typedef struct proyecto{
    int *id;
    char *nombre;
    int *inicio;
    int *fin;
    nodoEmpleado empleados;
    nodoActividad actividades;
}Proyecto;

typedef struct listaProyectos{

}nodoProyectos;


nodoEmpleado *cabezaEmpleado = NULL;

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

void editarArchivo(char *direccion,FILE *file, Empleado *empleado){
    file = fopen(direccion,"a");
    fprintf(file,"%d\t%s\t%s\t%s\n",empleado->id,empleado->nombre,empleado->apellido,empleado->departamento);
    fclose(file);
    printf("\nSe edito el arhivo\n\n");
}
void actualizarTabla(){
char linea[1024];
    FILE *fich;

    fich = fopen("C:\\Users\\Raquel Rojas\\Desktop\\empleados.txt", "r");
    int count = 0;
    while(fgets(linea, 1024, (FILE*) fich))
        {
    if (count>=0){
        printf(linea);
        const char* word = strtok(linea,"\t");
        int atributos = 0;
        while(word != 0)
            {
            Empleado empleado;
            Empleado *ptrEmpleado;
            ptrEmpleado = &empleado;

            int *idE = &contadorEmpleados;

            char *nombre = (char*) malloc (sizeof (char));
            char *apellido = (char*) malloc (sizeof (char));
            char *departamento = (char*) malloc (sizeof (char));

                ptrEmpleado->id = *idE;
                ptrEmpleado->nombre = nombre;
                ptrEmpleado->apellido = apellido;
                ptrEmpleado->departamento = departamento;

            if (atributos == 0){
                 printf("ID: %s\n",word);
                 int idE = word;
                 ptrEmpleado ->id = idE;
            }
            if (atributos == 1){
                 printf("Nombre: %s\n",word);
                 ptrEmpleado->nombre = word;
            }
            if (atributos == 2){
                 printf("Apellido: %s\n",word);
                 ptrEmpleado->apellido = word;
            }
            if (atributos == 3){
                 printf("Departamento: %s\n",word);
                  ptrEmpleado->departamento = word;
            }
            atributos++;
            agregarEmpleado(ptrEmpleado);
            contadorEmpleados++;
            word = strtok(NULL," \t");
            }
        }
        count++;
    }
    fclose(fich);
}


int main(){
    crearArchivo(direccionE,ArchivoEmpleado);
    crearArchivo(dirrecionP,ArchivoProyecto);
    crearArchivo(direccionA,ArchivoActividad);


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

        if(respuesta==1){
            int agregar;
            printf("--Digite 1 para agregar Empleado\n\n"
                    "--Digite 2 para agregar Proyecto\n\n"
                    "--Digite 3 para agregar Actividad\n\n");
            printf("Respuesta:  ");
            scanf("%d",&agregar);
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
                editarArchivo(direccionE,ArchivoEmpleado,ptrEmpleado);
            }
            if(agregar=2){
            }
            if(agregar=3){
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
    return 0;
}

//helloworld
