#include <iostream>
#include <vector>
/*
   《2026王道数据结构》综合题P42T03;
    function:Inverted singly linked list with the leading node in place;
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

    Node<T>* prev = nullptr;
    Node<T>* cur = head->next;
    Node<T>* next;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;

        cur = next;
    }
    head->next = prev;
}