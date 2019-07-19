#include <iostream>
#include <vector>
#include "node.hpp"

int main ()
{


    std::vector<node*> arr;

    node* he =  new node('h');

    he->set_next(new node('e'));

    node* lo = new node('l');
    lo->set_next(new node('o'));

    std::cout << "\n";


    he->concate(lo);

    he->concate(new node('!'));

    he->insert(3, new node('l'));

    he->print();

    std::cout << "\n" << he->get_length() << "\n";

    /*node *save = he->get_next();
    while(save != nullptr) {
        delete he;
        he = save;
        save = he->get_next();
    }*/


    while(he != nullptr) {
        arr.push_back(he);
        he = he->get_next();
    }
    for(node* i : arr){
        delete i;
    }
}
