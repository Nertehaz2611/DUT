#include<iostream>

using namespace std;

template<typename T>
class Vector{
    public:
        T *data;
        int size;
    public:
        Vector();
        Vector(T);
        ~Vector();
        template<typename K> 
        friend ostream& operator<<(ostream&, const Vector<K>&);
        // friend istream& operator>>(istream&, Vector&);
        void Show();
        T& operator[](const int&);
        // Vector(const Vector&);
        // const Vector& operator=(const Vector&);
};