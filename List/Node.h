//
//  Node.hpp
//  Exercises
//
//  Created by Gabriel P Ferreira on 2017-07-30.
//  Copyright © 2017 Gabriel P Ferreira. All rights reserved.
//

#ifndef Node_h
#define Node_h

template<typename T>
class Node {
public:
    T element;          // Element contained in the node
    Node<T>* next;      // Pointer to the next node
    Node<T>* previous;  // Pointer to the previous node
    
    // No-arg constructor
    Node() {
        next = previous = nullptr;
    }
    
    // Constructor
    Node(T element):element(element) {
        //this->element = element
        next = nullptr;
        previous = nullptr;
    }
};

#endif /* Node_h */
