#pragma once
#include <cstddef>
#include <iostream>
using namespace std;


template <typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;

        inline Node(){
            this->next = NULL;
            this->prev = NULL;
        }

        inline Node(T data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        T getNode(){
            return this->data;
        }
};

template <typename T>
class List{
    public:
        Node<T>* head;
        Node<T>* tail;
    public:
        List(){
            this->head = NULL;
            this->tail = this->head;
        }

        ~List(){

        }

        void Insert(T data){
            Node<T>* p = new Node<T>;
            p->data = data;
            p->next = NULL;
            p->prev = NULL;
            if (this->head == NULL){
                this->head = p;
                this->tail = p;
                return;
            }
            else {
                this->tail->next = p;
                p->prev = this->tail;
                this->tail = p;
            }
        }
        void Delete(T data){
            if(this->head == NULL){
                cout << "Danh sach trong!" << endl;
                return;
            }
            if (this->head->data == data && this->head->next == NULL){
                this->head = NULL;
                this->tail = this->head;
                return;
            }
            if (this->head->data == data && this->head->next != NULL){
                this->head = this->head->next;
                this->head->prev = NULL;
                return;
            }
            if (this->tail->data == data){
                this->tail = this->tail->prev;
                this->tail->next = NULL;
                return;
            }
            for (Node<T>* k = this->head; k->next != NULL; k = k->next){
                if (k->next->data == data){
                    k->next = k->next->next;
                    k = k->next;
                    k->prev = k->prev->prev;
                    return;
                }
            }
        }
        
        virtual Node<T>* Find(int) = 0; 
        virtual Node<T>* FindString(string) = 0;
        virtual void Display() = 0;
};