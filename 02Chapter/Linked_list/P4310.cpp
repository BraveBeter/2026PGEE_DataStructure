#include "node.h"
#include <iostream>
#include <vector>

template <typename T>
using Node = SinglyNode<T>;
/*
   《2026王道数据结构》综合题P43T10;
    function:Determine whether the single-stranded list of integer sequences B is a continuous subsequence of A
    Time Complexity :O(n * m);
    Space Complexity:O(1);
*/

bool solve(Node<int>* A, Node<int>* B)
{
    if (A == nullptr || B == nullptr) {
        return B == nullptr;
    }

    Node<int>* aPointer = A;
    Node<int>* bPointer = B;
    Node<int>* next_start = A->next;

    while (aPointer != nullptr && bPointer != nullptr) {
        int aVal = aPointer->data, bVal = bPointer->data;
        if (aVal == bVal) {
            bPointer = bPointer->next;
            aPointer = aPointer->next;
        } else {
            aPointer = next_start;
            bPointer = B;
            next_start = (aPointer == nullptr ? nullptr : aPointer->next);
        }

        if (bPointer == nullptr) {
            return true;
        }
    }
    return false;
}