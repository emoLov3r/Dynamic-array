#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"


int main(){
    DynamicArray<int> arr1;
    std::cout << arr1.GetSize();

    DynamicArray<int> arr2(arr1);
    std::cout << arr2.GetSize();

    LinkedList lst;
    lst.PushBack(1.0);
    lst.PushBack(2.0);
    lst.PushBack(3.0);
    lst.PushBack(4.0);
    lst.PushBack(5.0);

    return 0;
}