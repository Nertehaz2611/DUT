#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class Food {
    private:
        int ID;
        string Name;
        int Price;
        int Count;
    public:
        Food();
        Food(int, string, int);
        virtual ~Food();
        void setID(int);
        int getID();
        void setName(string);
        string getName();
        void setPrice(int);
        int getPrice();
        void setCount(int);
        int getCount();
        void Show();
        void ShowInOrder();

        bool operator==(Food);
};