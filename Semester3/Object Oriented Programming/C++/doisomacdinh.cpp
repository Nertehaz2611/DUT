#include<iostream>

using namespace std;

void Show(int x, int y = 1, int z = 2){
    cout << x << y << z << endl;
}

int main(){
    //Show();
    Show(1);
    Show(1, 2);
    Show(1, 2, 3);
    //Show(1,  , 1);

    return 0;
}