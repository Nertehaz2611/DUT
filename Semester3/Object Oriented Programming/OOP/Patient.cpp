#include"Patient.h"

Patient::Patient(int id, string name) : IDPatient(id), nameP(name) {

}

Patient::~Patient(){
    this->ListB.clear();
}

void Patient::setIDPatient(int id){
    this->IDPatient = id;
}

int Patient::getIDPatient() const {
    return this->IDPatient;
}

void Patient::setnameP(string name){
    this->nameP = name;
}

string Patient::getnameP() const {
    return this->nameP;
}

void Patient::addBenhAn(BenhAn* b){
    this->ListB.push_back(b);
}