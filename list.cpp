#include "list.h"
#include<stdexcept>
#include "node.h"

//constructor
List::List(){
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->prev = nullptr;
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    sentinel_tail->next = nullptr;
    size = 0;
}

//destructor
List::~List(){
    while(sentinel_head->next != sentinel_tail){
        Node* n = sentinel_head->next;
        sentinel_head->next = n->next;
        delete n;
    }
    delete sentinel_head;
    delete sentinel_tail;
}

//insertion
void List::insert(int v){
    Node* n1 = new Node(v, sentinel_tail, sentinel_tail->prev) ;
    sentinel_tail->prev->next = n1;
    sentinel_tail->prev = n1;
    ++size;
}

//deletion
int List::delete_tail(){
    if(size ==0){
        throw std::runtime_error("Empty Stack");
    }
    else{
        Node* tn = sentinel_tail->prev;
        int value = tn->get_value();
        tn->prev->next = sentinel_tail;
        sentinel_tail->prev = tn->prev;

        delete tn;
        --size;
        return value;
    }
}

//size
int List::get_size(){
    return size;
}

//head
Node* List::get_head(){
    return sentinel_head;
}
