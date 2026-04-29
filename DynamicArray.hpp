#pragma once
#include <cstddef>

template<typename T>
class DynamicArray {
    private:
        size_t size;
        T *data;
    public:
        DynamicArray() : size(5) {
            data = new T[size];
        };

        ~DynamicArray(){
            delete[] data;
        }

        size_t GetSize(){
            return size;
        }

};
