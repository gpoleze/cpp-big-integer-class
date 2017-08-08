//  Author:     Gabriel Poleze Ferreira #100280844
//  Course:     CPSC 1160
//  Lab#:       10
//  Purpose:    Define and implement the Linked List Class
//  Limitations:
//  Bugs:
//  References:

#ifndef LinkedList_h
#define LinkedList_h

#include <stdexcept>
#include <iostream>
#include <string>

#include "Node.h"
#include "Iterator.h"

using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    void validateIndexInSize(int) const;
    
public:
    //Constructors
    LinkedList();
    LinkedList(const T);
    LinkedList(const LinkedList<T>&);
    
    //Destructor
    virtual ~LinkedList();
    
    //Methods
    void addFirst(T element);
    void addLast(T element);
    void addLast(const LinkedList<T>& list);
    int getSize() const {return size;};     //O(1)
    bool isEmpty() const {return size==0;}; //O(1)
    //    T getFirst() const;
    //    T getLast() const;
    T removeFirst() throw (std::runtime_error);
    T removeLast() throw(std::runtime_error);
    //    void add(T element);
    //    void add(int index, T element);
    void clear();
    T at(int index) const;
    //    int indexOf(T element) const;
    //    int lastIndexOf(T element) const;
    //    void remove(T element);
    //    T removeAt(int index);
    //    T set(int index, T element);
    Iterator<T> begin() const{return Iterator<T>(head);}       //O(1)
    Iterator<T> end() const {return Iterator<T>(tail->next);}   //O(1)
    Iterator<T> rbegin() const{return Iterator<T>(tail);}
    Iterator<T> rend() const {return Iterator<T>(head->previous);}
    string toString() const;
    
    
    //Operator Overloading
    T& operator[](int index);
    const LinkedList<T>& operator=(const LinkedList<T>&);
    
    friend class stream;
    //    friend ostream& operator<<(ostream& out, const LinkedList& list);
};

#endif /* LinkedList_h */
