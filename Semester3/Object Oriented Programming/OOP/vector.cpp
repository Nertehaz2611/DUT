#include "vector.h"

template<typename T>
Vector<T>::Vector(){
    cout << "Dung Vector" << endl;
}

template<typename T>
Vector<T>::Vector(T t){
    cout << "Dung Vector co tham so" << endl;
}

template<typename T>
T &Vector<T>::operator[](const int &index)
{
    if (index >= 0 && index < this->size)
    return *(this->data + index);
}

// template<typename T>
// Vector<T>::Vector(int s) : size(s)
// {
//     this->data = new T[this->size];
//     for (int i = 0; i < this->size; i++){
//         cin >> *(this->data + i);
//     }
// }

template<typename T>
Vector<T>::~Vector()
{
    delete[] this->data;
}

template<typename T>
ostream &operator<<(ostream &o, const Vector<T> &v)
{
    // for (int i = 0; i < v.size; i++)
    // {
    //     o << v.data[i] << " ";
    // }
    // o << endl;
    o << "cout << Vector" << endl;
    return o;
}

// istream &operator>>(istream &i, Vector &v)
// {
//     for (int j = 0; j < v.size; j++)
//     {
//         cout << "v[" << j << "] = ";
//         i >> v.data[j];
//     }
//     return i;
// }

template<typename T>
void Vector<T>::Show()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << *(this->data + i) << " ";
    }
    cout << endl;
}

// Vector::Vector(const Vector &v) : size(v.size)
// {
//     this->data = new int[this->size];
//     for (int i = 0; i < this->size; i++)
//     {
//         (*this)[i] = *(v.data + i);
//     }
// }

// const Vector &Vector::operator=(const Vector &v)
// {
//     if (this != &v)
//     {
//         this->data = NULL;
//         this->size = v.size;
//         this->data = new int[this->size];
//         for (int i = 0; i < this->size; i++)
//         {
//             (*this)[i] = *(v.data + i);
//         }
//     }
//     return *this;
// }