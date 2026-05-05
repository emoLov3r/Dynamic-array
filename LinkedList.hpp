#pragma once
#include <cstddef>

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T& data){
        this->data = data;
        this->prev = this->next = NULL;
    }
        
};

template<typename T>
class LinkedList{
    private:
    //    Node<T>* head;
    //    Node<T>* tail;
    public:
        Node<T>* head;
        Node<T>* tail;
        LinkedList(){
            head = tail = nullptr;
        }
    ~LinkedList(){
        while(head != nullptr){
            PopFront();
        }
    }

        Node<T>* PushFront(const T& data){
            Node<T>* ptr = new Node<T>(data);
            ptr->next = head;
            if (head != nullptr){
                head->prev = ptr;
            }
            if (tail == nullptr){
                tail = ptr;
            }
            head = ptr;
            return ptr;
        }

        Node<T>* PushBack(const T& data){
            Node<T>* ptr = new Node<T>(data);
            ptr->prev = tail;
            if (tail != nullptr){
                tail->next = ptr;
            }
            if (head == nullptr){
                head = ptr;
            }
            tail = ptr;
            return ptr;
        }

        void PopFront(){
            if (head == nullptr){
                return;
            }
            Node<T>* ptr = head->next;
            if (ptr != nullptr){
                ptr->prev = nullptr;
            }else{
                tail = ptr;
            }
            delete head;
            head = ptr;
        }


        void PopBack(){
            if (tail == nullptr){
                return;
            }
            Node<T>* ptr = tail->prev;
            if (ptr != nullptr){
                ptr->next = nullptr;
            }else{
                head = ptr;
            }
            delete tail;
            tail = ptr;
        }

        Node<T>* GetAt(size_t index){
            Node<T>* ptr = head;
            size_t n = 0;

            while (n != index){
                if (ptr == nullptr){
                    return ptr;
                }
                ptr = ptr->next;
                n++;
            }
            return ptr;
        }

        Node<T>* operator[](size_t index){
            return GetAt(index);
        }

        Node<T>* insert(size_t index, const T& data){
            Node<T>* right = GetAt(index);
            if(right == nullptr){
                return PushBack(data);
            }
            Node<T>* left = right->prev;
            if (left == nullptr){
                return PushFront(data);
            }
            Node<T>* ptr = new Node<T>(data);
            ptr->prev = left;
            ptr->next = right;
            left->next = ptr;
            right->prev = ptr;

            return ptr;
        }

        void erase(size_t index){
            Node<T>* ptr = GetAt(index);
            if (ptr == nullptr){
                return;
            }
            if (ptr->prev == nullptr){
                PopFront();
                return;
            }
            if (ptr->next == nullptr){
                PopBack();
                return;
            }
            Node<T>* left = ptr->prev;
            Node<T>* right = ptr->next;
            left->next = right;
            right->prev = left;
            delete ptr;
        }
};







