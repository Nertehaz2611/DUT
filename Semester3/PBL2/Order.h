#pragma once
#include"List.h"
#include"Food.h"

using namespace std;

class FoodsOrdered : public List<Food> {
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
        void Display(){
            for (Node<Food>* k = this->head; k != NULL; k = k->next){
                k->data.Show();
            }
        }
};

class Order {
    protected:
        int ID;
        string CustomerName;
        string CustomerPhone;
        int TableNumber;
        bool Status;
        bool Confirmed;
        int FoodCount;
    public:
        FoodsOrdered list;
        Order();
        virtual ~Order();
        void setID(int);
        int getID();
        void setCustomerName(string);
        string getCustomerName();
        void setCustomerPhone(string);
        string getCustomerPhone();
        void setTableNumber(int);
        int getTableNumber();
        void setStatus(bool);
        bool getStatus();
        void setConfirmed(bool);
        bool getConfirmed();
        void setFoodCount(int);
        int getFoodCount();
        void setList(FoodsOrdered);
        FoodsOrdered getList();
        void Show();
};