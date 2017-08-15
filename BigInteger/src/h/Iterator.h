//
//  Iterator.hpp
//  Exercises
//
//  Created by Gabriel P Ferreira on 2017-07-31.
//  Copyright © 2017 Gabriel P Ferreira. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

#include "Node.h"

template<typename T>
class Iterator {
    Node<T>* current;
    
public:
    //Constructor
    Iterator(Node<T>* node);
    
    //Member Functions (also called Methods)
    Iterator next();
    Iterator previous();
    T content() const;
    bool isEqual(const Iterator<T>& other) const;
    
    //Operators Overloading
    Iterator operator=(const Iterator& other);
    
    // operator ++ and -- prefixed
    Iterator operator++();
    Iterator operator--();
    
    // operator ++ and -- post-fixed
    Iterator operator++(int dummy);
    Iterator operator--(int dummy);
    
    // Boolean operators
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
};

//Constructor
template<typename T>
Iterator<T>::Iterator(Node<T>* node){
    this->current = node;
}

//Member Functions
template<typename T>
Iterator<T> Iterator<T>::next(){
    current = current->next;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::previous(){
    current = current->previous;
    return *this;
}

template<typename T>
T Iterator<T>::content() const{
    return current->element;
}

template<typename T>
bool Iterator<T>::isEqual(const Iterator<T>& other) const {
    return current == other.current;
}

template<typename T>
Iterator<T> Iterator<T>::operator=(const Iterator& other){
    current = other.current;
    return *this;
}

// operator++ prefixed
template<typename T>
Iterator<T> Iterator<T>::operator++(){
    return next();
}
// operator++ post-fixed
template<typename T>
Iterator<T> Iterator<T>::operator++(int dummy){
    Iterator temp(current);
    next();
    return temp;
}

// operator-- prefixed
template<typename T>
Iterator<T> Iterator<T>::operator--(){
    return previous();
}

// operator-- post-fixed
template<typename T>
Iterator<T> Iterator<T>::operator--(int dummy){
    Iterator temp(current);
    previous();
    return temp;
}

// operator ==
template<typename T>
bool Iterator<T>::operator==(const Iterator& other) const{
    return isEqual(other);
}
// operator !=
template<typename T>
bool Iterator<T>::operator!=(const Iterator& other) const{
    return !isEqual(other);
}

#endif /* Iterator_h */



