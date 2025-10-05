#include "node.h"
#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P42T02;
    function:Delete the minimum node (unique) in the singly linked list;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/
template <typename T>
using Node = SinglyNode<T>;

template <typename T>
void solve(Node<T>* head)
{
    if (head == nullptr || head->next == nullptr) {
        std::cerr << "Empty List";
        return;
    }

    Node<T>* p = head;
    T min_val = p->next->data;

    // Determine the minimum node value
    while (p->next != nullptr) {
        min_val = std::min(min_val, p->next->data);
        p = p->next;
    }

    // Delete the minimum value node
    p = head;
    while (p->next != nullptr) {
        if (p->next->data == min_val) {
            Node<T>* del = p->next;
            p->next = p->next->next;
            delete del;
            break;
        }
        p = p->next;
    }
}
