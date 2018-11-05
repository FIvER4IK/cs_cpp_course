#ifndef HPP_NODER_NODE

#define HPP_NODER_NODE

#include <cstddef> // std::size_t

namespace noder
{

struct node {
    char value;
    node* next;
};

node* create_node (char letter);

/**
 * Должна возвращать длину цепи nod
 */
std::size_t get_length (node* nod);

/**
 * Должна возвращать: является ли цепь nod цикличной(замкнутой)
 */
bool is_circular (node* nod);

/**
 * Должна печатать на экран символы в цепи nod
 */
void print (node* nod);

/**
 * Должна склеить две цепочки left и right, так,
 *  что при прохождении получившейся цепочки, сначала шли узлы left,
 *  потом right
 */
node* concate (node* left, node* right);

/**
 * Должна ставлять узел nod, перед i-ым узлом цепи chain
 */
void insert (node* nod, std::size_t i, node* chain);

} // noder

#endif // HPP_NODER_NODE
