#include"Map.h"

template<typename T, typename U, template<typename V> class C>
Map<T, U, C>::Map(){
    cout << "Map" << endl;
}

template<typename T, typename U, template<typename V> class C>
Map<T, U, C>::Map(C<T> t, C<U> u) : key(t), value(u){
    cout << "Dung Map co tham so" << endl;
}

template<typename T, typename U, template<typename V> class C>
Map<T, U, C>::~Map(){
}

template<typename T, typename U, template<typename V> class C>
ostream& operator<<(ostream& o, const Map<T, U, C>& m){
    o << "cout << Map" << endl;
    return o;
}