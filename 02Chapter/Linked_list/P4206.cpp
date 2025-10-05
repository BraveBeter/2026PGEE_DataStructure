#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P19T02;
    function:turn {a1, b1, a2, b2, ......, an, bn} into {a1, a2, ......, an} , {b1, b2, ......, bn};
    Time Complexity :O(len);
    Space Complexity:O(1);
*/
template <typename T>
std::pair<Node<T>*, Node<T>*> solve(Node<T>* head)
{
    if (head == nullptr) {
        std::cerr << "The pointer of the head node is null" << std::endl;
        return { nullptr, nullptr };
    }

    Node<T>* a = new Node<T>();
    Node<T>* b = new Node<T>();
    if (head->next == nullptr) {
        std::cout << "Note:Empty List";
        return { a, b };
    }

    Node<T>* prev_a = a;
    Node<T>* prev_b = b;
    Node<T>* cur = head->next;
    while (cur != nullptr && cur->next != nullptr) {
        prev_a->next = cur;
        prev_b->next = cur->next;

        prev_a = cur;
        prev_b = cur->next;

        cur = cur->next->next;
    }
    // 扩展：可以处理节点数目为奇数的情况
    if (cur != nullptr) {
        prev_a->next = cur;
        prev_a = cur;
    }

    prev_a->next = nullptr;
    prev_b->next = nullptr;
    delete head;
    return { a, b };
}