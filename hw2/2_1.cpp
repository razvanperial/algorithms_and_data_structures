#include <iostream>
#include <list>
#include <fstream>

int main(){
    std::ofstream out_file;
    out_file.open("listB.txt", std::ios::out);
    if (!out_file){   
            std::cout <<"Error! Could not open file\n"; 
            exit(-1);
    }
    std::list<int>::iterator liter;
    std::list<int> A, B;
    int x;
    do{
        std::cin>>x;
        if(x > 0){
            A.push_back(x);
            B.push_front(x);
        }
    }while(x > 0);

    std::cout<<"list A: ";
    for(liter = A.begin(); liter != A.end(); liter++)
        std::cout<<*liter<<" ";
    std::cout<<std::endl<<std::endl;

    for(liter = B.begin(); liter != B.end(); liter++)
        out_file<<*liter<<" ";

    A.push_back(*A.begin());
    A.pop_front();
    B.push_back(*B.begin());
    B.pop_front();

    std::cout<<"list A: "; 
    for(liter = A.begin(); liter != A.end(); liter++)
        std::cout<<*liter<<", ";
    std::cout<<std::endl;  

    std::cout<<"list B: "; 
    for(liter = B.begin(); liter != B.end(); liter++)
        std::cout<<*liter<<", ";
    std::cout<<std::endl<<std::endl; 

    A.merge(B);
    A.sort();  

    std::cout<<"list A merged with B: "; 
    for(liter = A.begin(); liter != A.end(); liter++)
        std::cout<<*liter<<" "; 
    std::cout<<std::endl;

    return 0;
}