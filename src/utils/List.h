#ifndef BIKES_LIST_H
#define BIKES_LIST_H

#include "../Bikes.h"
#include <stdlib.h>

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
    struct ListNode<T>* head;

    List();

    ListNode<T>* makeNewNode(T* data);

    ListNode<T> * getFirstNode();
    T* getFirstElement();
    ListNode<T>* getLastNode();
    T* getLastElement();

    void addFirst(T* node);
    void addLast(T* data);
    void deleteFirst();
    void deleteLast();

    bool isEmpty();
    void clear();
    int size();
};

template<class T>
List<T>::List(){}

template<class T>
ListNode<T>* List<T>::makeNewNode(T* data)
{
    ListNode<T>* newNode;
    newNode = (struct ListNode<T>*) calloc(1, sizeof(struct ListNode<T>));
    newNode->info = *data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

template<class T>
ListNode<T>* List<T>::getFirstNode()
{
    return head;
}

template<class T>
T* List<T>::getFirstElement()
{
    return new T;
}

template<class T>
ListNode<T>* List<T>::getLastNode()
{
    ListNode<T>* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

template<class T>
T* List<T>::getLastElement()
{
    ListNode<T>* temp = head;
    while (temp != NULL)
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
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

template<class T>
void List<T>::addLast(T* data)
{
    ListNode<T>* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }

    struct ListNode<T>* newNode = makeNewNode(data);

    temp->next = newNode;
    newNode->prev = temp;

    return;
}

template<class T>
void List<T>::deleteFirst()
{
    struct ListNode<T>* temp = head->next;
    delete temp->prev;
    head = temp;
    return;
}

template<class T>
void List<T>::deleteLast()
{
    ListNode<T>* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }

    temp->prev = temp;
    delete temp->next;
    return;
}

template<class T>
bool List<T>::isEmpty()
{
    return head == NULL;
}

template<class T>
void List<T>::clear()
{
    ListNode<T>* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;
    return;
}

template<class T>
int List<T>::size()
{
    ListNode<T>* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

#endif //BIKES_LIST_H