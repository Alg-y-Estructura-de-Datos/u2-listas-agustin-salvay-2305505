// File: main.cpp
#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {
    DoubleLinkedList history;
    string command, url;

    while (true) {
        cout << "Enter command (add/show/back/forward/exit): ";
        cin >> command;

        if (command == "add") {
            cout << "Enter URL: ";
            cin >> url;
            history.addPage(url);
        } else if (command == "show") {
            history.showHistory();
        } else if (command == "back") {
            history.goBack();
        } else if (command == "forward") {
            history.goForward();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
