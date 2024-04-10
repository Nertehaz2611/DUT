#include"SV.h"

SV::SV(string m, string n, bool g, double d)
    : MSSV(m), Name(n), Gender(g), DTB(d) {
}

SV::~SV(){
    cout << "Huy SV" << endl;
}

ostream& operator<<(ostream& o, const SV& s){
    string gt = (s.Gender)? "Nam" : "Nu";
    o << s.MSSV << " " << s.Name << " " << gt << " " << s.DTB << endl;
    return o;
}

void SV::Show(){
    cout << *this;
}

const SV& SV::operator=(const SV& s){
    this->MSSV = s.MSSV;
    this->Name = s.Name;
    this->Gender = s.Gender;
    this->DTB = s.DTB;
    return *this;
}

bool SV::operator==(const SV& s){
    return (this->MSSV == s.MSSV);
}