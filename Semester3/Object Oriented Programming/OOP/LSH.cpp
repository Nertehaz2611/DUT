#include"LSH.h"

LSH::LSH(string m, int k) : MaLSH(m), Khoa(k) {
    cout << "Dung LSH" << endl;
}

LSH::~LSH(){
    cout << "Huy LSH" << endl;
}

void LSH::ShowLSH(){
    cout << this->MaLSH << " " << this->Khoa << endl;
}

void LSH::Show(){
    cout << "LSH" << endl;
}