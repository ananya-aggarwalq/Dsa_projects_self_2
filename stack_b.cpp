#include<iostream>
#include<stdexcept>
#include "stack_b.h"

//stack using dynamically sized arrays

//constructor with empty stack
Stack_B::Stack_B(){
    try{	
    size = -1;			
    capacity = 1024;
    stk= new int[1024];	}
    catch(std::exception e){
        throw(std::runtime_error("Out of Memory"));
    }					
}

//destructor
Stack_B::~Stack_B(){
    delete[] stk;
}

//push function
void Stack_B::push(int data){
    try{
    int fact = 2;
    if(size>capacity-1){
        int *temp = new int[capacity*fact];
        for(int i = 0; i<= size; i++){
            temp[i]=stk[i];
        }
        delete[] stk;
        stk = temp;
        capacity *= fact;
    }				
    stk[++size] = data;}
    
     catch(std::exception e){
        throw(std::runtime_error("Out of Memory"));
    }
}

//pop function
int Stack_B::pop(){
    
    if(size<0){
        throw std::runtime_error("Empty Stack");
    }else{
    int res = stk[size];
    int fact = 2;
    if(size<capacity/fact/fact){
        int* temp = new int[capacity/fact];
        for(int i = 0; i<= size; i++){
            temp[i] = stk[i];
        }
        delete[] stk;
        stk = temp;
        capacity /= fact;
        if(capacity<1024){
            capacity = 1024;
        }
    }
    size--;
    return res;
}}

//element from top
int Stack_B::get_element_from_top(int idx){
    if(idx<0 || size-idx<0){				
        throw std::runtime_error("Index out of range");}	
    else{						
        return stk[size-idx];}		
}		

//element from bottom
int Stack_B::get_element_from_bottom(int idx){		
    if(idx<0 || size-idx<0){						
        throw std::runtime_error("Index out of range");}	
    else{						
        return stk[idx];}					
 }

//printing stack
void Stack_B::print_stack(bool top){
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
int Stack_B::add(){
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
int Stack_B::subtract(){
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
int Stack_B::multiply(){
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
int Stack_B::divide(){
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
    ans = op2/double(op1);
    if(ans>=0 || op2%op1 ==0){
        fans = ans;
    }else{
        fans = ans-1;
    }
    push(fans);}
    return fans;
}} 

int* Stack_B::get_stack(){
    return stk;
}

int Stack_B::get_size(){
    return size+1;
}
