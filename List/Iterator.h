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
    Iterator(Node<T>* node):current(node){}
    
    //Member Functions (also called Methods)
    
    Iterator next(){
        current = current->next;
        return *this;
    }
    Iterator previous(){
        current = current->previous;
        return *this;
    }
    
    T content() const {
        return current->element;
    }
    
    bool isEqual(const Iterator<T>& other) const {
        return current == other.current;
    }
    
    //Operators Overload
    
    Iterator operator=(const Iterator& other){
        current = other.current;
        return *this;
    }
    
    // operator++ prefixed
    Iterator operator++(){
        return next();
    }
    // operator++ post-fixed
    Iterator operator++(int dummy){
        Iterator temp(current);
        next();
        return temp;
    }
    // operator-- prefixed
    Iterator operator--(){
        return previous();
    }
    
    // operator-- post-fixed
    Iterator operator--(int dummy){
        Iterator temp(current);
        previous();
        return temp;
    }
    
    // operator ==
    bool operator==(const Iterator& other) const{
        return isEqual(other);
    }
    // operator !=
    bool operator!=(const Iterator& other) const{
        return !isEqual(other);
    }
};

#endif /* Iterator_h */



