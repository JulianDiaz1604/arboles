#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct Nodo{
    string nombre;
    int id;
    Nodo *izquierda;
    Nodo *derecha;
};

void menu();
void insertar(Nodo *&arbol, string nombre, int id);
void mostrar(Nodo *arbol, int aux);
void encontrarRuta(Nodo *arbol, string origen, string destino);
void crearArbol();
Nodo *crearNodo(string nombre, int id);
void gotoxy(int x, int y);
void inOrden(Nodo *arbol);

Nodo *arbol = NULL;
int auxX = 0;//Variable publica.

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

void mostrar(Nodo *arbol, int auxY) {//auxY es el nivel del arbol

    if (arbol == NULL) {//Arbol vacio nada que mostrar
        return;
    }

    auxX += 5;//variable que permite posicionarse en el eje X

    mostrar(arbol->izquierda, auxY + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores

    gotoxy(5 + auxX - auxY, 3 + auxY);//posiciona el nodo segun sus variables en X y en Y

    cout << arbol->id << endl << endl;//Muestra el dato del nodo respectivo

    mostrar(arbol->derecha, auxY + 2);//Se para hasta el nodo mas a la derecho del árbol
    //Se debe tener el cuenta el funcionamiento de la recursividad la cual implementa una pila para almacenar las instrucciones
}

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void inOrden(Nodo *arbol){
    if (arbol == NULL){
        return;
    } else {
        inOrden(arbol -> izquierda);
        cout << "        " << arbol -> nombre << ": " << arbol -> id << endl;
        inOrden(arbol ->derecha);
    }
}

void encontrarRuta(Nodo *arbol, string origen, string destino){

}

void menu(){
    crearArbol();
    int opcion;

    do {
        FILE *banner = fopen("C:\\Users\\diazj\\Documents\\Arboles\\banner.txt", "r");
        int aux;
        while ((aux = fgetc(banner)) != EOF) {
            putchar(aux);
        }
        cout << endl << endl << endl;
        cout << "  |  |                                                                       |  |  " << endl;
        cout << "  |  |                                                                       |  |  " << endl;
        cout << "  |  |                         1. Encontrar mi ruta                          |  |  " << endl;
        cout << "  |  |                           2. Mostrar arbol                            |  |  " << endl;
        cout << "  |  |                              3. Salir                                 |  |  " << endl;
        cout << "  |  |                                                                       |  |  " << endl;
        cout << "  |  |                                                                       |  |  " << endl;
        cout << "                              Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
            {
                system("cls");
                string origen;
                string destino;
                cout << "\n   _________________________________________________";
                cout << "\n   -------------------------------------------------";
                cout << "\n\n      Ingrese el municipio de origen: ";
                cin >> origen;
                cout << "\n\n      Ingrese el municipio de destino: ";
                cin >> destino;
                encontrarRuta(arbol, origen, destino);
                cout << "\n   _________________________________________________";
                cout << "\n   -------------------------------------------------\n\n";
                system("pause");

                break;
            }

            case 2:
            {
                system("cls");
                cout << "\n   ____________________________________________________________________________________________________________________________";
                cout << "\n   ----------------------------------------------------------------------------------------------------------------------------";
                mostrar(arbol, 6);
                cout << "\n\n\n\n\n\n\n\n   ____________________________________________________________________________________________________________________________";
                cout << "\n   ----------------------------------------------------------------------------------------------------------------------------\n\n";
                inOrden(arbol);
                cout << endl;
                system("pause");

                break;
            }

            case 3:
            {
                system("cls");
                cout << "\n   _________________________________________________";
                cout << "\n   -------------------------------------------------";
                cout << "\n\n                      Saliendo...               \n";
                cout << "\n   _________________________________________________";
                cout << "\n   -------------------------------------------------\n\n";
                system("pause");

                break;
            }

            default:
            {
                cout << "\n\n\n                            Ingrese una opcion valida\n\n";
                system("pause");

                break;
            }

        }
        system("cls");
    } while (opcion != 3);
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
