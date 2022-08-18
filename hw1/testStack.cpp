#include <iostream>
#include "Stack.h"

int main(){
    Stack<int> s1(20);                          //using parameter constructor
    for(int i = 0; i < 10 ; i++)
        s1.push(i);                             //pushing elements in stack
    int x = s1.back();  
    std::cout<<"Last element: "<<x<<std::endl;  //printing last element
    Stack<int> s2(s1);                          //using copy constructor
    for(int i = 0; i < 10 ; i++)                //popping elements from stack
        s1.pop(x);
    return 0;
}