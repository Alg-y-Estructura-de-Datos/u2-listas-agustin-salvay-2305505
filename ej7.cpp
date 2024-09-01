using namespace std;
#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

// Función para mostrar las frases en el monitor de manera circular
template <typename T>
void mostrarFrasesCircular(CircList<T>& lista) {
    if (lista.esVacia()) {
        cout << "No hay frases para mostrar." << endl;
        return;
    }

    int pos = 0; // Empezamos desde la posición 0

    while (true) { // Bucle infinito para mostrar las frases circularmente
        cout << lista.getDato(pos) << endl; // Mostrar el dato en la posición actual
        pos = (pos + 1) % lista.getTamanio(); // Avanzar a la siguiente posición, circularmente

        // Introducir un retraso de 1 segundo
        this_thread::sleep_for(chrono::seconds(1)); // Retraso de 1 segundo
    }
}

// Función principal
int main() {
    CircList<string> lista;
    int n;
    string mensaje;

    cout << "Ingrese el número de mensajes: ";
    cin >> n;
    cin.ignore(); // Ignorar el salto de línea después de leer el número

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el mensaje " << i + 1 << ": ";
        getline(cin, mensaje);
        lista.insertarUltimo(mensaje);
    }

    cout << "Mostrando frases de anuncios en el monitor:" << endl;

    // Mostrar las frases en el monitor de manera circular
    mostrarFrasesCircular(lista);

    return 0;
}