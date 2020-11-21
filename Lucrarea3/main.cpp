#include <iostream>
#include <factorial.h>

int main(){
    int a;
    std::cout<< "Number to factorial"; std::cin>>a;

    std::cout<<"Factorial of a"<<factorial(a);
    return 0;
}