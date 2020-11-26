//
// Created by Alfonso Meraz on 11/23/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_NODE_H
#define STATISTICAL_FINANCIAL_DATA_NODE_H

template <class T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};


#endif //STATISTICAL_FINANCIAL_DATA_NODE_H
