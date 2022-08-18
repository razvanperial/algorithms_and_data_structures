#include <iostream>
#include "LinkedList.h"

int main(){
    int i;
    double a[5] = {5.1,5.2,5.3,5.4,5.5};
    char robot[] = "megathron";
    List<int> l1;                       //list of ints
    List<double> l2(5,a);               //list of doubles
    List<char> l3(10,robot);            //list of chars
    for (i = 0; i < 10; i++)            //pushing 10 elements into list of ints
        l1.push_front(i);
    for (i = 1; i <= 3; i++)            //popping 3 elements from the list of doubles
        l2.pop_back();

    //printing elements from lists
    std::cout<<"Last element from list of ints: "<<l1.get_back()<<std::endl;
    std::cout<<"Last element from list of doubles: "<<l2.get_back()<<std::endl;
    std::cout<<"First element from list of chars: "<<l3.get_front()<<std::endl;
    std::cout<<"Size of list of chars: "<<l3.get_size()<<std::endl;
    std::cout<<"Size of list of ints: "<<l1.get_size()<<std::endl;
    std::cout<<"Size of list of doubles: "<<l2.get_size()<<std::endl;

}