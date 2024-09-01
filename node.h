//
// Created by Agustin Miranda on 26/08/2024.
//

#ifndef NODE_H
#define NODE_H



// File: Node.h
#pragma once
#include <string>

class Node {
public:
    std::string url;
    Node* prev;
    Node* next;

    Node(const std::string& url) : url(url), prev(nullptr), next(nullptr) {}
};



#endif //NODE_H
