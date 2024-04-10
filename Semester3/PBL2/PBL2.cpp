#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include"Manager.h"

using namespace std;

Node<Customer>* uc = new Node<Customer>;
Node<Staff>* uf = new Node<Staff>;
StaffList sl;
CustomerList cl;
Orders ods;
BillList bl;
Menu m;
Manager mng;
fstream sf, cf, mf, of, bf;
int sCount = 0, cCount = 0, bCount = 0, oCount = 0, mCount = 0;

void SetupStaff(){
	sf.open("Staff.txt");
	sf.ignore(256, ':');
	sf >> sCount;
	string name, phoneNum;
	bool sex;
	int year;
	for (int i = 0; i < sCount; i++){
        sf.ignore(256, ':');
        sf.ignore(256, ' ');
        getline(sf, name);
        sf.ignore(256, ':');
        sf.ignore(256, ' ');
        sf >> sex;
		sf.ignore(256, ':');
        sf.ignore(256, ' ');
		sf >> year;
		sf.ignore(256, ':');
        sf.ignore(256, ' ');
		getline(sf, phoneNum);
		Staff s(name, sex, year, phoneNum);
		sl.Insert(s);
	}
	sf.close();
}

void SetupMenu(){
	mf.open("Menu.txt");
	mf.ignore(256, ':');
	mf >> mCount;
	int id, val;
	string name;
	for (int i = 0; i < mCount; i++){
		mf >> id;
        mf.ignore(1, '|');
        getline(mf, name, '|');
        mf >> val;
        Food f(id, name, val);
		m.Insert(f);
	}
	m.Sort();
	mf.close();
}

void SetupCustomer(){
	cf.open("Customer.txt");
	cf.ignore(256, ':');
	cf >> cCount;
	string name, phoneNum, password;
	for (int i = 0; i < cCount; i++){
        cf.ignore(256, ':');
        cf.ignore(256, ' ');
        getline(cf, name);
    	cf.ignore(256, ':');
        cf.ignore(256, ' ');
        getline(cf, phoneNum);
		cf.ignore(256, ':');
        cf.ignore(256, ' ');
		getline(cf, password);
		Customer c(name, phoneNum, password);
		cl.Insert(c);
	}
	cf.close();
}

void SetupOrder(){
	of.open("Order.txt");
	of.ignore(256, ':');
	of >> oCount;
	int ID, TableNumber, FoodCount;
	string Name, PhoneNum;
	bool Status;
	for (int i = 0; i < oCount; i++){
		of.ignore(256, ':');
		of >> ID;
		of.ignore(256, ':');
		of.ignore(256, ' ');
		getline(of, Name);
		of.ignore(256, ':');
		of.ignore(256, ' ');
		getline(of, PhoneNum);
		of.ignore(256, ':');
		of >> TableNumber;
		of.ignore(256, ':');
		of >> FoodCount;
		FoodsOrdered list;
		of.ignore(256, 'h');
		of.ignore(256, 'h');
		int OdFoodID, OdFoodPrice;
		string OdFoodName;
		for (int j = 0; j < FoodCount; j++){
			of >> OdFoodID;
			of.ignore(256, '_');
			getline(of, OdFoodName, '_');
			of >> OdFoodPrice;
			Food f(OdFoodID, OdFoodName, OdFoodPrice);
			list.Insert(f);
		}
		of.ignore(256, ':');
		of >> Status;
		Order o;
		o.setID(ID);
		o.setCustomerName(Name);
		o.setCustomerPhone(PhoneNum);
		o.setTableNumber(TableNumber);
		o.setFoodCount(FoodCount);
		o.setList(list);
		o.setStatus(Status);
		ods.Insert(o);

		if (o.getStatus()){
			Bill b(o);
			bl.Insert(b);
		}
	}
	of.close();
}

