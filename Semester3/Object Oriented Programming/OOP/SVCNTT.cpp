#include"SVCNTT.h"

SVCNTT::SVCNTT(string m, string n, bool g, double d, string l)
    : SV(m, n, g, d), LT(l) {
}

SVCNTT::~SVCNTT(){
    cout << "Xoa SVCNTT" << endl;
}

void SVCNTT::LapTrinh(){
    cout << this->LT << endl;
}

void SVCNTT::Show(){
    cout << *this;
}

ostream& operator<<(ostream& o, const SVCNTT& s){
    string gt = (s.Gender)? "Nam" : "Nu";
    o << s.MSSV << " " << s.Name << " " << gt << " " << s.DTB << " " << s.LT << endl;
    return o;
}

const SVCNTT& SVCNTT::operator=(const SVCNTT& s){
    this->MSSV = s.MSSV;
    this->Name = s.Name;
    this->Gender = s.Gender;
    this->DTB = s.DTB;
    this->LT = s.LT;
    return *this;
}

bool SVCNTT::operator==(const SVCNTT& s){
    return (this->MSSV == s.MSSV && this->LT == s.LT);
}