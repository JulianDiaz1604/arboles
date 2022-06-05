#include <iostream>

using namespace std;

struct Nodo{
    string nombre;
    int id;
    Nodo *izquierda;
    Nodo *derecha;
};

// Julian
void menu();

//Listo, comprobar funcionamiento
void insertar(Nodo *&arbol, string nombre, int id);

// Simon
void mostrar(Nodo *arbol, int cont);

// Jarod
void encontrarRuta(Nodo *arbol, string origen, string destino);

//Listo, comprobar funcionamiendo
void crearArbol();

//Listo, comprobar funcionamiento
Nodo *crearNodo(string nombre, int id);

Nodo *arbol = NULL;


int main(){
    menu();
}

void insertar(Nodo *&arbol, string nombre, int id){
    if (arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(nombre, id);
        arbol = nuevo_nodo;
    } else {
        int  valorRaiz = arbol -> id;
        if (id < valorRaiz){
            insertar(arbol -> izquierda, nombre, id);
        } else {
            insertar(arbol -> derecha, nombre, id);
        }
    }
}

void mostrar(Nodo *arbol, int n){

}

void menu(){
    crearArbol();

}

void crearArbol(){
    insertar(*&arbol, "Oriente", 21);
    insertar(*&arbol, "Guarne", 10);
    insertar(*&arbol, "San Vicente", 22);
    insertar(*&arbol, "Rionegro", 2);
    insertar(*&arbol, "Marinilla", 17);
    insertar(*&arbol, "El Retiro", 1);
    insertar(*&arbol, "La Ceja", 8);
    insertar(*&arbol, "La Union", 6);
    insertar(*&arbol, "El Carmen", 9);
    insertar(*&arbol, "Sonson", 4);
    insertar(*&arbol, "Abejorral", 7);
    insertar(*&arbol, "Argelia", 3);
    insertar(*&arbol, "Narino", 5);
    insertar(*&arbol, "Santuario", 14);
    insertar(*&arbol, "El Penol", 18);
    insertar(*&arbol, "Cocorna", 12);
    insertar(*&arbol, "Granada", 15);
    insertar(*&arbol, "San Francisco", 11);
    insertar(*&arbol, "San Luis", 13);
    insertar(*&arbol, "San Carlos", 16);
    insertar(*&arbol, "Guatape", 19);
    insertar(*&arbol, "San Rafael", 20);
    insertar(*&arbol, "Concepcion", 23);
    insertar(*&arbol, "Alejandria", 24);
}

Nodo *crearNodo(string nombre, int id){

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> nombre = nombre;
    nuevo_nodo -> id = id;
    nuevo_nodo -> derecha = NULL;
    nuevo_nodo -> izquierda = NULL;

    return nuevo_nodo;
}
