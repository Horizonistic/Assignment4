#ifndef BIKES_LIST_H
#define BIKES_LIST_H

#include "../Bikes.h"
#include <stdlib.h>
#include <iostream>

template<class T>
struct ListNode
{
public:
    T info;
    ListNode* next;
    ListNode* prev;
};

template<class T>
class List
{
public:
    List();

    ListNode<T>* makeNewNode(T* data);

    ListNode<T> * getFirstNode();
    T* getFirstElement();
    ListNode<T>* getLastNode();
    T* getLastElement();

    void addFirst(T* node);
    void addNth(T* node);
    void addLast(T* data);
    void deleteFirst();
    void deleteNth(int n);
    void deleteLast();

    bool isEmpty();
    void clear();
    int getSize();

private:
    int size = 0;
    struct ListNode<T>* head = NULL;
};

template<class T>
List<T>::List(){}

template<class T>
ListNode<T>* List<T>::makeNewNode(T* data)
{
    struct ListNode<T>* newNode = (struct ListNode<T>*) calloc(1, sizeof(struct ListNode<T>));
    newNode->info = *data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

template<class T>
ListNode<T>* List<T>::getFirstNode()
{
    if (this->head == NULL)
    {
        return NULL;
    }
    return this->head;
}

template<class T>
T* List<T>::getFirstElement()
{
    if (this->head == NULL)
    {
        return NULL;
    }
    return &this->head->info;
}

template<class T>
ListNode<T>* List<T>::getLastNode()
{
    ListNode<T>* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

template<class T>
T* List<T>::getLastElement()
{
    ListNode<T>* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return &temp->info;
}

template<class T>
void List<T>::addFirst(T* data)
{
    struct ListNode<T>* newNode = makeNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        this->size++;
        return;
    }

    this->head->prev = newNode;
    newNode->next = head;

    this->size++;
    head = newNode;
}

template <class T>
void List<T>::addNth(T* node)
{
    // TODO: Implement
    return;
}

template<class T>
void List<T>::addLast(T* data)
{
    struct ListNode<T>* newNode = makeNewNode(data);
    ListNode<T>* temp = head;

    if (head == NULL)
    {
        head = newNode;
        this->size++;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    this->size++;

    return;
}

template<class T>
void List<T>::deleteFirst()
{
    if (this->head == NULL)
    {
        return;
    }

    struct ListNode<T>* temp = this->head->next;
    delete temp->prev;
    temp->prev = NULL;
    this->head = temp;
    this->size--;
    return;
}

template <class T>
void List<T>::deleteNth(int n)
{
    // TODO: Implement
    return;
}

template<class T>
void List<T>::deleteLast()
{
    if (this->head == NULL)
    {
        return;
    }

    ListNode<T>* temp = this->head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp = temp->prev;
    delete temp->next;
    temp->next = NULL;
    this->size--;
    return;
}

template<class T>
bool List<T>::isEmpty()
{
    return this->size == 0;
}

template<class T>
void List<T>::clear()
{
    ListNode<T>* temp = this->head;
    do
    {
        temp = temp->next;
        delete temp->prev;
    }
    while (temp->next != NULL);

    delete temp;
    this->size = 0;
    return;
}

template<class T>
int List<T>::getSize()
{
    return this->size;
}

#endif //BIKES_LIST_H