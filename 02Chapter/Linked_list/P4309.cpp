#include "node.h"
#include <iostream>
#include <vector>
template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P43T09;
    function:Find the intersection from the incrementing linked lists A and B without duplicate elements and store it in A
    Time Complexity :O(n);
    Space Complexity:O(1);
*/

template <typename T>
void solve(Node<T>*& A, Node<T>* B)
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Node<T>* aPointer = A;
    Node<T>* bPointer = B;

    while (aPointer != nullptr && bPointer != nullptr) {
        T aVal = aPointer->data, bVal = bPointer->data;
        if (aVal > bVal) {
            bPointer = bPointer->next;
        } else if (aVal < bVal) {
            Node<T>* del = aPointer;
            aPointer = aPointer->next;
            delete del;
        } else {
            if (tail == nullptr) {
                head = aPointer;
                tail = head;
            } else {
                tail->next = aPointer;
                tail = tail->next;
            }

            aPointer = aPointer->next;
            bPointer = bPointer->next;
        }
    }

    while (aPointer != nullptr) {
        Node<T>* del = aPointer;
        aPointer = aPointer->next;
        delete del;
    }
    if (tail != nullptr)
        tail->next = nullptr;
    A = head;
}
