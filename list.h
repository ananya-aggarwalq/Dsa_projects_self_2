#pragma once 
#include "node.h"



class List {
private: 
    int size;
    Node* sentinel_head;
    Node* sentinel_tail;

public: 
    List();

    ~List();

    // Insertion at the tail 
    void insert(int v);

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int delete_tail();

    // Return the size of the linked list 
    int get_size(); 

    // Return a pointer to the sentinel head of the linked list 
    Node* get_head();

};
