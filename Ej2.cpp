/* Implementar una función que recibe una lista de números enteros y un número
 * entero “n” y que modifique la lista borrando todos los elementos de la lista
 * que tengan el número “n”. Imprimir la lista antes de hacer el llamado a la función
 * y luego del llamado a la función para mostrar que la lista original cambió. ej:
 * lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe pasar con la función a 1->2->
 * 4->5->7->8.*/


#include <iostream>
#include "lista/Lista.h"
using namespace std;

void eliminarElementos(Lista <int> &lista, int p,int n) {

    for (int i = 0; i < n; i++) {
        if (p == lista.getDato(i) ) {
            lista.remover(i);
            i--;
            n--;
        }

    }
}

int main() {

  Lista <int> lista;
    int n, d, p;
    cout << "ingrese el tamaño de la lista" << endl;
    cin >>n;

    for (int i = 0; i < n; i++) {
        cout << "ingrese el numero " << i + 1 << ": ";
        cin >> d;
        lista.insertarUltimo(d);
    }

    cout << "ingrese el numero que desea remover de la lista" << endl;
    cin >> p;
    eliminarElementos(lista, p, n);
    lista.print();
    return 0;
}
