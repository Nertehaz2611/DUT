#include<iostream>

using namespace std;

//Truyen tham chieu
/*
void hv(int &a, int &b){
    int t = a;
    a = b ;
    b = t;
}
*/

//Truyen con tro
void hv(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


int main(){
    int x = 5, y = 9;
    hv(&x, &y); //Dang dung truyen con tro
    //Neu dung truyen tham chieu thi dung lenh hv(x, y);
    cout << x << ", " << y;
    return 0;
}
