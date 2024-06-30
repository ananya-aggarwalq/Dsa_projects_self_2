#include<iostream>
#include <stdexcept>
#include "node.h"
#include "list.h"
#include "stack_c.h"

Stack_C::Stack_C(){
    try{
        stk = new List();
    }
    catch(std::exception e){
        throw(std::runtime_error("Out of Memory"));
    }
}
Stack_C::~Stack_C(){
    delete stk;
}
void Stack_C::push(int data){
    try{
        stk->insert(data);
    }
    catch(std::exception e){
        throw(std::runtime_error("Out of Memory"));
    }
}
int Stack_C::pop(){
    if(stk->get_size()<=0){
        throw std::runtime_error("Empty Stack");
        return -1;
    }
    else{
        return stk->delete_tail();
    }
}
int Stack_C::get_element_from_top(int idx){
    if(idx<0 || stk->get_size()-idx<=0){
        throw std::runtime_error("Index out of range");
    }else{
        Node* cn = stk->get_head()->next;
        int reqcount = stk->get_size()-idx-1;
        for(int i = 0; i<reqcount; ++i){
            cn = cn->next;
        } 
        return cn->get_value();
    }
}
int Stack_C::get_element_from_bottom(int idx){
    if(idx<0 || stk->get_size()-idx<=0){
        throw std::runtime_error("Index out of range");
    }else{
        Node* n = stk->get_head()->next;
        for(int i = 0; i<idx ; i++){
            n = n->next;
        }
        return n->get_value();
    }
}
void Stack_C::print_stack(bool top_or_bottom){
    if(stk->get_size()==0){
        throw std::runtime_error("Empty Stack");
    }else{
    Node* temp;
    if(top_or_bottom){
        temp = stk->get_head()->next;
        while(temp!= NULL){
            std::cout<<temp->get_value()<<std::endl;
            temp = temp->next;    
        }
    }else{
        temp = stk->get_head()->next;
        for(int i=0; i<stk->get_size()-1; ++i){
            temp = temp->next;
        }
        while(temp!= stk->get_head()){
            std::cout<<temp->get_value()<<std::endl;
            temp = temp->prev;    
        }
    }
}}
int Stack_C::add(){
    if(stk->get_size()<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op1+op2;
    push(ans);
    return ans;}}

int Stack_C::subtract(){
    if(stk->get_size()<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op2-op1;
    push(ans);
    return ans;}
}
int Stack_C::multiply(){
    if(stk->get_size()<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op1*op2;
    push(ans);
    return ans;}
}
int Stack_C::divide(){
    if(stk->get_size()<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,fans;
    double ans;
    op1 = pop();
    op2 = pop();
    if(op2==0){
        throw std::runtime_error("Divide by Zero Error");
    }else{
    ans = op2/double(op1);
    if(ans>=0 || op2%op1 ==0){
        fans = ans;
    }else{
        fans = ans-1;
    }
    push(fans);}
    return fans;
}
}
List* Stack_C::get_stack(){
return stk;
}
int Stack_C::get_size(){
return stk->get_size();    
}
