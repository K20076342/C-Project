#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists

template<typename T>
class Node{

public:
    T data;
    Node<T>* next;
    Node<T>* previous;
    
    //constructor
    Node(T stuff):
        data (stuff), next (nullptr), previous (nullptr){}

};

template<typename T>
class NodeIterator {
  
    
public:
    
    Node<T>* current;

    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here
        
    //operator++ below

    
    void operator++()
    {
        if (current != nullptr)
        {
            current = current->next;

        }
    }

// operator ==

    bool operator== (const NodeIterator & currentItr)
    {
        return current == currentItr.current;
    }

//operator!
  
   bool operator!= (const NodeIterator & currentItr)
   {
    return current != currentItr.current;
   }
};

// do not edit below this line

#endif
