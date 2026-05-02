#include <iostream>
#include "DynamicArray.hpp"


int main(){
    DynamicArray<int> arr1;
    std::cout << arr1.GetSize();

    DynamicArray<int> arr2(arr1);
    std::cout << arr2.GetSize();

    return 0;
}