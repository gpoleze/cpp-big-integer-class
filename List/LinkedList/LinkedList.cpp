//
//  LinkedList.cpp
//  Exercises
//
//  Created by Gabriel P Ferreira on 2017-07-31.
//  Copyright © 2017 Gabriel P Ferreira. All rights reserved.
//

#include "LinkedList.h"

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
    //    cout << "list deleted \n";
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
    
    
    Iterator<T> it = begin();
    
    for (it; it != end(); it++) {
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
