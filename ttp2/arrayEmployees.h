#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int menu();

int initEmployees (Employee employees[], int len);

int addEmployees(Employee employees[], int len, int id, char nombre[], char lastName[], float salary, int sector);

int findEmployeeById(Employee employees[], int len, int id);

int removeEmployee(Employee employees[], int len, int id);

int sortEmployees(Employee employees[], int len, int order);

int printEmployees(Employee employees[], int length);

int printEmpoyee(Employee employees);

int seachFree(Employee employees[], int len);

Employee newEmployee(int id, char name[], char lastName[], float salary, int sector);


// menu de opciones
int menu(){
    int opcion;

    printf("****** menu de opciones ******\n\n");
    printf("-1 ALTAS \n");
    printf("-2 MODIFICAR \n");
    printf("-3 BAJA \n");
    printf("-4 INFORMES \n");
    printf("-5 SALIR \n");
    printf("seleccione una opcion \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int initEmployees (Employee employees[], int len){

    int todoOK = -1;
    int flag = 1;

    for(int i = 0; i < len; i++){
         employees[i].isEmpty = 1;
         if (flag){
            flag = -1;
            todoOK = 0;
         }
    }

    return todoOK;
}

int seachFree(Employee employees[], int len){
    int indice = -1;

    for (int i = 0; i < len; i++){
        if(employees[i].isEmpty == 1){
           indice = i;
           break;
        }
    }
    return indice;
}

int addEmployees(Employee employees[], int len, int id, char name[], char lastName[], float salary, int sector){
    int indice;
    int todoOk = 0;

    indice = seachFree(employees, len);

        if( indice == -1)
    {

        printf("\nSistema completo\n\n");

    }


    else
    {

        employees[indice] = newEmployee(id, name, lastName, salary, sector);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");

    }

    return todoOk;

}

Employee newEmployee(int id, char name[], char lastName[], float salary, int sector){


    Employee em;
    em.id = id;
    strcpy(em.name, name);
    strcpy(em.lastName, lastName);
    em.salary = salary;

    em.sector = sector;
    em.isEmpty = 0;



    return em;

}

int findEmployeeById(Employee employees[], int len, int id){

    int indice = -1;

    for(int i = 0; i < len; i++){
        if (employees[i].id == id && employees[i].isEmpty == 0){
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(Employee employees[], int len, int id){
    int baja;
    int todoOk = -1;

    baja = findEmployeeById(employees, len, id);



    if(employees[baja].id == id){
        employees[baja].isEmpty = -1;
        todoOk = 0;
    }

    return todoOk;
}

int sortEmployees(Employee employees[], int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;
    int todoOk = -1;

    if(order == 1){

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(employees[i].name ,employees[j].name)>0)
                {
                     auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j] = auxEmployee;
                }

                else
                {
                    if(strcmp(employees[i].name, employees[j].name)==0)
                    {
                        if(employees[i].sector > employees[j].sector)
                        {
                             auxEmployee = employees[i];
                            employees[i] = employees[j];
                            employees[j] = auxEmployee;
                        }
                    }
                }
            }

        }

        todoOk = 0;
    }



    if(order == 2){

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(employees[i].name, employees[j].name)<0)
                {
                     auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j] = auxEmployee;
                }

                else
                {
                    if(strcmp(employees[i].name, employees[j].name)==0)
                    {
                        if(employees[i].sector > employees[j].sector)
                        {
                             auxEmployee = employees[i];
                            employees[i] = employees[j];
                            employees[j] = auxEmployee;
                        }
                    }
                }
            }

        }

        todoOk = 0;
    }

    return todoOk;
}

int printEmployees(Employee employees[], int length){

    printf("id  --  nombre  --  apellido  --  salario  --  sector  \n\n");

    for(int i = 0; i < length; i++){
        if(employees[i].isEmpty == 0){
            printEmpoyee(employees[i]);
        }
    }
}

int printEmpoyee(Employee employees){
    printf("%d  --  %s  --  %s  --  %f  --  %d  \t\n\n ", employees.id, employees.name, employees.lastName, employees.salary, employees.sector);
}

int modificarEmployee(Employee employees[], int len){

    int todoOk = 0;
    int id;
    int indice;
    int opcion;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = findEmployeeById(employees, len, id);

        if( indice == -1)
    {
        printf("No existe un Empledo con ese id\n\n");

    }
    else
    {

        printEmpoyee(employees[indice]);

        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar salario");
        printf("4- Modificar sector");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            scanf("%s", &employees[indice].name);
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            scanf("%s", &employees[indice].lastName);
            break;
        case 3:
            printf("Ingrese nuevo salario");
            scanf("%f", &employees[indice].salary);
            break;
        case 4:
            printf("Ingrese nuevo sector");
            scanf("%d", &employees[indice].sector);
            break;
        case 5:
            printf("se a canselado la modificacion");
        }
    }

}
