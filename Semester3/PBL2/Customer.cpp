#include"Customer.h"
#include<conio.h>


Customer::Customer(){

}

Customer::Customer(string name, string phone, string pw) : Name(name), PhoneNumber(phone) {
    this->Password = pw;
}

Customer::~Customer(){

}

void Customer::setID(int id){
    this->ID = id;
}

int Customer::getID(){
    return this->ID;
}

void Customer::setName(string name){
    this->Name = name;
}

string Customer::getName(){
    return this->Name;
}

void Customer::setPhoneNumber(string phone){
    this->PhoneNumber = phone;
}

string Customer::getPhoneNumber(){
    return this->PhoneNumber;
}

void Customer::setPassWord(string pw){
    this->Password = pw;
}

string Customer::getPassWord(){
    return this->Password;
}

void Customer::ViewMenu(Menu m){
    m.Display();
}

void Customer::ViewOrder(Orders ods){
    for (Node<Order>* k = ods.head; k != NULL; k = k->next){
        if (k->data.getCustomerPhone() == this->PhoneNumber){
            cout << "\n=================================\n" << endl;
            k->data.Show();
        }
    }
    cout << "\n=================================\n";
}

void Customer::Ordering(Menu m, Orders& ods){
    Order o;
    o.setCustomerName(this->Name);
    o.setCustomerPhone(this->PhoneNumber);
    o.setID(o.getID());
    int TableID;
    cout << "Nhap ma ban: ";
    cin >> TableID;
    o.setTableNumber(TableID);
    m.Display();
    cout << "Nhap ma mon an (Nhap 0 de ket thuc chon mon): " << endl;
    int FoodID;
    Node<Food>* Food;
    while (FoodID != 0){
        cin >> FoodID;
        if (FoodID == 0) break;
        Food = m.Find(FoodID);
        if (Food == NULL){
            cout << "Khong ton tai mon nay" << endl; 
        }
        else {
            Food->data.setCount(Food->data.getCount() + 1);
            o.setFoodCount(o.getFoodCount() + 1);
            o.list.Insert(Food->data);
            cout << "Them mon an thanh cong, hay tiep tuc chon mon: " << endl;
        }
    }
    cout << endl << "Ban da dat nhung mon sau: " << endl;
    o.list.Display();
    cout << endl;
    XacNhan:
    cout << "Ban co xac nhan don hang khong?" << endl;
    cout << "1. Co" << endl << "2. Khong" << endl;
    cout << "Nhap 1 de xac nhan don hang, nhap 2 de huy don hang: ";
    int choice;
    cin >> choice;
    if (choice == 1){
        o.setID(ods.tail->data.getID()+1);
        ods.Insert(o);
        cout << "Xac nhan thanh cong!" << endl;
    }
    else if (choice == 2){
        cout << "Huy thanh cong!" << endl;
    }
    else {
        cout << "Khong hop le! Nhan Enter de xac nhan lai";
        _getch();
        goto XacNhan;
    }
}

void Customer::OrderConfirm(Orders ods, BillList bl){
    for (Node<Order>* k = ods.head; k != NULL; k = k->next){
        if (k->data.getCustomerName() == this->Name && k->data.getStatus() == 1){
            k->data.setConfirmed(!k->data.getConfirmed());
            Bill b(k->data);
            this->TransactionHistory.Insert(b);
            bl.Insert(b);
        }
    }
}

void Customer::ViewTransactionHistory(Orders ods, BillList bl){
    OrderConfirm(ods, bl);
    this->TransactionHistory.Display();
}

BillList Customer::getTransactionHistory(){
    return this->TransactionHistory;
}

void Customer::Show(){ 
    cout << "Ten khach hang: " << this->Name << endl;
    cout << "So dien thoai: " << this->PhoneNumber << endl;
}

bool Customer::operator==(Customer c){
    return (this->Name == c.Name && this->PhoneNumber == c.PhoneNumber);
}