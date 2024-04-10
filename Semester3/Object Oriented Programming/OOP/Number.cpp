#include<iostream>
#include"Number.h"
using namespace std;

Number::Number(double d) : d(d) {
}

Number::~Number(){
}

Number::operator int(){
    return int(this->d);
}

Number::operator double(){
    return double(this->d);
}