void SetupBill(){
	bf.open("Bill.txt");
	int BillID, OrderID, TableNumber, FoodCount, Sum;
	string Name, PhoneNum;
	while (!bf.eof()){
		bf.ignore(256, ':');
		bf >> BillID;
		bf.ignore(256, ':');
		bf >> OrderID;
		bf.ignore(256, ':');
		bf.ignore(256, ' ');
		getline(bf, Name);
		bf.ignore(256, ':');
		bf.ignore(256, ' ');
		getline(bf, PhoneNum);
		bf.ignore(256, ':');
		bf >> TableNumber;
		bf.ignore(256, ':');
		bf >> FoodCount;
		FoodsOrdered tmp;
		for (int i = 0; i < FoodCount; i++){
			int FoodID, FoodPrice;
			string FoodName;
			bf >> FoodID;
			bf.ignore(256, '_');
			getline(bf, FoodName, '_');
			bf >> FoodPrice;
			Food f(FoodID, FoodName, FoodPrice);
			tmp.Insert(f);
		}
		bf.ignore(256, ':');
		bf >> Sum;
		Order o;
		o.setID(OrderID);
		o.setCustomerName(Name);
		o.setCustomerPhone(PhoneNum);
		o.setTableNumber(TableNumber);
		o.setConfirmed(1);
		o.setFoodCount(FoodCount);
		o.setList(tmp);
		o.setStatus(1);
		Bill b;
		b.setBillID(BillID);
		b.setOrder(o);
		b.setSumPrice();
		bl.Insert(b);
	}
	bf.close();
}

void Setup(){
	SetupStaff();
	SetupMenu();
	SetupCustomer();
	SetupOrder();
}

void StaffListWrite(){
	sf.open("Staff.txt", ios::out | ios::trunc);
	string str = "So luong nhan vien trong danh sach nay: ";
	char c = '|';
	char c1 = ':';
	char c2 = ' ';
	sf << str;
	sf << sCount << endl; 
	for (Node<Staff>* k = sl.head; k != NULL; k = k->next){
		sf << c << endl;
		sf << "Ten nhan vien: ";
		sf << k->data.getName() << endl;
		sf << "Gioi tinh: ";
		sf << k->data.getSex() << endl;
		sf << "Nam sinh: ";
		sf << k->data.getBirthYear() << endl;
		sf << "So dien thoai: ";
		sf << k->data.getPhoneNumber() << endl;
	}
	sf.close();
}

void MenuWrite(){
	mf.open("Menu.txt", ios::out | ios::trunc);
	string str = "So luong mon an trong danh sach nay: ";
	char c = '|';
	mf << str;
	mf << mCount;
	mf << endl;
	for (Node<Food>* k = m.head; k != NULL; k = k->next){
		mf << k->data.getID();
		mf << c;
		mf << k->data.getName();
		mf << c;
		mf << k->data.getPrice();
		mf << endl;
	}	
	mf.close();
}

void CustomerListWrite(){
	cf.open("Customer.txt", ios::out | ios::trunc);
	string str = "So luong khach hang trong danh sach nay: ";
	char c = '|';
	char c1 = ':';
	char c2 = ' ';
	cf << str;
	cf << cCount << endl; 
	for (Node<Customer>* k = cl.head; k != NULL; k = k->next){
		cf << c << endl;
		cf << "Ten khach hang: ";
		cf << k->data.getName() << endl;
		cf << "So dien thoai: ";
		cf << k->data.getPhoneNumber() << endl;
		cf << "Mat khau: ";
		cf << k->data.getPassWord() << endl;
	}
	cf.close();
}

void OrderWrite(){
	of.open("Order.txt", ios::out | ios::trunc);
	string str = "So luong khach hang trong danh sach nay: ";
	char c = '|';
	char c1 = ':';
	char c2 = ' ';
	of << str;
	of << oCount << endl; 
	for (Node<Order>* k = ods.head; k != NULL; k = k->next){
		of << c << endl;
		of << "Ma don hang: ";
		of << k->data.getID() << endl;
		of << "Khach hang: ";
		of << k->data.getCustomerName() << endl;
		of << "SDT: ";
		of << k->data.getCustomerPhone() << endl;
		of << "Ma ban: ";
		of << k->data.getTableNumber() << endl;
		of << "So luong mon da dat: ";
		of << k->data.getFoodCount() << endl;
		of << "Ma mon" << setw(20) << "Ten mon" << setw(25) << "Gia thanh" << endl << endl;
		FoodsOrdered tmp = k->data.getList();
		for (Node<Food>* f = tmp.head; f != NULL; f = f->next){
			string tmp = "_" + f->data.getName() + '_';
			of << f->data.getID() << setw(30) << tmp << setw(20) << f->data.getPrice() << endl;
		}
		of << "Trang thai: ";
		of << k->data.getStatus() << endl;
	}
	of.close();
}

