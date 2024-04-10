#include"Manager.h"

Manager::Manager(){ 
    this->Username = "manager123";
    this->Password = "102220316";
}

Manager::~Manager(){

}

void Manager::AddStaff(StaffList& sl, Staff s){
    sl.Insert(s);
}

void Manager::RemoveStaff(StaffList& sl, Staff s){
    sl.Delete(s);
}

void Manager::StaffInfo(StaffList sl){
    sl.Display();
}

void Manager::CustomerInfo(CustomerList cl){
    cl.Display();
}

void Manager::AddFood(Menu& m, Food f){
    m.Insert(f);
}

void Manager::RemoveFood(Menu& m, Food f){
    m.Delete(f);
}

void Manager::UpdateMenu(Menu& m){
    cout << "Nhap ma mon an muon cap nhat gia: ";
    int id; cin >> id;
    Node<Food> *nf = m.Find(id); 
    cout << "Nhap gia tien cho mon an: ";
    int newPrice; cin >> newPrice;
    nf->data.setPrice(newPrice);
    cout << "Cap nhat thanh cong!" << endl;
}

void Manager::ViewMenu(Menu m){
    m.Display();
}

void Manager::ViewOrders(Orders ods){
    ods.Display();
}

void Manager::RevenueStatistics(BillList bl){
    bl.Display();
}