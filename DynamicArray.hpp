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

        DynamicArray(const DynamicArray& other){ //конструктор копирования
            size = other.size;
            data = new T[size]; 
            for (size_t i = 0; i < size; i++){
                data[i] = other.data[i];            
            }
        }

        DynamicArray<T>& operator= (const DynamicArray& other){ //конструктор копирования присваиванием
            if (this != &other){

                delete[] data;
                size = other.size;
                data = new T[size]; 
                for (size_t i = 0; i < size; i++){
                    data[i] = other.data[i];            
                }
            }
            
            return *this;
        }
        
        DynamicArray (DynamicArray&& other){ //конструктор перемещения
            size = other.size;
            data = other.data;
            
            other.size = 0;
            other.data = nullptr;
        }

        DynamicArray<T>& operator= (DynamicArray&& other){ //конструктор перемещения присваиванием
            if (this != &other){
                delete[] data;
                size = other.size;
                data = other.data;
                        
                other.size = 0;
                other.data = nullptr;
            }


            return *this;
        }
};


