#include<iostream>
using namespace std;

class HP {
    private:
        string MaHP;
        int SL;
    public:
        HP(string = "", int = 0);
        ~HP();
        void ShowHP();
        virtual void Show();
};