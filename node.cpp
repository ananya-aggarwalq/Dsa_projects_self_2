#include "node.h"

Node::Node(bool sentinel) {
    is_sentinel = sentinel;
}

Node::Node(int v, Node* nxt, Node* prv){
    this->next = nxt;
    this->prev = prv;
    this->value = v;
}

int Node::get_value(){
    return value;
}
bool Node::is_sentinel_node(){
    if(this->next == nullptr || this->prev == nullptr){
        return true;
    }else{
        return false;
    }
}
