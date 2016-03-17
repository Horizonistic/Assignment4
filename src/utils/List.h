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

using namespace std;

/*
 * NOTE: All Nth methods are 0-based
 */
template<class T>
class List
{
public:
    List();

    ListNode<T>* makeNewNode(T* data);

    ListNode<T>* getFirstNode();
    T* getFirstElement();
    ListNode<T>* getNthNode(int n);
    T* getNthElement(int n);
    ListNode<T>* getLastNode();
    T* getLastElement();

    void addFirst(T* node);
    void addNth(int n, T* data);
    void addLast(T* data);
    void deleteFirst();
    void deleteNth(int n);
    void deleteLast();

    bool isEmpty();
    void clear();
    int getSize();
    void dump();

private:
    int size = 0;
    struct ListNode<T>* head = NULL;
    struct ListNode<T>* tail = NULL;
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
template <class T>
ListNode<T>* List<T>::getNthNode(int n)
{
    if (this->head == NULL || tail == NULL)
    {
        return NULL;
    }

    ListNode<T>* temp;

    if (n == this->size - 1)
    {
        return this->tail;
    }
    else if (n == 0)
    {
        return this->head;
    }
    else if (n <= (this->size / 2))
    {
        temp = this->head;
        int count = 0;

        while (temp->next != NULL && count < n)
        {
            temp = temp->next;
            count++;
        }

        return temp;

    }
    else
    {
        temp = this->tail;
        int count = 0;

        while (temp->prev != NULL && count < this->size - n)
        {
            temp = temp->prev;
            count++;
        }

        return temp->prev;
    }
}

template <class T>
T* List<T>::getNthElement(int n)
{
    if (this->head == NULL || tail == NULL)
    {
        return NULL;
    }

    return &(getNthNode(n)->info);
}

template<class T>
ListNode<T>* List<T>::getLastNode()
{
    if (this->tail == NULL)
    {
        return NULL;
    }
    else
    {
        return this->tail;
    }
}

template<class T>
T* List<T>::getLastElement()
{
    if (this->tail == NULL)
    {
        return NULL;
    }
    return &this->tail->info;
}

template<class T>
void List<T>::addFirst(T* data)
{
    struct ListNode<T>* newNode = makeNewNode(data);
    if (this->head == NULL)
    {
        this->head = newNode;
        this->size++;

        if (this->tail == NULL)
        {
            this->tail = newNode;
            return;
        }
        return;
    }

    this->head->prev = newNode;
    newNode->next = this->head;

    this->size++;
    this->head = newNode;
}

template <class T>
void List<T>::addNth(int n, T* data)
{
    struct ListNode<T>* newNode = makeNewNode(data);

    if (this->head == NULL)
    {
        this->head = newNode;

        if (this->tail == NULL)
        {
            this->tail = newNode;
            return;
        }
        this->size++;
        return;
    }

    ListNode<T>* temp;

    if (n == this->size || n == this->size + 1)
    {
        addLast(data);
    }
    else if (n == 0)
    {
        addFirst(data);
    }
    else if (n <= (this->size / 2))
    {
        temp = this->head;
        int count = 0;

        while (temp->next != NULL && count < n)
        {
            temp = temp->next;
            count++;
        }

        newNode->next = temp;
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
        this->size++;

        return;

    }
    else
    {
        temp = this->tail;
        int count = 0;

        while (temp->prev != NULL && count < this->size - (n + 1))
        {
            temp = temp->prev;
            count++;
        }

        newNode->next = temp;
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
        this->size++;

        return;
    }
}

template<class T>
void List<T>::addLast(T* data)
{
    struct ListNode<T>* newNode = makeNewNode(data);

    if (this->head == NULL)
    {
        this->head = newNode;
        if (tail == NULL)
        {
            this->tail = newNode;
        }
        this->size++;
        return;
    }

    this->tail->next = newNode;
    newNode->prev = this->tail;
    this->tail = newNode;
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
    if (this->head == NULL)
    {
        return;
    }

    ListNode<T>* temp;

    if (n <= (this->size / 2))
    {
        temp = this->head;
        int count = 0;

        while (temp->next != NULL && count < n)
        {
            temp = temp->next;
            count++;
        }

        if (temp == this->tail)
        {
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
            this->size--;
            return;
        }
        else if (temp == this->head)
        {
            head = temp->next;
            head->prev = NULL;
            delete temp;
            this->size--;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        this->size--;

        return;

    }
    else
    {
        temp = this->tail;
        int count = 0;

        while (temp->prev != NULL && count < this->size - n)
        {
            temp = temp->prev;
            count++;
        }

        if (temp == this->tail)
        {
            this->tail = temp->prev;
            this->tail->next = NULL;
            delete temp;
            this->size--;
            return;
        }
        else if (temp == this->head)
        {
            this->head = temp->next;
            this->head->prev = NULL;
            delete temp;
            this->size--;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        this->size--;

        return;
    }
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

template<class T>
void List<T>::dump()
{
    if (this->head == NULL)
    {
        return;
    }
    else if (this->tail == NULL)
    {
        return;
    }

    ListNode<T>* temp = this->head;
    while (temp->next != NULL)
    {
        cout << temp->info.id_num << ", ";
        temp = temp->next;
    }
    cout << temp->info.id_num << std::endl;
}

#endif //BIKES_LIST_H