//
// Created by Alfonso Meraz on 10/22/20.
//

#ifndef TEMPLATELINKEDLIST_LINKEDLIST_H
#define TEMPLATELINKEDLIST_LINKEDLIST_H
#include <iostream>
#include <cstddef>
#include "Node.h"

template<class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();
    void insert(T item);
    void insertHead(T item);
    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);
    void operator+=(const T& item);
    void insertBefore(T insertThis, T beforeThat);
    void insertAfter(T insertThis, T target);
    LinkedList<T>& operator=(const LinkedList<T>& list);
    void clear();
    bool checkEmpty();
    void remove(T target);
    int size();
    T getTailData();
    T getHeadData();
    void removeTail();
    void removeHead();
    T seek(int n);
    T rseek(int n);
private:
    Node<T>* createNode(T item);
    bool insertFirst(Node<T>* node);
    Node<T>* find(T target);
    int _size = 0;
    void insertBefore(T insertThis, Node<T>* target);
    void remove(Node<T>* temp);
    Node<T>* head;
    Node<T>* tail;
};

#include "LinkedList.cpp"
#endif //TEMPLATELINKEDLIST_LINKEDLIST_H
