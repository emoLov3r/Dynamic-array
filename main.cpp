#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"


int main(){
    DynamicArray<int> arr1;
    std::cout << arr1.GetSize();

    DynamicArray<int> arr2(arr1);
    std::cout << arr2.GetSize()<<"\n";

    DynamicArray<int>arr;
    arr.PushBack(1);
    arr.PushBack(10);
    arr.PushBack(123);
    arr.PushBack(144);

    arr.PopBack();
    arr.PopBack();

    std::cout<<arr[2];

    for (size_t i = 0; i < arr.GetSize(); i++){
        std::cout<<arr[i]<<" ";
    }



    LinkedList<double> lst;
    lst.PushBack(1.0);
    lst.PushBack(2.0);
    lst.PushBack(3.0);
    lst.PushBack(4.0);
    lst.PushBack(5.0);

    std::cout<<lst[1]->data<<"\n";

    lst.insert(2, -2.5);
    lst.insert(20, 100);

    lst.erase(3);
    lst.erase(30);
   

    for (Node<double>* ptr = lst.head; ptr !=NULL; ptr = ptr->next){
        std::cout <<ptr->data<<" ";
    }
    std::cout<<"\n";
    for (Node<double>* ptr = lst.tail; ptr != 0; ptr = ptr->prev){
        std::cout<<ptr->data<<" ";
    }
    return 0;
}