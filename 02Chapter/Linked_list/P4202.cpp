#include "node.h"
#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P42T02;
    function:Delete the minimum node (unique) in the singly linked list with the leading node;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
using Node = SinglyNode<T>;

template <typename T>
void solve(Node<T>* head)
{
    if (head == nullptr) {
        std::cerr << "The pointer of the head node is null" << std::endl;
        return;
    }
    if (head->next == nullptr) {
        std::cout << "Note:Empty List";
        return;
    }

    Node<T>* p = head;
    Node<T>* del_prev;
    T min_val = p->next->data;

    // Determine the minimum node value
    while (p->next != nullptr) {
        if (p->next->data < min_val) {
            min_val = p->next->data;
            del_prev = p;
        }
        p = p->next;
    }

    Node<T>* del = del_prev->next;
    del_prev->next = del->next;
    delete del;
}
