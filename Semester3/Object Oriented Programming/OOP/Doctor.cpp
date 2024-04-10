#include"Doctor.h"

Doctor::Doctor(int id, string name) : IDDoctor(id), nameD(name) {

}

Doctor::~Doctor(){
    this->ListB.clear();
}

void Doctor::setIDDoctor(int id){
    this->IDDoctor = id;
}

int Doctor::getIDDoctor() const {
    return this->IDDoctor;
}

void Doctor::setnameD(string name){
    this->nameD = name;
}

string Doctor::getnameD() const {
    return this->nameD;
}

void Doctor::addBenhAn(BenhAn* b){
    this->ListB.push_back(b);
}
