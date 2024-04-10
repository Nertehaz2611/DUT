#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double x = 1234.5;
    cout << setiosflags(ios::showpoint) << setprecision(3);
    cout << x;

    return 0;
}