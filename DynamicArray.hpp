#pragma once
#include <cstddef>

template<typename T>
class DynamicArray {
    private:
        size_t size;
        size_t capacity;
        T *data;
    public:
        DynamicArray() : size(0), capacity(0), data(nullptr) {}

        ~DynamicArray(){
            delete[] data;
        }

        size_t GetSize() const{ //const для работы с константными объектами
            return size;
        }

        DynamicArray(const DynamicArray& other){ //конструктор копирования
            size = other.size;
            capacity = other.capacity;
            data = new T[size]; 
            for (size_t i = 0; i < size; i++){
                data[i] = other.data[i];            
            }
        }

        DynamicArray<T>& operator= (const DynamicArray& other){ //конструктор копирования присваиванием
            if (this != &other){

                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = new T[size]; 
                for (size_t i = 0; i < size; i++){
                    data[i] = other.data[i];            
                }
            }
            
            return *this;
        }
        
        DynamicArray (DynamicArray&& other){ //конструктор перемещения
            size = other.size;
            capacity = other.capacity;
            data = other.data;
            
            other.size = 0;
            other.capacity = 0;
            other.data = nullptr;
        }

        DynamicArray<T>& operator= (DynamicArray&& other){ //конструктор перемещения присваиванием
            if (this != &other){
                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = other.data;
                        
                other.size = 0;
                other.capacity = 0;
                other.data = nullptr;
            }


            return *this;
        }

        void PushBack(const T& value){
            if (size == capacity){
                size_t newCapacity;
                if (capacity == 0){
                    newCapacity = 1;
                }else{
                    newCapacity = capacity * 2;
                }
                T* newData = new T[newCapacity];
                for (size_t i = 0; i < size; i++){
                    newData[i] = data[i];
                }

                delete[] data;
                
                data = newData;
                capacity = newCapacity;
            }
            data[size] = value;
            ++size;
        }
        
        const T& operator[](size_t index){
            return data[index];
        }

        T* GetAt(size_t index){
            if (index >= size){
                return nullptr;
            }
            return &data[index];
        }

        int IsEmpty() const{
            if  (size > 0){
                return 0;
            } else{
                return 1;
            }
        }

        void clear(){
            size = 0;
        }

        void Reserve(size_t newCapacity){
            if (newCapacity <= capacity){
                return;
            }
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; i++){
                newData[i] = data[i];
            }
            delete[]data;
            data = newData;
            capacity = newCapacity;
        }
 
        void PopBack(){
            if (size > 0){
                --size;
            }
        }

};


