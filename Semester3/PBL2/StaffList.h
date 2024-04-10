#pragma once
#include"Staff.h"
#include"List.h"

class StaffList : public List<Staff> {
    public:
        Node<Staff>* FindString(string sdt){
            Node<Staff>* k = this->head;
            for (k; k != NULL; k = k->next){
                if (k->data.getPhoneNumber() == sdt) break;
            }
            return k;
        }
        Node<Staff>* Find(int id){

        }
        void Display(){
            if (this->head == NULL) return;
            for (Node<Staff>* k = this->head; k != NULL; k = k->next){
                cout << "\n=================================\n" << endl;
                k->data.Show();
            }
            cout << "\n=================================\n";
        }
};