#include"Exp.h"
Exp::Exp(string s) : sms(s) {

}

Exp::~Exp(){

}

ostream& operator<<(ostream& o, const Exp& e){
    o << e.sms << endl;
    return o;
}