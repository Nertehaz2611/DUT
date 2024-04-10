#include"Order.h"

Order::Order(){
    this->Status = 0;
    this->Confirmed = 0;
    this->ID = 0;
    this->FoodCount = 0;
}

Order::~Order(){
}


void Order::setID(int ID){
    this->ID = ID;
}

int Order::getID(){
    return this->ID;
}

void Order::setCustomerName(string c){
    this->CustomerName = c;
}

string Order::getCustomerName(){
    return this->CustomerName;
}

void Order::setCustomerPhone(string p){
    this->CustomerPhone = p;
}

string Order::getCustomerPhone(){
    return this->CustomerPhone;
}

void Order::setTableNumber(int num){
    this->TableNumber = num;
}

int Order::getTableNumber(){
    return this->TableNumber;
}

void Order::setStatus(bool s){
    this->Status = s;
}

bool Order::getStatus(){
    return this->Status;
}

void Order::setConfirmed(bool c){
    this->Confirmed = c;
}

bool Order::getConfirmed(){
    return this->Confirmed;
}

void Order::setFoodCount(int c){
    this->FoodCount = c;
}

int Order::getFoodCount(){
    return this->FoodCount;
}

void Order::setList(FoodsOrdered list){
    this->list = list;
}

FoodsOrdered Order::getList(){
    return this->list;
}

void Order::Show(){
    cout << "Ma don hang: " << this->ID << endl;
    cout << "Khach Hang: " << this->CustomerName << endl;
    cout << "SDT: " << this->CustomerPhone << endl;
    cout << "Ma ban: " << this->TableNumber << endl;
    cout << "So luong mon da dat: " << this->FoodCount << endl;
    cout << "Ma mon" << setw(35) << "Ten mon" << setw(30) << "Gia thanh" << endl << endl;
    this->list.Display();
    cout << "Trang thai: ";
    if (this->getStatus()){
        cout << "Da hoan thanh" << endl;
    }
    else cout << "Chua hoan thanh" << endl;
}
