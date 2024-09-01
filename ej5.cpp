/*
 * Crear un programa que pida al usuario dar elementos a una Lista de números enteros. Luego
cree una función que reciba una lista int L1 y devuelva otra lista int L2 conteniendo los
elementos repetidos de L1. Por ejemplo, si L1 almacena los valores 5->2->7-> 2->5->5->1, debe
construirse una lista L2 con los valores 5->2. Si en L1 no hay elementos repetidos se debe
indicar al usuario que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.
 */



#include <iostream>
#include "lista/lista.h"


using namespace std;

Lista<int> elementosRepetidos(Lista<int> &L1) {
    Lista<int> L2;
    Lista<int> yaVistos;

    for (int i = 0; i < L1.getTamanio(); i++) {
        int dato = L1.getDato(i);
        bool yaVisto = false;

        for (int j = 0; j < yaVistos.getTamanio(); j++) {
            if (yaVistos.getDato(j) == dato) {
                yaVisto = true;
                break;
            }
        }

        if (yaVisto) {
            bool repetido = false;
            for (int j = 0; j < L2.getTamanio(); j++) {
                if (L2.getDato(j) == dato) {
                    repetido = true;
                    break;
                }
            }
            if (!repetido) {
                L2.insertarUltimo(dato);
            }
        } else {
            yaVistos.insertarUltimo(dato);
        }
    }

    return L2;
}

int main() {
    Lista<int> L1;
    int n, d;

    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> d;
        L1.insertarUltimo(d);
    }

    if (L1.esVacia()) {
        cout << "La lista esta vacia" << endl;
        return 0;
    }

    Lista<int> L2 = elementosRepetidos(L1);

    cout << "La lista 1 es: ";
    L1.print();

    if (L2.esVacia()) {
        cout << "No hay elementos repetidos en la lista 1" << endl;
    } else {
        cout << "Los elementos repetidos en la lista 1 son: ";
        L2.print();
    }

    return 0;
}