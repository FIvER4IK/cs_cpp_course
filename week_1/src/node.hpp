#pragma once

#include <cstddef>

#include <iostream>

using namespace std;

class node {

private:
    char value;
    node *next;

public:

    void set_next (node* set) {
        next = set;
    }

    node* get_next () const {
        return next;
    }
    ~node();

    void print() const;

    void concate(node *right);

    explicit node(char letter);

    size_t get_length() const;

    void insert(size_t i, node *chain);
};