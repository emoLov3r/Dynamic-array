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

        DynamicArray(const DynamicArray& other){ //используем ссылку, чтобы не копировать объект 
            other.size = size;
            data = new T[size]; //выделение новой памяти
            for (size_t i = 0; i < size; i++){
                data[i] = other.data[i];            }
            }

};
