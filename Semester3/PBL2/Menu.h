#pragma once
#include"List.h"
#include"Food.h"

class Menu : public List<Food> {
    public:
        Node<Food>* Find(int id){
            Node<Food>* k = this->head;
            for (k; k != NULL; k = k->next){
                if (k->data.getID() == id) break;
            }
            return k;
        }
        Node<Food>* FindString(string s){
            
        }
        void Sort(){
            Node<Food>* i = this->head;
            for (i; i != NULL; i = i->next){
                for(Node<Food>* j = i->next; j != NULL; j = j->next){
                    if (i->data.getID() > j->data.getID()){
                        Food f = i->data;
                        i->data = j->data;
                        j->data = f;
                    }
                }
            }
        }
        void Display(){
            cout << "================================ MENU =================================" << endl << endl;
            cout << "Ma mon" << setw(35) << "Ten mon" << setw(30) << "Gia thanh" << endl << endl;
            for (Node<Food>* k = this->head; k != NULL; k = k->next){
                k->data.Show();
            }
            cout << endl << "=======================================================================" << endl;
        }
};