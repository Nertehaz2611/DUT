#pragma once
#include"Orders.h"
#include"User.h"
#include"Menu.h"
#include"BillList.h"

class Customer : public User {
    private:
        int ID;
        string Name;
        string PhoneNumber;
        BillList TransactionHistory;
    public:
        Customer();
        Customer(string, string, string);
        virtual ~Customer();
        void setID(int);
        int getID();
        void setName(string);
        string getName();
        void setPhoneNumber(string);
        string getPhoneNumber();
        void setPassWord(string);
        string getPassWord();
        BillList getTransactionHistory();
        void ViewMenu(Menu);
        void ViewOrder(Orders);
        void Ordering(Menu, Orders&);
        void OrderConfirm(Orders, BillList);
        void ViewTransactionHistory(Orders, BillList);
        void Show();

        bool operator==(Customer);
};