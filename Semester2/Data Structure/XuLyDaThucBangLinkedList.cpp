#include<bits/stdc++.h>
using namespace std;

#define PrHs(x, y) if (abs(x) != 1 || (abs(x) == 1 && y == 0)) cout << abs(x);
#define Pr(x) if (x == 1) cout << "x"; else if (x != 1 && x != 0) cout << "x^" << x;

struct donThuc{
	double heSo;
	int soMu;
};

struct Node{
	donThuc Info;
	Node *pNext;
};

struct daThuc{
	Node *pHead;
};

void daThucInit(daThuc &tmp){
	tmp.pHead = NULL;
}

//Ham them da thuc vao list
void Add(daThuc &L, donThuc t){
	Node *tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->Info = t;
	//Them don thuc bac lon nhat vao dau da thuc
	if (L.pHead == NULL || L.pHead->Info.soMu < t.soMu){
		tmp->pNext = L.pHead;
		L.pHead = tmp;
	} 
	//Neu don thuc them vao co bac nho hon so bac cua don thuc dau da thuc thi lam tiep
	else {
		Node *cur = L.pHead;
	//Them don thuc vua tao vao truoc so hang co so mu lon hon no
		//Tim vi tri truoc vi tri cua don thuc dau tien co bac nho hon bac cua don thuc chuan bi them vao
		while (cur->pNext != NULL && cur->pNext->Info.soMu >= t.soMu){
			cur = cur->pNext;
		}
		//Neu don thuc co vi tri vua tim duoc co bac bang voi bac cua da thuc chuan bi them vao
		//thi chi can cong he so cua don thuc moi vao vi tri da tim duoc
		if (cur->Info.soMu == t.soMu){
			cur->Info.heSo += t.heSo;
		}
		//Neu don thuc co vi tri vua tim duoc co bac lon hon bac cua da thuc chuan bi thi vao thi:
		else {
			tmp->pNext = cur->pNext; //Dat don thuc moi dung truoc don thuc ngay sau don thuc co vi tri da tim
			cur->pNext = tmp; //Dat don thuc co vi tri da tim dung truoc don thuc moi
		}
	}
}

//Ham nhap da thuc
void nhapDaThuc(daThuc &tmp){
	donThuc t;
	do {
		cout << "\nHe so: "; cin >> t.heSo;
		cout << "So mu: "; cin >> t.soMu;
		Add(tmp, t);
	} while (t.soMu != 0);
}


//Ham xuat da thuc
void xuatDaThuc(daThuc L){
	Node *cur = L.pHead;
	if (cur != NULL){
		while (cur->Info.heSo == 0 && cur->pNext != NULL) cur = cur->pNext;
		if (cur->Info.heSo < 0) cout << " - ";
		PrHs(cur->Info.heSo, cur->Info.soMu);
		Pr(cur->Info.soMu);
		cur = cur->pNext;
	}
	while (cur != NULL){
		if (cur->Info.heSo != 0){
			if (cur->Info.heSo > 0) cout << " + ";
			else cout << " - ";
			PrHs(cur->Info.heSo, cur->Info.soMu);
			Pr(cur->Info.soMu);
		} 
		cur = cur->pNext;
	}
	cout << "\n\n";
}

//Ham cong hai da thuc
daThuc congHaiDaThuc(daThuc a, daThuc b){
	daThuc tmp;
	daThucInit(tmp);
	Node *cur = a.pHead;
	while (cur != NULL){
		Add(tmp, cur->Info);
		cur = cur->pNext;
	}
	cur = b.pHead;
	while (cur != NULL){
		Add(tmp, cur->Info);
		cur = cur->pNext;
	}
	return tmp;
}

//Ham nhan hai da thuc
daThuc nhanHaiDaThuc(daThuc a, daThuc b){
	daThuc tmp;
	daThucInit(tmp);
	Node *cur1 = a.pHead;
	Node *cur2 = b.pHead;
	donThuc t;
	while (cur1 != NULL){
		while (cur2 != NULL){
			t.heSo = cur1->Info.heSo * cur2->Info.heSo;
			t.soMu = cur1->Info.soMu + cur2->Info.soMu;
			Add(tmp, t);
			cur2 = cur2->pNext;
		}
		cur2 = b.pHead;
		cur1 = cur1->pNext;
	}
	return tmp;
}

int main(){
	daThuc A, B, C, D;
	daThucInit(A);
	cout << "Nhap da thuc A: ";
	nhapDaThuc(A);
	cout << "\nDa thuc A: ";
	xuatDaThuc(A);
	daThucInit(B);
	cout << "Nhap da thuc B: ";
	nhapDaThuc(B);
	cout << "\nDa thuc B: ";
	xuatDaThuc(B);
	C = congHaiDaThuc(A, B);
	D = nhanHaiDaThuc(A, B);
	cout << "\nA + B = ";
	xuatDaThuc(C);
	cout << "\nA x B = ";
	xuatDaThuc(D);
	return 0;
}
