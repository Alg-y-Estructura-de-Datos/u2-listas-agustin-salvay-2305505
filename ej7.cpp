/*
 * Utiliza la clase ListaDoble para gestionar una lista de estudiantes, donde cada estudiante
tiene un nombre (cadena de caracteres) y una edad (entero). Implementa las siguientes
funcionalidades:
1. Agregar Estudiantes:
○ Usa los métodos de ListaDoble para agregar varios estudiantes a la lista.
Debes insertar al menos cinco estudiantes con nombres y edades diferentes.
2. Mostrar Estudiantes:
○ Implementa una función que recorra la lista y muestre todos los estudiantes en
orden. Utiliza el método imprimir() de ListaDoble.
3. Buscar un Estudiante por Nombre:
○ Implementa una función que busque un estudiante por su nombre. Utiliza el
método getDato(int pos) para acceder a los datos de los nodos y busca al
estudiante en la lista.
4. Eliminar un Estudiante por Nombre:
○ Implementa una función que elimine un estudiante por su nombre. Utiliza los
métodos getDato(int pos) y remover(int pos) para encontrar y
eliminar al estudiante de la lista.
5. Contar Estudiantes:
○ Usa el método getTamanio() para contar el número de estudiantes en la lista
y muestra el resultado.

 */


#include <iostream>
#include "Lista/ListaDoble.h"
#include <string>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;

public:
    Estudiante(const string& nom, int ed) : nombre(nom), edad(ed) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void setNombre(const string& nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }

    // Sobrecarga del operador << para imprimir Estudiante
    friend ostream& operator<<(ostream& os, const Estudiante& e) {
        os << "Nombre: " << e.nombre << ", Edad: " << e.edad;
        return os;
    }
};

// Agregar Estudiantes
void agregarEstudiantes(ListaDoble<Estudiante>& lista) {
    int numEstudiantes;
    string nombre;
    int edad;

    cout << "Ingrese el número de estudiantes a agregar: ";
    cin >> numEstudiantes;
    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        getline(cin, nombre);
        cout << "Ingrese la edad del estudiante " << i + 1 << ": ";
        cin >> edad;
        cin.ignore(); // Limpiar el buffer de entrada
        lista.insertarUltimo(Estudiante(nombre, edad));
    }
}

// Mostrar Estudiantes
void mostrarEstudiantes(const ListaDoble<Estudiante>& lista) {
    cout << "Lista de Estudiantes:" << endl;
    lista.imprimir();
}

// Buscar Estudiante por Nombre
Estudiante* buscarEstudiantePorNombre(const ListaDoble<Estudiante>& lista, const string& nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; ++i) {
        Estudiante est = lista.getDato(i);
        if (est.getNombre() == nombre) {
            return new Estudiante(est); // Devolvemos una copia del estudiante encontrado
        }
    }
    return nullptr; // No se encontró el estudiante
}

// Eliminar Estudiante por Nombre
void eliminarEstudiantePorNombre(ListaDoble<Estudiante>& lista, const string& nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; ++i) {
        Estudiante est = lista.getDato(i);
        if (est.getNombre() == nombre) {
            cout << "Estudiante " << nombre << " eliminado exitosamente" << endl;
            lista.remover(i);
            return; // Eliminar el estudiante y salir
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

// Contar Estudiantes
void contarEstudiantes(const ListaDoble<Estudiante>& lista) {
    cout << "Numero de estudiantes: " << lista.getTamanio() << endl;
}

int main() {
    ListaDoble<Estudiante> listaEstudiantes;
    int opcion;
    string nombre;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Contar estudiantes\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                agregarEstudiantes(listaEstudiantes);
                break;
            case 2:
                mostrarEstudiantes(listaEstudiantes);
                break;
            case 3:
                cout << "Ingrese el nombre del estudiante a buscar: ";
                getline(cin, nombre);
                if (Estudiante* estudianteEncontrado = buscarEstudiantePorNombre(listaEstudiantes, nombre)) {
                    cout << "Estudiante encontrado: " << *estudianteEncontrado << endl;
                    delete estudianteEncontrado; // Liberar la memoria
                } else {
                    cout << "Estudiante no encontrado." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el nombre del estudiante a eliminar: ";
                getline(cin, nombre);
                eliminarEstudiantePorNombre(listaEstudiantes, nombre);
                break;
            case 5:
                contarEstudiantes(listaEstudiantes);
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