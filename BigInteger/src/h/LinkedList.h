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

//#include "Node.h"
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
    int getSize() const;
    bool isEmpty() const;
    void addFirst(T element);
    void addLast(T element);
    void addLast(const LinkedList<T>& list);
    //    T getFirst() const;
    //    T getLast() const;
    T removeFirst() throw (std::runtime_error);
    T removeLast()  throw (std::runtime_error);
    //    void add(T element);
    //    void add(int index, T element);
    void clear();
    T at(int index) const;
    //    int indexOf(T element) const;
    //    int lastIndexOf(T element) const;
    //    void remove(T element);
    //    T removeAt(int index);
    //    T set(int index, T element);
    Iterator<T> begin() const{return Iterator<T>(head);}
    Iterator<T> end()   const {return Iterator<T>(tail->next);}
    Iterator<T> rbegin() const{return Iterator<T>(tail);}
    Iterator<T> rend()   const {return Iterator<T>(head->previous);}
    string toString() const;
    
    
    //Operator Overloading
    T& operator[](int index);
    const LinkedList<T>& operator=(const LinkedList<T>&);
    
    friend class stream;
    //    friend ostream& operator<<(ostream& out, const LinkedList& list);
};
//Constructors
template <typename T>
LinkedList<T>::LinkedList(){
    head = tail = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const T value){
    size = 1;
    head = tail = new Node<T>(value);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
    size = 0;
    head = tail = nullptr;
    
    if (list.isEmpty())
        return;
    
    for(Iterator<T> it = list.begin(); it != list.end() ; it++)
        this->addLast(it.content());
}

//Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
    if (!isEmpty()){
        Node<T>* current = head;
        for (int i = 0; i < size; i++){
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
        size = 0;
        head = tail = nullptr;
    }
}

//Methods
template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return size==0;
}

template<typename T>
void LinkedList<T>::addFirst(T element){
    Node<T>* temp = new Node<T>(element);
    
    if(isEmpty()){
        head = tail = temp;
    } else {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
    
    size++;
}

template<typename T>
void LinkedList<T>::addLast(T element){
    
    Node<T>* temp = new Node<T>(element);
    
    if (head == nullptr){
        head = tail = temp;
    } else{
        temp->previous = tail;
        tail->next = temp;
        
        
        tail = temp; // tail = tail->next;
    }
    
    size++;
    
}

template<typename T>
T LinkedList<T>::removeFirst() throw(std::runtime_error){
    if (size == 0)
        throw std::runtime_error("The list was already empty");
    
    Node<T>* newHead = head->next;
    T oldElement = head->element;
    
    delete head;
    
    head = newHead;
    size--;
    
    return oldElement;
    
}

template<typename T>
T LinkedList<T>::removeLast() throw(std::runtime_error){
    if (size == 0)
        throw std::runtime_error("The list was already empty");
    
    Node<T>* newTail = tail->previous;
    T oldElement = tail->element;
    
    delete tail;
    
    tail = newTail;
    size--;
    
    return oldElement;
}

template<typename T>
void LinkedList<T>::clear(){
    if (size == 0)
        return;
    
    while (head != nullptr)
        removeFirst();
    
}

template<typename T>
T LinkedList<T>::at(int index) const{
    validateIndexInSize(index);
    
    if (index == 0)
        return head->element;
    
    if (index == size - 1)
        return tail->element;
    
    Iterator<T> it = begin();
    
    int counter;
    
    if (index < size / 2) {
        counter = 1;
        for (++it; it != end(); it++)
            if (counter++ == index)
                break;
    } else{
        counter = size - 1 - 1;
        it = Iterator<T>(tail);
        for (--it; it != begin(); it--)
            if (counter-- == index)
                break;
    }
    
    return it.content();
}

template<typename T>
string LinkedList<T>::toString() const{
    if (isEmpty())
        return "[]";
    
    
    string out("[");
    string c(" ");
    
    for (Iterator<T> it = begin(); it != end(); it++) {
        out += c + to_string(it.content());
        c = ", ";
    }
    out += " ]";
    
    return out;
}

template<typename T>
T& LinkedList<T>::operator[](int index){
    validateIndexInSize(index);
    
    if (index == 0)
        return head->element;
    
    if (index == size - 1)
        return tail->element;
    
    Node<T>* current = head;
    
    for (int i = 1; i <= index; i++)
        current = current->next;
    
    return current->element;
}

template<typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    clear();
    
    for(Iterator<T> it = other.begin(); it != other.end(); it++)
        addLast(it.content());
    
    return *this;
}

template<typename T>
void LinkedList<T>::validateIndexInSize(int index) const{
    if (index < 0 || index >= size)
        throw out_of_range("index out of bounds");
}

template<typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& list){
    if (list.isEmpty()){
        out << "[]";
    } else {
        out << "[";
        string c(" ");
        
        for(Iterator<T> it = list.begin(); it != list.end(); it++){
            out << c;
            out << it.content();
            c = ", ";
        }
        
        out << " ]";
    }
    
    return out;
}

#endif /* LinkedList_h */
