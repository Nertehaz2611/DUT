#include"HP.h"

HP::HP(string m, int s) : MaHP(m), SL(s) {
    cout << "Dung HP" << endl;
}

HP::~HP(){
    cout << "Huy HP" << endl;
}

void HP::ShowHP(){
    cout << this->MaHP << " " << this->SL << endl;
}

void HP::Show(){
    cout << "HP" << endl;
}