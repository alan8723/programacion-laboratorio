#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10
#define TAMC 3
#define TAMCOM 5

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct{
    int legajoAlmuerzo;
    int idComida;
    int idAlmuerzo;
    eFecha fecha;
    int isEmpy;
}eAlmuerzo;

typedef struct{

    int idComida;
    char desc[20];
    int precio;
}eComida;



typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
} eAlumno;

typedef struct{

    int id;
    char descripcion[20];

}eCarrera;

void mostrarAlumnosDeTodasLasCarreras(eCarrera carreras[], int tamC, eAlumno alumnos[], int tam);
void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam);
void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int leg, eCarrera carreras[], int tamC);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f, int idCarrera);
int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int ModificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad);

// Funciones Carrera
void mostrarCarreras(eCarrera carreras[], int tam);
void mostrarCarrera(eCarrera carrera);
int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]);

int menu();

int main()
{
    int legajo = 20000;
    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eAlumno lista[TAM];
    char salir = 'n';
    eAlmuerzo almuersos[TAM];
    eComida comidas[TAMCOM]= {{5000,"Bife", 250},{5001,"Fideos", 180},{5002,"Pizza", 200}, {5003,"Arroz", 160},{5004,"Milanesa", 220}};


    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);

    mostrarComidas(comidas, TAMCOM);



    /*do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            MostrarInformes(lista, TAM, carreras, TAMC);

            break;
        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');*/

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(){

    int opcion;

    system("cls");
    printf("****** Informes ******\n");
    printf("1-Mostrar Alumnos de una carrera \n");
    printf("2-Mostrar Alumnos por carrera \n");
    printf("3-Mostrar Cantidad de alumnos por carrera\n");
    printf("4-Mostrar La Carrera con mas inscriptos \n");
    printf("5-Mostrar Mejor promedio por carrera \n");
    printf("6-Mostrar Alumnos varones \n");
    printf("7-Mostrar Mujeres de alguna carrera \n");
    printf("8-Mostrar Alumnos mayores de 30 alguna licenciatura\n");
    printf("9-Salir \n\n");
    printf("Ingrece opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void MostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char salir = 'n';


    do{
            printf("Informes Alumno\n\n");

            switch(menuInformes()){

            case 1:

                mostrarAlumnosCarerraSeleccionada(alumnos, tam, carreras, tamC);

                break;
            case 2:

                mostrarAlumnosDeTodasLasCarreras(carreras, tamC, alumnos, tam);

                break;
            case 3:
                printf("seleccionaste opcion 3 \n");
                mostrarCantidadAlumnosCarrera(carreras, tamC, alumnos, tam);
                break;
            case 4:
                printf("seleccionaste opcion 4 \n");
                break;
            case 5:
                printf("seleccionaste opcion 5 \n");
                break;
            case 6:
                printf("seleccionaste opcion 6 \n");
                break;
            case 7:
                printf("seleccionaste opcion 7 \n");
                break;
            case 8:
                printf("seleccionaste opcion 8 \n");
                break;
            case 9:
                printf("Confirma salir?: \n");
                fflush(stdin);
                salir = getche();
                break;
            default:
                printf("opcion invalida \n");
            }

            system("pause");
            }
            while(salir == 'n');

}


void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam)
{
    char descCarrera[20];

    cargarDescCarrera(x.idCarrera, carreras, tam, descCarrera);
    printf("  %d  %10s   %d      %c    %2d    %2d       %3.2f     %02d/%02d/%d   %s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descCarrera);
}

void mostrarAlumnos(eAlumno vec[], int tam,  eCarrera carreras[], int tamC)
{

    int flag = 0;
    system("cls");

    printf(" Legajo    Nombre    Edad   Sexo  Nota1  Nota2  Promedio   FIngreso  Carrera\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i], carreras, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].sexo > vec[j].sexo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("Alumnos Ordenados\n\n");
}

void inicializarAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno vec[], int tam, int leg, eCarrera carreras[], int tamC)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    int idCarrera;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota 1: ");
        scanf("%d", &n1);

        printf("Ingrese nota 2: ");
        scanf("%d", &n2);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarCarreras(carreras, tamC);
        printf("Ingrese id carrera: ");
        scanf("%d", &idCarrera);

        vec[indice] = newAlumno(leg, nombre, edad, sexo, n1, n2, fecha, idCarrera);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAlumno newAlumno(
    int leg,
    char nombre[],
    int edad,
    char sexo,
    int nota1,
    int nota2,
    eFecha fecha,
    int idCarrera
    )
{

    eAlumno al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.idCarrera = idCarrera;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {
        mostrarAlumno(vec[indice], carreras, tamC);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int ModificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC)
{

    int todoOk = 0;
    int legajo;
    int indice;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice], carreras, tamC);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota1);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 2:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota2);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}


