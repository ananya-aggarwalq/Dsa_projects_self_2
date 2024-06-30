#include<iostream>
#include<stdexcept>
#include "stack_a.h"

//stack using fixed size arrays

//constructor with empty stack
Stack_A::Stack_A(){	
	size = -1;									
}											

//push function
void Stack_A::push(int data){					
    if(size>1023){					
        throw std::runtime_error("Stack Full");}		
    else{						
        stk[++size] =data;}					
}						

//pop function
int Stack_A::pop(){						
    if(size<0){						
        throw std::runtime_error("Empty Stack");}	
    else{						
        return stk[size--];}					
}							

//element from top
int Stack_A::get_element_from_top(int idx){			
    if(idx<0 || size-idx<0){				
        throw std::runtime_error("Index out of range");}	
    else{						
        return stk[size-idx];}				
}						

//element from bottom
int Stack_A::get_element_from_bottom(int idx){		
    if(idx<0 || size-idx<0){						
        throw std::runtime_error("Index out of range");}	
    else{						
        return stk[idx];}					
 }

//printing stack
void Stack_A::print_stack(bool top){
    if(size<0){
        throw std::runtime_error("Empty Stack");
    }else{   
    if(top){
        for(int i = size; i>=0; --i){
            std::cout<<stk[i]<<std::endl;
        }
    }
    else{
         for(int i = 0; i<=size; ++i){
            std::cout<<stk[i]<<std::endl;
        }
    }}
} 

//addition
int Stack_A::add(){
    if(size<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op1+op2;
    push(ans);
    return ans;
}}

//subtraction
int Stack_A::subtract(){
    if(size<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op2-op1;
    push(ans);
    return ans;
}} 

//multiplication
int Stack_A::multiply(){
    if(size<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,ans;
    op1 = pop();
    op2 = pop();
    ans = op1*op2;
    push(ans);
    return ans;
}} 

//division
int Stack_A::divide(){
    if(size<1){
        throw std::runtime_error("Not Enough Arguments");
    }else{
    int op1,op2,fans;
    double ans;
    op1 = pop();
    op2 = pop();
    if(op2==0){
        throw std::runtime_error("Divide by Zero Error");
    }else{
    ans = double(op2)/double(op1);
    if(ans>=0 || op2%op1 ==0){
        fans = ans;
    }else{
        fans = ans-1;
    }
    push(fans);}
    return fans;
}} 

int* Stack_A::get_stack(){
    return stk;
}

int Stack_A::get_size(){
    return size+1;
}
