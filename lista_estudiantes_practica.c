#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{

    char *nombre;
    int creditos;
    int semestre;

};

typedef struct alumno Alumno;
typedef Alumno *AlumnoPtr;

struct nodo
{
    Alumno est;
    struct nodo *enlace;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

NodoPtr crearNodo(AlumnoPtr);
AlumnoPtr crearAlumno(char*, int, int);
void insertarNodoOrdenadoCreditos(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);

int main(){

    NodoPtr cabecera = NULL;

    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Isaias", 94, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Mauro", 89, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Mariana", 92, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Jaqui", 96, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Ruz", 100, 3)));
    imprimirLista(cabecera);




    return 0;
}

AlumnoPtr crearAlumno(char *nombre, int creditos, int semestre){

    AlumnoPtr nuevoAlumno = (AlumnoPtr)malloc(sizeof(Alumno));

    nuevoAlumno -> nombre = strdup(nombre);
    nuevoAlumno -> creditos = creditos;
    nuevoAlumno -> semestre = semestre;

    return nuevoAlumno;
}

NodoPtr crearNodo(AlumnoPtr nuevoAlumno){

    NodoPtr nuevoNodo = (NodoPtr)malloc(sizeof(Nodo));

    nuevoNodo -> est.nombre = strdup(nuevoAlumno -> nombre);
    nuevoNodo -> est.creditos = nuevoAlumno -> creditos;
    nuevoNodo -> est.semestre = nuevoAlumno-> semestre;
    nuevoNodo -> enlace = NULL;

    return nuevoNodo;
}

void insertarNodoOrdenadoCreditos(NodoPtr* cabecera, NodoPtr nuevoNodo){

    if(*cabecera == NULL){
        *cabecera = nuevoNodo;
    }
    else{
        NodoPtr actualNodo = *cabecera, anteriorNodo = NULL;

        while(actualNodo != NULL && nuevoNodo->est.creditos < actualNodo->est.creditos){

            anteriorNodo = actualNodo;
            actualNodo = actualNodo -> enlace;
        }

        if(actualNodo == NULL || (actualNodo != NULL && anteriorNodo != NULL)){

            nuevoNodo -> enlace = anteriorNodo -> enlace;
		    anteriorNodo -> enlace = nuevoNodo;
        }
        else{
            nuevoNodo -> enlace = actualNodo;
		    *cabecera = nuevoNodo;	
        }

    }

}

void imprimirLista(NodoPtr cabecera){

    int i = 1;
    if(cabecera == NULL){
        //Verificamos si la lista está vacía
        printf("La lista esta vacia\n");
        return;

    }
    else{

        printf("\nLista de alumnos\n");

        while(cabecera != NULL){

            printf("%d.- %s - %d - %d\n", i, cabecera->est.nombre, cabecera->est.creditos, cabecera->est.semestre );
            cabecera = cabecera -> enlace;
            i++;
        }
    }
}