int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlumno suplentes[]=
    {
        { 20000, "Juan", 20, 'm', 5, 7, 6, {12, 5, 2015}, 1000, 0},
        { 20001, "Alberto", 21, 'm', 2, 8, 5, {12, 5, 2019},1001, 0},
        { 20002, "Ana", 22, 'f', 4, 5, 4.5, {2, 7, 2018},1002, 0},
        { 20003, "Luis", 20, 'm', 9, 8, 8.5, {21, 5, 2018},1000, 0},
        { 20004, "Alicia", 21, 'f', 6, 7, 6.5, {11, 9, 2017},1001, 0},
        { 20005, "Diego", 23, 'm', 2, 2, 2, {12, 4, 2014},1000, 0},
        { 20006, "Sofia", 19, 'f', 8, 9, 8.5, {12, 2, 2014},1002, 0},
        { 20007, "Clara", 21, 'f', 2, 4, 3, {28, 8, 2018},1001, 0},
        { 20008, "Mauro", 20, 'm', 4, 7, 5.5, {23, 3, 2015},1001, 0},
        { 20009, "Daniela", 22, 'f', 2, 8, 4, {10, 10, 2016},1000, 0},
        { 20010, "Agustin", 24, 'm', 6, 7, 6.5, {1, 7, 2017},1002, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarCarreras(eCarrera carreras[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarCarrera( carreras[i]);
    }
    printf("\n");
}

void mostrarCarrera(eCarrera carrera){

    printf("  %d      %10s\n", carrera.id, carrera.descripcion);

}

int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == carreras[i].id){
            strcpy(desc, carreras[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void MostrarAlumnosCarrera(eAlumno alumno[], int tam,  eCarrera carreras[], int tamC, int idCarrera){


    for(int i=0; i < tam; i++)
    {
        if (alumno[i].idCarrera == idCarrera && alumno[i].isEmpty == 0){

            mostrarAlumno(alumno[i], carreras, tamC);
        }
    }

}

void mostrarAlumnosCarerraSeleccionada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){
    int idCarrera;

    system("cls");
    mostrarCarreras(carreras, tamC);

    printf("indique el id de la carrera \n");
    scanf("%d", &idCarrera);

    MostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosDeTodasLasCarreras(eCarrera carreras[], int tamC, eAlumno alumnos[], int tam){

    char desc[20];

    for(int i = 0; i < tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("%s \n\n", desc);
        MostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera){

    int cantidad;
    for(int i=0; i < tam; i++)
    {
        if (alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){

            cantidad++;
        }
    }
    return cantidad;
}

void mostrarCantidadAlumnosCarrera(eCarrera carreras[], int tamC, eAlumno alumnos[], int tam){

     char desc[20];

    for(int i = 0; i < tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("%s \n\n", desc);
           // cantidadAlumnosCarrera(alumnos, tam, )
        }
}

void mostrarComida(eComida comidas){
    printf("%d,  %s,  %d \n\n", comidas.idComida, comidas.desc, comidas.precio);
}

void mostrarComidas(eComida comidas[], int tam){


    for(int i=0; i < tam; i++){
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void inicializarAlmuerzo(eAlmuerzo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpy = 1;
    }
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, int id, eAlumnos vec[], int tam, eComida comidas, int tamC)
{
    int todoOk = 0;
    int indice;
    int legajoAlumno;
    int idComida;
    int idAlmuerzo;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarLibre(almuerzos, tamA);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrce legajo alumno: ");
        scanf("%d", &legajoAlumno);

        printf("Ingrece id comida: ");
        sacnf("%d", idComida);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        vec[indice] = newAlmuerzo(almuerzos.legajoAlmuerzo, comidas.idComida, )
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

eAlmuerzo newAlmuerzo(
    int legAlumno,
    int idComida,
    int idAlmuerzo,
    eFecha fecha,
    int isEmpy,
    )
{

    eAlumuerzo alm;
    alm.legajoalumno = legAlumno;
    alm.idComida = idComida;
    alm.idAlmuerzo = idAlmuerzo;
    alm.fechaIngreso = fecha;
    alm.isEmpty = 0;

    return alm;
}
