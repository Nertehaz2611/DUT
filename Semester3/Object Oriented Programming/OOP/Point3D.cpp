#include"Point3D.h"

Point3D::Point3D(int x, int y, int z) : Point(x, y){
    this->xVal = x;
    this->yVal = y;
    this->zVal = z;
    cout << "Dung Point3D" << endl;
}

Point3D::~Point3D(){
    cout << "Huy Point3D" << endl;
}

void Point3D::Show3D(){
    cout << this->xVal << " " << this->yVal << " " << this->zVal << endl;
}

void Point3D::Show(){
    Point::Show();
    cout << this->zVal << endl;
}