#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = DoublyNode<T>;
/*
   《2026王道数据结构》综合题P19T02;
    function:Determine whether the circular doubly linked list with the leading node is symmetrical
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
bool solve(Node<T>* head)
{
    if (head == nullptr) {
        std::cerr << "The pointer of the head node is null" << std::endl;
        return false;
    }

    Node<T>* l = head->next;
    Node<T>* r = head->prev;
    while (l != r && l->prev != r) {
        if (l->data != r->data) {
            return false;
        }
        l = l->next;
        r = r->prev;
    }
    return true;
}
