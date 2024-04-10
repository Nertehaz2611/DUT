#include<iostream>
using namespace std;

int main(){
	enum Color{
		RED = 1,
		BLUE = 2, 
		GREEN = 3,
		YELLOW = 4
	};
	Color c = GREEN;
	cout << c;
	return 0;
}

//Neu gan bien bang mot hang chua duoc gan gia tri, thi bien se bang hang truoc do + 1
//Neu hang dau tien chua duoc gan gia tri, thi bien duoc gan hang do co gia tri bang 0
