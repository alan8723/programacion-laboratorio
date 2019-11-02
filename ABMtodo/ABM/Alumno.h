#include <stdio.h>
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int libre;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno);
