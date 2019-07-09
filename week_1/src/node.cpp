#include "node.hpp"
#include <iostream>
#include <cstring>

using namespace std;

class node{

private:

char value;
node* next;

public:

int size_t index(node* nod, node* element) {
    size_t size = 1;
    while (nod){
        if (element == nod)
            return size;
        nod = nod->next;
        size++;
    }
    if (element == nullptr)
        return size - 1;
    return 0;
}

int create_node (char letter) {
    node* result = new node;
    result->value = letter;
    result->next = nullptr;
    return result;
}

size_t get_length (node* nod) {
    return index(nod, nullptr);
}

bool is_circular (node* nod) {
    return index(nod->next, nod) != 0;
}

void print (node* nod) {
    while (nod) {
        cout << nod->value;
        nod = nod->next;
    }
}

node concate (node* left, node* right) {
    node* result = left;
        return result;
        // Написать
    }

void insert (node* nod, std::size_t i, node* chain) {
    node* i = chain;

    }

};
