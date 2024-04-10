#include "TG.h"

TG::~TG(){
    
}

TG::TG(const Point& pa, const Point& pb, const Point& pc){
    this->A = pa;
    this->B = pb;
    this->C = pc;
}

TG::TG(int xa, int ya, int xb, int yb, int xc, int yc)
    : A(xa, ya), B(xb, yb), C(xc, yc)
{

}

void TG::Show(){
    A.Show();
    B.Show();
    C.Show();
}