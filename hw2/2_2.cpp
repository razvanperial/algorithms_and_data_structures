#include <iostream>
#include <deque>

int main(){
    std::deque<float> A;
    std::deque<float>::iterator diter;
    float x;
    do{
        std::cin>>x;
        if(x > 0){
            A.push_back(x);
        }
        else if(x < 0)
            A.push_front(x);
    }while(x != 0);

    for(diter = A.begin(); diter != A.end(); diter++)
        std::cout<<*diter<<" ";
    std::cout<<std::endl<<std::endl;

    for(diter = A.begin(); *diter < 0 ; diter++){}

    A.insert(diter, 0);

    diter = A.begin();
    std::cout<<*diter;
    diter++;

    for(; diter != A.end(); diter++)
        std::cout<<", "<<*diter;
    std::cout<<std::endl;
    return 0;
}