#include<iostream>
using namespace std;

int main(){
    int x = 10, y  = 20;
    int *p1, *p2;
    p1 = &x; p2 = &y;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    *p1 = 50; *p2 = 90;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    *p1 = *p2;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    return 0;
}