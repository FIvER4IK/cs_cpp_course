#include <iostream>
#include "node.hpp"

int main ()
{
    noder::node* hello = noder::create_node('h');
    noder::node* assign = hello;
    assign = assign->next = noder::create_node('e');
    assign = assign->next = noder::create_node('l');
    assign = assign->next = noder::create_node('l');
    assign = assign->next = noder::create_node('o');

    noder::node* world = noder::create_node('w');
    assign = world;
    assign = assign->next = noder::create_node('o');
    assign = assign->next = noder::create_node('r');
    assign = assign->next = noder::create_node('l');
    assign = assign->next = noder::create_node('d');
    assign->next = world; // world зацикливается

    // Задача на подумать, что будет если сделать так? Какая функция не справиться с таким графом?
    // assign->next = assign;


    

    if (!noder::is_circular(hello)) // Если нет цикла
        noder::print (hello); // Печатаем 

    if (!is_circular(world)) // Если нет цикла
        noder::print (world); // Печатаем 

    std::cout << "\n";

    assign->next = nullptr; // Снимаем цикличность

    noder::concate(hello, world);
    noder::concate(hello, noder::create_node('\n'));
    noder::insert(noder::create_node(' '), 5, hello);

    noder::print(hello); // Должно распечатать hello world\n

}
