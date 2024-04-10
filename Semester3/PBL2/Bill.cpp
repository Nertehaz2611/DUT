#include"Bill.h"

Bill::Bill(){
    
}

Bill::Bill(Order od) : o(od), BillID(od.getID()) {
}

Bill::~Bill(){

}

void Bill::setBillID(int ID){
    this->BillID = ID;
}

int Bill::getBillID(){
    return this->BillID;
}

void Bill::setSumPrice(){
    int sum = 0;
    for (Node<Food>* k = this->o.list.head; k != NULL; k = k->next){
        sum += k->data.getPrice();
    }
    this->SumPrice = sum;
}

int Bill::getSumPrice(){
    return this->SumPrice;
}

void Bill::setSPrice(int s){
    this->SumPrice = s;
}

void Bill::setOrder(Order o){
    this->o = o;
}

Order Bill::getOrder(){
    return this->o;
}

void Bill::Show(){
    cout << "Ma hoa don: " << this->BillID << endl;
    cout << "Ma don hang: " << this->o.getID() << endl;
    cout << "Khach hang: " << this->o.getCustomerName() << endl;
    cout << "So dien thoai: " << this->o.getCustomerPhone() << endl;
    cout << "Ma ban: " << this->o.getTableNumber() << endl;
    this->o.list.Display();
    this->setSumPrice();
    cout << "Tong thanh tien: " << this->SumPrice << endl;
}
