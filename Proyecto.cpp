#include <iostream>
#include <string>
using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string email;
    Contacto* siguiente;
};

struct NodoArbol {
    Contacto* contacto;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};

struct Operacion {
    string tipo;
    string contacto;
    Operacion* siguiente;
};

const int MAX_CONTACTOS = 100;
Contacto* contactos[MAX_CONTACTOS];
int totalContactos = 0;

Contacto* listaEliminados = NULL;
Operacion* pilaHistorial = NULL;
Contacto* frenteCola = NULL;
Contacto* finalCola = NULL;
NodoArbol* arbolContactos = NULL;

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << "\nPresione enter para continuar";
    cin.ignore();
    cin.get();
}
void agregarContacto() {
    if (totalContactos >= MAX_CONTACTOS) {
        cout << "No se pueden agregar mas contactos\n";
        return;
    }

    Contacto* nuevo = new Contacto;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevo->nombre);
    cout << "Telefono: ";
    getline(cin, nuevo->telefono);
    cout << "Email: ";
    getline(cin, nuevo->email);
    nuevo->siguiente = NULL;

    //Hasta aquí, de aquí sigue total contactos