#include "node.hpp"

#include <iostream>

namespace noder
{

namespace
{

/**
 * Находит позицию на которой узел element находится в цепи nod
 * Индексация начинается с 1, 0 - не найден
 */
std::size_t index(node* nod, node* element) {
    std::size_t size = 1;
    while (nod)
    {
        if (element == nod)
            return size;
        nod = nod->next;
        size++;
    }
    if (element == nullptr)
        return size - 1;
    return 0;
}

} // namespace


node* create_node (char letter) {
    node* result = new node;
    result->value = letter;
    result->next = nullptr;
    
    return result;
}

std::size_t get_length (node* nod) {
    return index(nod, nullptr);
}

bool is_circular (node* nod) {
    return index(nod->next, nod) != 0;
}

void print (node* nod) {
    while (nod) {
        std::cout << nod->value;
        nod = nod->next;
    }
}

node* concate (node* left, node* right) {
    node* result = left;
    return result;
    // Написать
}

void insert (node* nod, std::size_t i, node* chain) {
    // Написать
}

} // noder
