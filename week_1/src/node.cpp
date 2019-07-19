#include "node.hpp"
#include <iostream>
#include <cstring>
#include <cstddef>



node::node(char letter) {
    value = letter;
    next = nullptr;
}
node::~node(){
    std::cout << "DELETING:" << this << " LETTER:" << value << " NEXT:" << next << "\n";
}


void node::print() const {
    const node* nod = this;
    while (nod) {
        cout << nod->value;
        nod = nod->next;
    }
}



void node::concate(node *right) {
    node* nod = next;
    while(nod->next != nullptr) {
        nod = nod->next;
    }
    nod->next = right;
}

size_t node::get_length() const {
    int i = 1;
    node* nod = next;
    while(nod->next != nullptr) {
        nod = nod->next;
        i++;
    }
    return i;
}

void node::insert(size_t insert_index, node *chain) {
    int j = 0;
    node* nod = this;
    if(insert_index == 0) {
        chain->next = this;
        return ;
    }
    while(nod->next != nullptr && j + 1 < insert_index ) {
        nod = nod->next;
        j++;
    }
    if (nod->next == nullptr) {
        nod->next = chain;
    }
    else{
        chain->next = nod->next;
        nod->next = chain;
    }
}
