//
// Created by Agustin Miranda on 26/08/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


// File: DoubleLinkedList.h
#pragma once
#include "Node.h"
#include <iostream>

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addPage(const std::string& url) {
        Node* newNode = new Node(url);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            current = tail;
        }
    }

    void showHistory() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->url << std::endl;
            temp = temp->next;
        }
    }

    void goBack() {
        if (current && current->prev) {
            current = current->prev;
            std::cout << "Current URL: " << current->url << std::endl;
        } else {
            std::cout << "No previous page." << std::endl;
        }
    }

    void goForward() {
        if (current && current->next) {
            current = current->next;
            std::cout << "Current URL: " << current->url << std::endl;
        } else {
            std::cout << "No next page." << std::endl;
        }
    }
};


#endif //DOUBLELINKEDLIST_H
