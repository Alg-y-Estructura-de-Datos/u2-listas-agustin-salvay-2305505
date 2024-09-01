/*
 * Crea un programa que gestione una lista circular de contactos. Cada contacto contiene un
nombre (cadena de caracteres) y un número de teléfono (cadena de caracteres).
Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.
2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.
3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.
4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).
5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado
 */


#include <iostream>
#include "Lista/CircList.h"
#include <string>

using namespace std;

class contacto {
public:
    string nombre;
    string telefono;

    contacto() : nombre(""), telefono("") {}
    contacto(const string &nombre, const string &telefono) : nombre(nombre), telefono(telefono) {}

    friend ostream &operator<<(ostream &os, const contacto &c) {
        os << "Nombre: " << c.nombre << " - Telefono: " << c.telefono;
        return os;
    }

    bool operator==(const contacto &c) const {
        return nombre == c.nombre;
    }
};

void mostrarContactos(CircList<contacto> &lista) {
    if (lista.esVacia()) {
        cout << "No hay contactos para mostrar." << endl;
        return;
    }
    lista.imprimir();
}

bool buscarContacto(CircList<contacto> &lista, const string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            cout << "Contacto encontrado: " << c << endl;
            return true;
        }
    }
    cout << "Contacto no encontrado." << endl;
    return false;
}

void eliminarContacto(CircList<contacto> &lista, const string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            lista.eliminarPorValor(c);
            cout << "Contacto eliminado: " << c << endl;
            return;
        }
    }
    cout << "Contacto no encontrado." << endl;
}

int main() {
    CircList<contacto> lista;
    int opcion;
    string nombre, telefono;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar contactos\n";
        cout << "3. Buscar contacto\n";
        cout << "4. Eliminar contacto\n";
        cout << "5. Contar contactos\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del contacto: ";
                getline(cin, nombre);
                cout << "Ingrese el telefono del contacto: ";
                getline(cin, telefono);
                lista.insertarUltimo(contacto(nombre, telefono));
                break;
            case 2:
                cout << "Lista de contactos:\n";
                mostrarContactos(lista);
                break;
            case 3:
                cout << "Ingrese el nombre del contacto a buscar: ";
                getline(cin, nombre);
                buscarContacto(lista, nombre);
                break;
            case 4:
                cout << "Ingrese el nombre del contacto a eliminar: ";
                getline(cin, nombre);
                eliminarContacto(lista, nombre);
                break;
            case 5:
                cout << "Numero total de contactos: " << lista.getTamanio() << endl;
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    return 0;
}