#include<iostream>

using namespace std;

int main(){
    int x = 5;
    const int y = 4;
    // const int &z = y;
    // const int &z = x;
    // cout << x << ", " << z << endl;
    // x = 10;
    // cout << x << ", " << z << endl;
    const int &z = 3;
    cout << z << endl;

    return 0;
}