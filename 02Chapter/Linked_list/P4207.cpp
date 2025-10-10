#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P43T07;
    function:Delete the duplicate elements in the incrementally ordered singly linked list;
    Time Complexity :O(len);
    Space Complexity:O(1);
*/

template <typename T>
void solve(Node<T>* head)
{
    if (head->next == nullptr) {
        std::cout << "Note:Empty List";
        return;
    }

    Node<T>* cur = head;
    while (cur->next != nullptr) {
        if (cur->data == cur->next->data) {
            Node<T>* del = cur->next;
            cur->next = del->next;
            delete del;
            continue;
        }
        cur = cur->next;
    }
}