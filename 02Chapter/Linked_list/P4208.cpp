#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P43T08;
    function:Generate A singly linked list C from the common elements in incrementally sorted singly linked columns A and B with a leading node
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

template <typename T>
Node<T>* solve(Node<T>* A, Node<T>* B)
{
    Node<T>* C = new Node<T>();
    if (A == nullptr || B == nullptr) {
        std::cerr << "The pointer of the head node is null" << std::endl;
        return C;
    }
    if (A->next == nullptr || B->next == nullptr) {
        std::cout << "Note:Empty List";
        return C;
    }
    Node<T>* aPointer = A->next;
    Node<T>* bPointer = B->next;
    Node<T>* cPointer = C;
    while (aPointer != nullptr && bPointer != nullptr) {
        T aVal = aPointer->data, bVal = bPointer->data;
        if (aVal < bVal) {
            aPointer = aPointer->next;
        } else if (aVal > bVal) {
            bPointer = bPointer->next;
        } else {
            Node<T>* newnode = new Node<T>(aVal);
            cPointer->next = newnode;

            aPointer = aPointer->next;
            bPointer = bPointer->next;
            cPointer = cPointer->next;
        }
    }
    return C;
}
