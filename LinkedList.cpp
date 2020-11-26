//
// Created by Alfonso Meraz on 10/22/20.
//
#ifndef TEMPLATELINKEDLIST_LINKEDLIST_CPP
#define TEMPLATELINKEDLIST_LINKEDLIST_CPP
#include "LinkedList.h"


template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : LinkedList()
{
    *this = list;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
void LinkedList<T>::insert(T item)
{
    Node<T>* temp = createNode(item);
    if(!insertFirst(temp))
    {
        tail->next = temp;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        _size++;
    }
}

template<class T>
bool LinkedList<T>::insertFirst(Node<T>* node)
{
    if(head == nullptr)
    {
        head = node;
        tail = node;
        return true;
    }
    return false;
}

template<class T>
void LinkedList<T>::insertHead(T item)
{
    Node<T>* temp = createNode(item);
    if(!insertFirst(temp))
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head = temp;
        _size++;
    }
}

template<class S>
std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list)
{
    for(Node<S>* walk = list.head; walk != nullptr; walk = walk->next)
    {
        out.width(5);
        out << walk->data;
    }
    return out;
}

template<class T>
void LinkedList<T>::operator+=(const T& item)
{
    insert(item);
}

template<class T>
void LinkedList<T>::insertBefore(T insertThis, T beforeThat)
{
    Node<T>* target = find(beforeThat);
    insertBefore(insertThis, target);
}
template<class T>
void LinkedList<T>::insertBefore(T insertThis, Node<T>* target)
{
    if(target != nullptr)
    {
        Node<T>* node = createNode(insertThis);
        Node<T>* tprev = target->prev;
        if(head == tail || target == head)
        {
            node->prev = nullptr;
            node->next = target;
            target->prev = node;
            head = node;
        }
        else
        {
            node->next = target;
            node->prev = tprev;
            tprev->next = node;
            tprev = node;
        }
        _size++;
    }
}


template<class T>
Node<T> *LinkedList<T>::createNode(T item) {
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}

template<class T>
void LinkedList<T>::insertAfter(T insertThis, T target)
{
    Node<T>* temp = find(target);
    if(temp == tail)
        insert(insertThis);
    else if(temp != nullptr && temp->next != nullptr)
    {
        insertBefore(insertThis, temp->next);
    }
}

template<class T>
Node<T>* LinkedList<T>::find(T target)
{
    Node<T>* walker = head;
    while(walker != nullptr && walker->data != target)
    {
        walker = walker->next;
    }
    return walker;
}


template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
    clear();
    Node<T>* walker = list.head;
    _size = 0;
    while(walker != nullptr)
    {
        insert(walker->data);
        walker = walker->next;
    }
    return *this;
}

template<class T>
void LinkedList<T>::clear()
{
    Node<T>* walker = head;
    Node<T>* previous;
    while(walker != nullptr)
    {
        previous = walker;
        walker = walker->next;
        delete previous;
        _size--;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
bool LinkedList<T>::checkEmpty() {
    if(head == nullptr && tail == nullptr)
        return true;
    return false;
}

template<class T>
void LinkedList<T>::remove(T target) {
    remove(find(target));
}

template<class T>
void LinkedList<T>::remove(Node<T> *temp) {
    if(temp != nullptr)
    {
        Node<T>* before = temp->prev;
        Node<T>* after = temp->next;
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if(temp == head)
        {
            after->prev = nullptr;
            head = after;
        }
        else if(temp == tail)
        {
            before->next = nullptr;
            tail = before;
        }
        else
        {
            before->next = after;
            after->prev = before;
        }
        delete temp;
        _size--;
    }
}

template<class T>
int LinkedList<T>::size() {
    Node<T>* walker = head;
    int size = 0;
    while(walker != nullptr)
    {
        walker = walker->next;
        size++;
    }
    return size;
}

template<class T>
T LinkedList<T>::getTailData()
{
    return tail->data;
}
template<class T>
T LinkedList<T>::getHeadData()
{
    return head->data;
}

template<class T>
void LinkedList<T>::removeTail()
{
    remove(tail);
}
template<class T>
void LinkedList<T>::removeHead()
{
    remove(head);
}

template<class T>
T LinkedList<T>::seek(int n) {
    Node<T>* walker = head;
    int i = 0;
    while(walker != nullptr && i < n)
    {
        walker = walker->next;
        i++;
    }
    if(walker != nullptr)
    {
        return walker->data;
    }
    else if(tail != nullptr)
        return tail->data;
    return T();
}

template<class T>
T LinkedList<T>::rseek(int n) {
    Node<T>* walker = tail;
    int i = 0;
    while(walker != nullptr && i < n)
    {
        walker = walker->prev;
        i++;
    }
    if(walker != nullptr)
    {
        return walker->data;
    }
    else if(head != nullptr)
        return head->data;
    return T();
}


#endif