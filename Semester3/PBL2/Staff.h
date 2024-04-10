#pragma once
#include"Orders.h"
#include"User.h"

class Staff : public User {
    private:
        string Name;
        bool Sex;
        int BirthYear;
        string PhoneNumber;
    public:
        Staff();
        Staff(string, bool, int, string);
        virtual ~Staff();
        void setName(string);
        void setSex(bool);
        void setBirthYear(int);
        void setPhoneNumber(string);
        string getName();
        bool getSex();
        int getBirthYear();
        string getPhoneNumber();
        void Show();
        void ViewOrders(Orders);
        void RecieveOrder(Orders, int);

        bool operator==(Staff);
};