void BillWrite(){
	bf.open("Bill.txt", ios::out | ios::trunc);
	char c = '|';
	for (Node<Bill>* k = bl.head; k != NULL; k = k->next){
		bf << c << endl;
		bf << "Ma hoa don: ";
		bf << k->data.getBillID() << endl;
		bf << "Ma don hang: ";
		bf << k->data.getOrder().getID() << endl;
		bf << "Khach hang: ";
		bf << k->data.getOrder().getCustomerName() << endl;
		bf << "SDT: ";
		bf << k->data.getOrder().getCustomerPhone() << endl;
		bf << "Ma ban: ";
		bf << k->data.getOrder().getTableNumber() << endl;
		bf << "So mon an da dat: ";
		bf << k->data.getOrder().getFoodCount() << endl;
		
		FoodsOrdered tmp = k->data.getOrder().getList();
		for (Node<Food>* f = tmp.head; f != NULL; f = f->next){
			string tmp = "_" + f->data.getName() + '_';
			bf << f->data.getID() << setw(30) << tmp << setw(20) << f->data.getPrice() << endl;
		}
		bf << "Tong thanh tien: ";
		bf << k->data.getSumPrice() << endl;
	}
	bf.close();
}

void DataWrite(){
	MenuWrite();
	StaffListWrite();
	CustomerListWrite();
	OrderWrite();
	BillWrite();
}

