#include"Staff.h"

Staff::Staff(){

}

Staff::Staff(string name, bool sex, int year, string phonenum) : Name(name), Sex(sex), BirthYear(year), PhoneNumber(phonenum) {

}

Staff::~Staff(){

}

void Staff::setName(string name){
    this->Name = name;
}

string Staff::getName(){
    return this->Name;
}

void Staff::setSex(bool sex){
    this->Sex = sex;
}

bool Staff::getSex(){
    return this->Sex;
}

void Staff::setBirthYear(int year){
    this->BirthYear = year;
}

int Staff::getBirthYear(){
    return this->BirthYear;
}

void Staff::setPhoneNumber(string phonenum){
    this->PhoneNumber = phonenum;
}

string Staff::getPhoneNumber(){
    return this->PhoneNumber;
}

void Staff::Show(){
    cout << "Ten nhan vien: " << this->Name << endl;
    cout << "Gioi tinh: " << ((this->Sex) ? "Nam" : "Nu") << endl;
    cout << "Nam sinh: " << this->BirthYear << endl;
    cout << "So dien thoai: " << this->PhoneNumber << endl;
}

void Staff::ViewOrders(Orders ods){
    ods.Display();
}

void Staff::RecieveOrder(Orders ods, int id){
    Node<Order>* tmp = ods.Find(id);
    if (tmp == NULL){
        cout << "Khong co don hang nay trong danh sach" << endl;
    }
    else if (tmp->data.getStatus()){
        cout << "Don hang nay da duoc hoan thanh truoc do, hay chon don hang khac" << endl;
    }
    else {
        tmp->data.setStatus(true);
        cout << "Da hoan thanh don hang" << endl;
    }
}

bool Staff::operator==(Staff s){
    return (this->Name == s.Name && this->PhoneNumber == s.PhoneNumber);
}