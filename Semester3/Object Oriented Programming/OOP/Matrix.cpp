#include "Matrix.h"

Matrix::Matrix(int r, int c, int t):
    row(r), col(c) {
    this->p = new int*[this->row];
    for (int i = 0; i < this->row; i++){
        *(this->p + i) = new int[this->col];
        for (int j = 0; j < this->col; j++){
            *(*(this->p + i) + j) = t;
            //this->p[i][j] = t;
            //(*this).p[i][j] = t;
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < this->row; i++){
        delete[] *(this->p + i);
    }
    delete[] p;
}

void Matrix::Show(){
    for (int i = 0; i < this->row; i++){
        for (int j = 0; j < this->col; j++){
            cout << *(*(this->p + i) + j) << " ";
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& o, const Matrix& m){
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            o << *(*(m.p + i) + j) << " ";
        }
        o << endl;
    }
    return o;
}

int& Matrix::operator()(const int& i, const int& j){
    static int NGU = 0;
    return (i >= 0 && i < this->row && j >= 0 && j < this->col) ? *(*(this->p + i) + j) : NGU;
}