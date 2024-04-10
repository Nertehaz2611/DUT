#include<iostream>

using namespace std;

int main(){
    int x = 2, y =3;
    const int* p = &x; //con tro hang
    //(*p) = 3; lenh nay bao loi vi khong the thong qua con tro hang de thay doi gia tri cua bien
    cout << *p << endl;
    p = &y; //lenh nay duoc thuc hien vi con tro hang co the tro den nhieu dia chi khac nhau
    cout << *p << endl;

    int* const p1 = &x; //hang con tro
    *p1 = 10;
    cout << *p1 << endl;
    //p1 = &y; lenh nay bao loi vi hang con tro chi duoc tro den dia chi cua bien dau tien ma no tro vao
    return 0;
}

