#include<iostream>
using namespace std;

class Point{
    protected:
        int xVal;
        int yVal;
    public:
        Point();
        Point(int = 1, int = 1);
        ~Point();
        virtual void Show();
        // friend Point operator+(const Point&, const Point&);
        // friend Point operator+(const Point&, const int&);
        // Point operator-(const Point&);
        friend ostream& operator<<(ostream&, const Point&);
        // friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);
        // Point(int);
        // const Point& operator=(const Point&);
        // Point(const Point&);
        // Point operator++();
        // const Point operator++(int);
        // bool operator==(const Point& p);

};