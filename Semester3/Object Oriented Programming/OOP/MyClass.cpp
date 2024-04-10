#include"MyClass.h"

MyClass::MyClass(string s) : sms(s){

}

MyClass::~MyClass(){

}

void MyClass::MC(){
    cout << this->sms << endl;
}

void MyClass::A(){
    cout << "MC - A" << endl;
}