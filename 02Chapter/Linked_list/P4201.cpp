#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P42T01;
    function:Delete the element with a value of X in the singly linked list with the leading node and free up space；
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

template <typename T>
void solve(Node<T>* head, T x)
{
    if (head == nullptr) {
        std::cerr << "错误：表头节点指针为空！" << std::endl;
        return;
    }

    Node<T>* t = head;
    while (t->next != nullptr) {
        if (t->next->data == x) {
            Node<T>* del = t->next;
            t->next = del->next;
            delete del;
            continue;
        }
        t = t->next;
    }
}