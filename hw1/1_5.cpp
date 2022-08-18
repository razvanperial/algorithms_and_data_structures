#include <iostream>
#include <vector>

int main(){
    unsigned int i, size = 0;
    bool ok = false;
    std::string s;
    std::vector<std::string> v;
    std::vector<std::string>::iterator viter;
    do{
        size++;
        getline(std::cin, s);
        v.push_back(s); 
        if(size == 5)
            ok = true;
    }while(s != "END");

    if(ok){
        std::string aux = v[4];
        v[4] = v[1];
        v[1] = aux;
    }
    else{
        std::cout<<"There are less then 5 objects in the vector"<<std::endl;
    }

    v[size-1] = "???";

    for(i = 0; i < size - 1; i++){
        std::cout<<v[i]<<", ";
    }
    std::cout<<v[i]<<std::endl;

    viter = v.begin();
    std::cout<<*viter;
    viter++;
    while(viter != v.end()){
        std::cout<<"; "<<*viter;
        viter++;
    }
    std::cout<<std::endl;
    viter = v.end();
    while(viter != v.begin()){
        std::cout<<*viter<<" ";
        viter--;
    }

    std::cout<<*viter<<std::endl;

}