#include"BenhAn.h"

BenhAn::BenhAn(int ba, Patient* p, Doctor* d) : IDBA(ba), p(p), d(d){

}

BenhAn::~BenhAn(){

}

void BenhAn::setIDBA(int id){
    this->IDBA = id;
}

int BenhAn::getIDBA(){
    return this->IDBA;
}

Patient* BenhAn::getPatient(){
    return this->p;
}

Doctor* BenhAn::getDoctor(){
    return this->d;
}