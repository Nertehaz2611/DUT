#pragma once
#include"List.h"
#include"Customer.h"

class CustomerList : public List<Customer> {
    public:
        Node<Customer>* Find(int id){
            
        }
        Node<Customer>* FindString(string sdt){
            Node<Customer>* k = this->head;
            for (k; k != NULL; k = k->next){
                if (k->data.getPhoneNumber() == sdt) break;
            }
            return k;
        }
        void Sort(){
            Node<Customer>* i = this->head;
            for (i; i != NULL; i = i->next){
                for(Node<Customer>* j = i->next; j != NULL; j = j->next){
                    if (i->data.getID() > j->data.getID()){
                        Customer c = i->data;
                        i->data = j->data;
                        j->data = c;
                    }
                }
            }
        }
        void Display(){
            for (Node<Customer>* k = this->head; k != NULL; k = k->next){
                cout << "\n=================================\n" << endl;
                k->data.Show();
            }
            cout << "\n=================================\n";
        }
};