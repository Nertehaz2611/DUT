#include<iostream>
using namespace std;

void Show(int **p, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << *(*(p+i)+j) << " ";
        }
        cout << endl;
    }
}

int main(){
    int **p;
    int r, c; cin >> r >> c;
    p = new int*[r];
    for (int i = 0; i < r; i++){
        *(p+i) = new int[c];
        for (int j = 0; j < c; j++){
            *(*(p+i)+j) = 3;
        }
    }
    Show(p, r, c);
    for (int i = 0; i < r; i++){
        delete[] *(p+i);
    }
    delete[] p;
    return 0;
}