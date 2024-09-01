/*
 * Sistema de Monitor Publicitario Circular
Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
circular simplemente enlazada.
Requisitos:
1. Frases de Anuncios:
○ Cada frase de anuncio será un texto simple que el monitor debe mostrar por
vez.
2. Mostrar Circularmente:
○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
mostrado la última frase, el monitor debe volver a mostrar la primera y así
infinitamente.
3. Implementación:
○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
y la visualización de las frases. La lista circular debe permitir el recorrido
continuo de los elementos.
4. Operaciones Básicas:
○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
○ Mostrar Frases: Implementa una función para mostrar las frases en el monitor
de manera continua, recorriendo circularmente la lista e infinitamente
 */

#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

using namespace std;

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
        this_thread::sleep_for(chrono::seconds(3)); // Retraso de 1 segundo
    }
}

int main (){
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