void Intro(){
	system("cls");
    int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                             DO AN CO SO LAP TRINH                                    %c",4,4);
 	printf("\n        %c                       DE TAI: He thong quan li nha hang                              %c",4,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c       Sinh vien thuc hien:                       Giao vien huong dan:                %c",4,4);
 	printf("\n        %c           %c Nguyen Thanh Hieu                       %c Le Thi My Hanh                 %c",4,45,45,4);
 	printf("\n        %c           %c Tran Duc Duy  %60c",4,45,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);
	cout << " Press any key to continue..." << endl;
	_getch();
	system("cls");
}

int Login(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                                  WELCOME TO                                          %c",4,4);
 	printf("\n        %c                       RESTAURANT MANAGEMENT APPLICATION                              %c",4,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                 %d. Dang nhap                        %d. Dang ky                       %c",4,1,2,4);
 	printf("\n        %c                 %d. Quay lai trang truoc  %45c",4,3,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	int num;
	cout << "Nhap so de chon thao tac: "; cin >> num;
	if (num != 1 && num != 2 && num != 3){
		cout << "Khong hop le, nhan Enter de nhap lai" << endl;
		_getch();
		goto Nhaplai;
	}
	system("cls");
	return num;
}

void ThanksScreen(){
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                               Thanks for using                                       %c",4,4);
 	printf("\n        %c                       RESTAURANT MANAGEMENT APPLICATION                              %c",4,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                                See you again!                                        %c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);
	cout << " Press any key to continue..." << endl;
	_getch();
	system("cls");
}

int MainScreen(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
	printf("\n        %c                                  WELCOME TO                                          %c",4,4);
 	printf("\n        %c                       RESTAURANT MANAGEMENT APPLICATION                              %c",4,4);
	printf("\n        %c %86c",4,4);
 	printf("\n        %c                                   Ban la...                                          %c",4,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                 %d. Quan ly                        %d. Nhan vien                       %c",4,1,2,4);
 	printf("\n        %c                 %d. Khach hang                     %d. Thoat ung dung%19c",4,3,0,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	int num;
	cout << "Nhap so de chon thao tac: "; cin >> num;
	if (num != 1 && num != 2 && num != 3 && num != 0){
		cout << "Khong hop le, nhan Enter de nhap lai" << endl;
		_getch();
		goto Nhaplai;
	}
	system("cls");
	return num;
}

void ManagerSignInScreen(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                         Dang nhap vao tai khoan quan ly                              %c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	string Username, Password;
	cout << "Username: "; cin >> Username;
	cout << "Password: "; cin >> Password;

	if (Username != mng.getUsername()){
		cout << "Tai khoan khong ton tai, vui long nhan Enter de dang nhap lai!" << endl;
		_getch();
		goto Nhaplai;
	}
	else if (Username == mng.getUsername() && Password != mng.getPassword()){
		cout << "Sai mat khau, vui long nhan Enter de dang nhap lai!" << endl;
		_getch();
		goto Nhaplai;
	}
	else {
		cout << "Dang nhap thanh cong!" << endl;
		_getch();
	}
	system("cls");
}

void StaffSignInScreen(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                         Dang nhap vao tai khoan nhan vien                            %c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	string phoneNum;
	cout << "Nhap so dien thoai: "; cin >> phoneNum;
	Node<Staff>* nf = sl.FindString(phoneNum);
	if (nf == NULL){
		cout << "Tai khoan khong ton tai, vui long nhan Enter de dang nhap lai!" << endl;
		_getch();
		goto Nhaplai;
	}
	else {
		cout << "Dang nhap thanh cong!" << endl;
		uf = nf;
		_getch();
	}
	system("cls");
}

void CustomerSignUpScreen(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                         Dang ky tai khoan khach hang                                 %c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	string Name, phoneNum, Password, pw;
	cin.ignore();
	cout << "Ho va ten: "; getline(cin, Name);
	cout << "So dien thoai: "; getline(cin, phoneNum);
	Node<Customer>* nc = cl.FindString(phoneNum);
	if (nc != NULL){
		cout << "So dien thoai nay da duoc dang ky, nhan Enter de dang nhap" << endl;
		_getch();
		system("cls");
	}
	else {
		cout << "Mat khau: "; getline(cin, Password);
		cout << "Xac nhan mat khau: "; getline(cin, pw);
		if (Password != pw){
			cout << "Mat khau khong trung khop, vui long nhan Enter de dang ky lai" << endl;
			_getch();
			system("cls");
			goto Nhaplai;
		}
		else {
			cout << "Dang ky thanh cong!" << endl;
			Customer c(Name, phoneNum, Password);
			cl.Insert(c);
			cCount++;
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			return;
		}
	}
}

void CustomerSignInScreen(){
	Nhaplai:
	system("cls");
	int i;
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                         Dang nhap vao tai khoan khach hang                           %c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);

	string phoneNum, Password;
	cout << "So dien thoai: "; cin >> phoneNum;
	cout << "Password: "; cin >> Password;

	Node<Customer>* nc = cl.FindString(phoneNum);

	if (nc == NULL){
		cout << "Tai khoan khong ton tai, vui long nhan Enter de dang nhap lai!" << endl;
		_getch();
		goto Nhaplai;
	}
	else if (phoneNum == nc->data.getPhoneNumber() && Password != nc->data.getPassword()){
		cout << "Sai mat khau, vui long nhan Enter de dang nhap lai!" << endl;
		_getch();
		goto Nhaplai;
	}
	else {
		cout << "Dang nhap thanh cong!" << endl;
		uc = nc;
		_getch();
	}
	system("cls");
}


int main(){

	Setup();

    Intro();
	ManHinhChinh:
	int role = MainScreen();
	switch (role)
	{
	case 1:
		ManagerSignInScreen();
		ManHinhQuanLy:
		cout << " ==========================================" << endl;
		cout << " |  Chon cac thao tac duoi day:           |" << endl;
		cout << " |      1) Xem danh sach nhan vien        |" << endl;
		cout << " |      2) Xem danh sach khach hang       |" << endl;
		cout << " |      3) Xem Menu                       |" << endl;
		cout << " |      4) Xem danh sach don hang         |" << endl;
		cout << " |      5) Xem danh sach hoa don          |" << endl;
		cout << " |      6) Quay lai man hinh chinh        |" << endl;
		cout << " ==========================================" << endl;
		int ManageOption; 
		cout << "Nhap so de chon thao tac: "; cin >> ManageOption;
		if (ManageOption != 1 && ManageOption != 2 && ManageOption != 3 && ManageOption != 4 && ManageOption != 5 && ManageOption != 6){
			cout << "Khong hop le, nhan Enter de nhap lai" << endl;
			_getch();
			system("cls");
			goto ManHinhQuanLy;
		}
		system("cls");
		switch (ManageOption)
		{
		case 1:
			sl.Display();
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			ThaoTacVoiNhanVien:
			cout << " ==========================================" << endl;
			cout << " |  Chon cac thao tac duoi day:           |" << endl;
			cout << " |      1) Them nhan vien                 |" << endl;
			cout << " |      2) Xoa nhan vien                  |" << endl;
			cout << " |      3) Quay lai trang truoc           |" << endl;
			cout << " ==========================================" << endl;
			int choice;
			cout << "Nhap so de chon thao tac: "; cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3){
				cout << "Khong hop le, nhan Enter de nhap lai" << endl;
				_getch();
				system("cls");
				goto ThaoTacVoiNhanVien;
			}
			system("cls");
			if (choice == 1){
				cout << "Nhap thong tin nhan vien" << endl;
				cout << "Ten nhan vien: ";
				string name;
				cin.ignore();
				getline(cin, name);
				
				cout << "Gioi tinh (1 la nam, 0 la nu): ";
				bool sex; cin >> sex;
				cout << "Nam sinh: ";
				int year; cin >> year;
				cout << "So dien thoai: ";
				string phoneNum; cin >> phoneNum;
				Staff s(name, sex, year, phoneNum);
				sl.Insert(s);
				cout << "Them nhan vien thanh cong!" << endl;
				sCount++;
				cout << "Nhan Enter de quay lai trang truoc" << endl;_getch();
				system("cls");
				goto ThaoTacVoiNhanVien;
			}
			if (choice == 2){
				cout << "Nhap so dien thoai cua nhan vien muon xoa: ";
				string phoneNum; cin >> phoneNum;
				Node<Staff>* ns = sl.FindString(phoneNum);
				if (ns == NULL){
					cout << "Khong co nhan vien nay trong danh sach." << endl;
				}
				else {
					sl.Delete(ns->data);
					cout << "Xoa thanh cong!" << endl;
					sCount--;
				}
				cout << "Nhan Enter de quay lai trang truoc" << endl;_getch();
				system("cls");
				goto ThaoTacVoiNhanVien;
			}
			if (choice == 3){
				goto ManHinhQuanLy;
			}
			break;
		case 2:
			cl.Display();
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			goto ManHinhQuanLy;
			break;
		case 3:
			m.Display();
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			ThaoTacVoiMenu:
			cout << " ==========================================" << endl;
			cout << " |  Chon cac thao tac duoi day:           |" << endl;
			cout << " |      1) Them mon an                    |" << endl;
			cout << " |      2) Xoa mon an                     |" << endl;
			cout << " |      3) Chinh sua gia mon an           |" << endl;
			cout << " |      4) Quay lai trang truoc           |" << endl;
			cout << " ==========================================" << endl;
			int fchoice;
			cout << "Nhap so de chon thao tac: "; cin >> fchoice;
			if (fchoice != 1 && fchoice != 2 && fchoice != 3 && fchoice != 4){
				cout << "Khong hop le, nhan Enter de nhap lai" << endl;
				_getch();
				system("cls");
				goto ThaoTacVoiMenu;
			}
			system("cls");
			if (fchoice == 1){
				ThongTinMonAn:
				cout << "Nhap thong tin mon an" << endl;
				cout << "Ma mon an: "; int ID; cin >> ID;
				Node<Food>* nf = m.Find(ID);
				if (nf != NULL){
					cout << "Ma mon an bi trung, nhan Enter de nhap so khac" << endl;
					_getch();
					system("cls");
					goto ThongTinMonAn;
				}
				cout << "Ten mon an: "; string Name; cin.ignore(); getline(cin, Name);
				cout << "Gia mon an: "; int Price; cin >> Price;
				Food f(ID, Name, Price);
				m.Insert(f);
				mCount++;
				m.Sort();
				cout << "Them mon an thanh cong!" << endl;
				cout << "Nhan Enter de quay lai trang truoc" << endl;
				_getch();
				system("cls");
				goto ThaoTacVoiMenu;
			}
			if (fchoice == 2){
				cout << "Nhap ma cua mon an muon xoa: ";
				int ID; cin >> ID;
				Node<Food>* nf = m.Find(ID);
				if (nf == NULL){
					cout << "Khong co mon an nay trong menu." << endl;
				}
				else {
					m.Delete(nf->data);
					cout << "Xoa thanh cong!" << endl;
					mCount--;
				}
				cout << "Nhan Enter de quay lai trang truoc" << endl;_getch();
				system("cls");
				goto ThaoTacVoiMenu;
			}
			if (fchoice == 3){
				mng.UpdateMenu(m);
				cout << "Nhan Enter de quay lai trang truoc" << endl;_getch();
				system("cls");
				goto ThaoTacVoiMenu;
			}
			if (fchoice == 4){
				goto ManHinhQuanLy;
			}
			break;
		case 4:
			ods.Display();
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			goto ManHinhQuanLy;
			break;
		case 5:
			bl.Display();
			cout << "Nhan Enter de tiep tuc" << endl;
			_getch();
			system("cls");
			goto ManHinhQuanLy;
			break;
		case 6:
			goto ManHinhChinh;
		default:
			break;
		}
		break;
	case 2:
		StaffSignInScreen();
		ManHinhNhanVien:
		cout << " ==========================================" << endl;
		cout << " |  Chon cac thao tac duoi day:           |" << endl;
		cout << " |      1) Xem danh sach don hang         |" << endl;
		cout << " |      2) Quay lai man hinh chinh        |" << endl;
		cout << " ==========================================" << endl;
		int StaffOption; 
		cout << "Nhap so de chon thao tac: "; cin >> StaffOption;
		if (StaffOption != 1 && StaffOption != 2){
			cout << "Khong hop le, nhan Enter de nhap lai" << endl;
			_getch();
			system("cls");
			goto ManHinhNhanVien;
		}
		system("cls");
		switch (StaffOption){
			case 1:
				ThaoTacVoiOrders:
				ods.Display();
				cout << endl << endl;
				cout << " ==========================================" << endl;
				cout << " |  Chon cac thao tac duoi day:           |" << endl;
				cout << " |      1) Nhan don hang                  |" << endl;
				cout << " |      2) Quay lai trang truoc           |" << endl;
				cout << " ==========================================" << endl;
				int StaffChoice; 
				cout << "Nhap so de chon thao tac: "; cin >> StaffChoice;
				if (StaffChoice != 1 && StaffChoice != 2){
					cout << "Khong hop le, nhan Enter de nhap lai" << endl;
					_getch();
					system("cls");
					goto ThaoTacVoiOrders;
				}
				if (StaffChoice == 1){
					cout << "Chon ma don hang muon nhan: "; int ID; cin >> ID;
					uf->data.RecieveOrder(ods, ID);
					cout << endl << "Nhan Enter de tiep tuc" << endl;
					_getch();
					system("cls");
					goto ThaoTacVoiOrders;
				}
				if (StaffChoice == 2){
					system("cls");
					goto ManHinhNhanVien;
				}
				break;
			case 2:
				goto ManHinhChinh;
		}
		break;
	case 3:
		ManHinhLogin:
		switch (Login())
		{
		case 1:
			CustomerSignInScreen();
			ManHinhKhachHang:
			cout << " ==========================================" << endl;
			cout << " |  Chon cac thao tac duoi day:           |" << endl;
			cout << " |      1) Xem menu                       |" << endl;
			cout << " |      2) Xem danh sach don hang         |" << endl;
			cout << " |      3) Order                          |" << endl;
			cout << " |      4) Xem lich su giao dich          |" << endl;
			cout << " |      5) Quay lai trang truoc           |" << endl;
			cout << " ==========================================" << endl;
			int CustomerOption; 
			cout << "Nhap so de chon thao tac: "; cin >> CustomerOption;
			if (CustomerOption != 1 && CustomerOption != 2 && CustomerOption != 3 && CustomerOption != 4 && CustomerOption != 5){
				cout << "Khong hop le, nhan Enter de nhap lai" << endl;
				_getch();
				system("cls");
				goto ManHinhKhachHang;
			}
			system("cls");
			switch (CustomerOption){
				case 1:
					m.Display();
					cout << "Nhan Enter de tiep tuc" << endl;
					_getch();
					system("cls");
					goto ManHinhKhachHang;
				case 2:
					uc->data.ViewOrder(ods);
					cout << "Nhan Enter de tiep tuc" << endl;
					_getch();
					system("cls");
					goto ManHinhKhachHang;
				case 3:
					uc->data.Ordering(m, ods);
					oCount -= 1;
					cout << "Nhan Enter de tiep tuc" << endl;
					_getch();
					system("cls");
					goto ManHinhKhachHang;
				case 4:
					uc->data.ViewTransactionHistory(ods, bl);
					cout << "Nhan Enter de tiep tuc" << endl;
					_getch();
					system("cls");
					goto ManHinhKhachHang;
				case 5:
					goto ManHinhLogin;
			}
			break;
		case 2:
			CustomerSignUpScreen();
			goto ManHinhLogin;
			break;
		case 3:
			goto ManHinhChinh;
			
		default:
			break;
		}
		break; 
	case 0:
		ThanksScreen();
		DataWrite();
		break;
	default:
		break;
	}
}
