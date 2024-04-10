#include<iostream>
using namespace std;

class LSH {
    private:
        string MaLSH;
        int Khoa;
    public:
        LSH(string = "", int = 1990);
        ~LSH();
        void ShowLSH();
        virtual void Show();
};