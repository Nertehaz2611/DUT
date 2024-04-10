#pragma once 
#include"List.h"
#include"Order.h"

class Orders : public List<Order> {
    public:
        Node<Order>* Find(int id){
            Node<Order>* k = this->head;
            for (k; k != NULL; k = k->next){
                if (k->data.getID() == id) break;
            }
            return k;
        }
        Node<Order>* FindString(string s){

        }
        void Display(){
            for (Node<Order>* k = this->head; k != NULL; k = k->next){
                cout << "\n==================================================================\n" << endl;
                k->data.Show();
                }
            cout << "\n==================================================================\n";
        }
};