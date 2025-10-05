#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P42T04;
    function:Delete the nodes in the singly linked list whose node values fall within the given closed interval;
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

template <typename T>
void solve(Node<T>* head, T low, T high)
{
    if (head == nullptr) {
        std::cerr << "The pointer of the head node is null" << std::endl;
        return;
    }
    if (head->next == nullptr) {
        std::cout << "Note:Empty List";
        return;
    }

    Node<T>* node = head;
    while (node->next != nullptr) {
        T& val = node->next->data;
        if (val >= low && val <= high) {
            Node<T>* del = node->next;
            node->next = node->next->next;
            delete del;
            continue;
        }
        node = node->next;
    }
}