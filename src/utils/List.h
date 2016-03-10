#ifndef BIKES_LIST_H
#define BIKES_LIST_H

#include "../Bikes.h"

struct ListNode
{
public:
    Bike* info;
    ListNode* next;
};

template<class T>
class List
{
public:
    void List();

    template<class T>
    ListNode getFirstNode();
    template<class T>
    Bike getFirstElement();
    template<class T>
    ListNode getLastNode();
    template<class T>
    Bike getLastElement();

    template<class T>
    void addFirst(T node);
    template<class T>
    void addLast(T node);
    template<class T>
    void deleteFirst();
    template<class T>
    void deleteLast();

    template<class T>
    bool isEmpty();
    template<class T>
    void clear();
    template<class T>
    int size();

private:
    ListNode getNext(T node);
};

#endif //BIKES_LIST_H