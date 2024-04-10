#include<iostream>
using namespace std;

class Matrix{
    private:
        int **p;
        int row, col;
    public:
        Matrix(int, int, int);
        ~Matrix();
        void Show();
        friend ostream& operator<<(ostream& o, const Matrix&);
        int& operator()(const int&, const int&);
};