#include <iostream>
#include <vector>

int main(){
    unsigned int i, size = 0;
    std::string s;
    std::vector<std::string> v;
    do{
        size++;
        std::cin>>s;
        v.push_back(s); 
    }while(s != "END");

    for(i = 0; i < size; i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    for(i = 0; i < size - 1; i++){
        std::cout<<v[i]<<", ";
    }
    std::cout<<v[i]<<std::endl;

}