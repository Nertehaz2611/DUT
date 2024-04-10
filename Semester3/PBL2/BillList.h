#pragma once
#include"List.h"
#include"Bill.h"

class BillList : public List<Bill> {
    public:
        Node<Bill>* Find(int id){
            Node<Bill>* k = this->head;
            for (k; k != NULL; k = k->next){
                if (k->data.getBillID() == id) break;
            }
            return k;
        }
        Node<Bill>* FindString(string s){
            
        }
        void Display(){
            for (Node<Bill>* k = this->head; k != NULL; k = k->next){
                cout << "\n==================================================================\n" << endl;
                k->data.Show();
            }
            cout << "\n==================================================================\n";
        }
};