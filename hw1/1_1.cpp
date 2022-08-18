#include <iostream>
#include <cstring>

class Complex {
private:
    int real, imag;
public:
    void set_real(int r) {real = r;}
    void set_imag(int i) {imag = i;}
    Complex(int r = 0, int i = 0) {real = r;   imag = i;}
    //overloading the '!=' operator
    bool operator != (Complex const &obj) {
         return real != obj.real || imag != obj.imag;
    }
};

template<class T>
int search(T array[], T el, int size){
    int i;
    for(i = 0; i < size && array[i] != el; i++){}
    if(i == size)
        return -1;
    return i;
}

int main(){
    int int_array[10] = {0,1,2,3,4,5,6,7,8,9};
    char char_array[] = "abcdefghi";
    Complex class_array[10];

    //create array of complex numbers
    for(int i = 0; i < 10; i++){
        class_array[i].set_real(i);
        class_array[i].set_imag(i+1);
    }

    std::cout<<"Searching for 6 in array of ints: "
    <<search<int>(int_array, 6, 10)<<std::endl;

    std::cout<<"Searching for 'z' in array of chars: "
    <<search<char>(char_array, 'z', 10)<<std::endl;

    std::cout<<"Searching for complex number (9, 10) in array of objects: "
    <<search<Complex>(class_array, Complex(9,10), 10)<<std::endl;

    return 0;
}