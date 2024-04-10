#include<iostream>

using namespace std;

template<typename T, typename U, template<typename V> class C>
class Map {
    private:
        C<T> key;
        C<U> value; 
    public:
        Map();
        Map(C<T>, C<U>);
        ~Map();
        template<typename T1, typename U1, template<typename V1> class C1>
        friend ostream& operator<<(ostream&, const Map<T1, U1, C1>&);
};