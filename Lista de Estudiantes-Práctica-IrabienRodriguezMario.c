#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno { //STRUCUT DE EL ALUMNO
    char* Nombre;
    int CreditosAprobados;
    int SemestreEquivalente;
} Alumno;

typedef struct Lista { //NODO DE LA LISTA DE ALUMNOS
    Alumno Datos;
    struct Nodo* siguientePtr;
} Lista;

typedef Lista* ListaPtr;

Alumno crearAlumno(const char* nombre, int creditos, int semestreEq);
ListaPtr crearNodo(Alumno alumno);
void agregarListaOrdenada(ListaPtr* inicio, ListaPtr nuevoAlum);
void imprimirLista(ListaPtr inicio);

int main() {

    ListaPtr lista = NULL;
    Alumno alumnos[5] = { //ARREGLO DE ALUMNNOS
        crearAlumno("Mario Irabien Rodriguez", 70, 2),
        crearAlumno("Victor Hugo Rosado Pech", 32, 1),
        crearAlumno("Iliana Itzel Yanes Lopes", 76, 3),
        crearAlumno("Andry Azael Rabanales Herrera", 10, 1),
        crearAlumno("Andy Perez Baeza", 157, 5)
    };
    printf("\n");
    
    agregarListaOrdenada(&lista, crearNodo(alumnos[0]));
    agregarListaOrdenada(&lista, crearNodo(alumnos[1]));
    agregarListaOrdenada(&lista, crearNodo(alumnos[2]));
    agregarListaOrdenada(&lista, crearNodo(alumnos[3]));
    agregarListaOrdenada(&lista, crearNodo(alumnos[4]));

    

    imprimeLista(lista);

    return 0;
}

Alumno crearAlumno(const char* nombre, int creditos, int semestre) { //CREA LA STRUC DE ALUMNO
    Alumno nuevoAlumno;
    printf("Estructura de alumno creada en: %p\n", (void*)&nuevoAlumno);
    nuevoAlumno.Nombre = strdup(nombre);
    nuevoAlumno.CreditosAprobados = creditos;
    nuevoAlumno.SemestreEquivalente = semestre;
    return nuevoAlumno;
}

ListaPtr crearNodo(Alumno alumno) { //CREA EL NODO DE LA LSITA
    ListaPtr nuevoNodo = (ListaPtr)malloc(sizeof(Lista));
    if (nuevoNodo != NULL) {
        nuevoNodo->Datos = alumno;
        nuevoNodo->siguientePtr = NULL;
    }
    printf("Nodo de lista creado en %p\n", (void*)nuevoNodo);
    return nuevoNodo;
}

void agregarListaOrdenada(ListaPtr* inicio, ListaPtr nuevoAlum) {
    if (*inicio != NULL) { //VERIFICA SI HAY ALGUN ELEMENTO EN LA LISTA
        if (nuevoAlum->Datos.CreditosAprobados > (*inicio)->Datos.CreditosAprobados) { //VERIFICA SI ES EL ELEMENTO MAS GRANDE DE LA LISTA
            nuevoAlum->siguientePtr = *inicio;
            *inicio = nuevoAlum;
        } else {
            ListaPtr puntero = *inicio;
            ListaPtr anterior = NULL;

            while (puntero != NULL && puntero->Datos.CreditosAprobados > nuevoAlum->Datos.CreditosAprobados) {//COMPARA CON LA LISTA
                anterior = puntero;
                puntero = puntero->siguientePtr;
            }

            if (anterior != NULL) {//ASIGNA LALISTA ANTERIOR AL NUEVO NODO
                anterior->siguientePtr = nuevoAlum;
            } else { //VERIFICA DE ANTEMANO SI NO ES EL PRIMERO
                *inicio = nuevoAlum;
            }
            nuevoAlum->siguientePtr = puntero;
        }
    } else {
        *inicio = nuevoAlum;
    }
}

void imprimeLista(ListaPtr primero){ //IMPRIME LA LISTA DE ALUMNOS DE FORMA DESCENDENTE
    ListaPtr lista = primero;
    printf("\n\nLISTA DE ALUMNOS DE FORMA DESCENDENTE:\n"); 
    while(lista != NULL){
        printf("%s %i %i\n", lista->Datos.Nombre, lista->Datos.CreditosAprobados,lista->Datos.SemestreEquivalente);
        lista = lista->siguientePtr;
    }
}