#ifndef NODE_H
#define NODE_H

// 单链表节点（仅含next指针）
template <typename T>
struct SinglyNode {
    T data; // 节点数据
    SinglyNode<T>* next; // 指向下一个节点
    // 构造函数：初始化数据和指针
    SinglyNode(const T& val)
        : data(val)
        , next(nullptr)
    {
    }
    SinglyNode()
        : data()
        , next(nullptr)
    {
    }
};

// 双链表节点（含prev和next指针）
template <typename T>
struct DoublyNode {
    T data; // 节点数据
    DoublyNode<T>* prev; // 指向前一个节点
    DoublyNode<T>* next; // 指向下一个节点
    // 构造函数：初始化数据和指针
    DoublyNode(const T& val)
        : data(val)
        , prev(nullptr)
        , next(nullptr)
    {
    }
    DoublyNode()
        : data()
        , prev(nullptr)
        , next(nullptr)
    {
    }
};

#endif // NODE_H
