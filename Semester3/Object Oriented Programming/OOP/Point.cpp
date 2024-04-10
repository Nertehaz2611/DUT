#include<iostream>
#include "Point.h"

using namespace std;

Point::Point(){
    cout << "Point" << endl;
}

void Point::Show(){
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point(int x, int y)
{
    this->xVal = x;
    this->yVal = y;
}

// Point operator+(const Point& p1, const Point& p2){
//     Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
//     return p;
// }

// Point Point::operator-(const Point& q){
//     Point p(this->xVal - q.xVal, this->yVal - q.yVal);
//     return p;
// }

Point::~Point(){
    //cout << "Huy Point" << endl;
}

ostream& operator<<(ostream& o, const Point& p){
    o << p.xVal << ", " << p.yVal << endl;
    return o;
}

// ostream& operator<<(const Point& p, ostream& o){
//     o << p.xVal << ", " << p.yVal << endl;
//     return o;
// }

istream& operator>>(istream& i, Point& p){
    cout << "xVal = ";
    i >> p.xVal;
    cout << "yVal = ";
    i >> p.yVal;
    return i;
}

// Point operator+(const Point& p, const int& t){
//     Point p1(p.xVal + t, p.yVal + t);
//     return p1;
// }

// Point::Point(int t):
//     xVal(t), yVal(t) {   
// }

// const Point& Point::operator=(const Point& p){
//     if (this != &p) {
//         this->xVal = p.xVal;
//         this->yVal = p.yVal;
//     }
//     return *this;
// }

// Point::Point(const Point& p):
//     xVal(p.xVal), yVal(p.yVal) {
// }

// Point Point::operator++(){
//     this->xVal++;
//     this->yVal++;
//     return *this;
// }

// const Point Point::operator++(int){
//     Point p(*this);
//     this->xVal++;
//     this->yVal++;
//     return p;
// }

// bool Point::operator==(const Point& p){
//     return (this->xVal == p.xVal && this->yVal == p.yVal);
// }