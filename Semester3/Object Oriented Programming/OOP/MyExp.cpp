#include"MyExp.h"
MyExp::MyExp(string s, int m) : Exp(s), m(m) {

}

MyExp::~MyExp(){

}

ostream& operator<<(ostream& o, const MyExp& e){
    o << e.sms << " " << e.m << endl;
    return o;
}