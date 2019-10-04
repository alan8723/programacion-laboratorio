#include <stdio.h>
#include <stdlib.h>

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

int addEmployees(Employee employees[], int len, int id, char nombre[], char lastName, float salary, int sector);

int findEmployeeById(Employee employees[], int len, int id);

int removeEmployee(Employee employees[], int len, int id);

int sortEmployees(Employee employees[], int len, int order);

int printEmployees(Employee employees[], int length);

int printEmpoyee(int id, char name[], char lastname[], float salary, int sector);

int seachFree(Employee employees[], int len);


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
    int i = 0;
    int todoOK = -1;
    int flag = 1;

    for(i < len; i++;){
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
    int i = 0;

    for (i < len; i++;){
        if(employees[i].isEmpty == 1){
           indice = i;
           break;
        }
    }
    return indice;
}

int addEmployees(Employee employees[], int len, int id, char nombre[], char lastName, float salary, int sector){
    int indice;
    int todoOk = 0;

    indice = seachFree(employees, len);

    if(indice !=-1){


        strcpy(employees[indice].name, nombre);

        strcpy (employees[indice].lastName, lastName);

        employees[indice].salary = salary;

        employees[indice].sector = sector;

        employees[indice].id = id;

        employees[indice].isEmpty = 0;
        todoOk = 1;
    }
    else{
        todoOk = -1;
    }

    return todoOk;

}

int findEmployeeById(Employee employees[], int len, int id){
    int i = 0;
    int indise = -1;

    for(i < len; i++;){
        if (employees[i].id == id && employees[i].isEmpty == 1){
            indise = i;
            break;
        }
    }

    return indise;
}

int removeEmployee(Employee employees[], int len, int id){
    int baja;
    int todoOk = -1;

    baja = findEmployeeById(employees, len, id);

    if(employees[baja].id == id){
        employees[baja].isEmpty == -1;
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
    int i = 0;
    int todoOk;

    for(i < length; i++;){
        if(employees[i].isEmpty == 1){
            printEmpoyee(employees[i].id, employees[i].name, employees[i].lastName, employees[i].salary, employees[i].sector);
        }
    }
}

int printEmpoyee(int id, char name[], char lastname[], float salary, int sector){
    printf("%s  \t\t\n\n  %s  \t\t\n\n  %f  \t\t\n\n  %d  \t\t\n\n  ", id, name, lastname, salary, sector);
}
