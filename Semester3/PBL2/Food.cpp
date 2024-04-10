#include"Food.h"

Food::Food(){
    this->Count = 0;
}

Food::Food(int ID, string Name, int Price) : ID(ID), Name(Name), Price(Price) {
    this->Count = 0;
}

Food::~Food(){
}

void Food::setID(int ID){
    this->ID = ID;
}

int Food::getID(){
    return this->ID;
}

void Food::setName(string Name){
    this->Name = Name;
}

string Food::getName(){
    return this->Name;
}

void Food::setPrice(int Price){
    this->Price = Price;
}

int Food::getPrice(){
    return this->Price;
}

void Food::setCount(int c){
    this->Count = c;
}

int Food::getCount(){
    return this->Count;
}

void Food::Show(){
    cout << this->ID << setw(40) << this->Name << setw(30) << this->Price << endl;
}

void Food::ShowInOrder(){
    cout << this->ID << " " << this->Name << endl;
}

bool Food::operator==(Food f){
    return (this->ID == f.ID);
}


