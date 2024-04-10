#include"Department.h"

Department::Department(string name) : nameDep(name) {

}

Department::~Department(){
    this->teacher.clear();
}

void Department::addTeacher(Teacher* t){
    this->teacher.push_back(t);
}

ostream& operator<<(ostream& o, const Department& d){
    o << d.nameDep << ": " << endl;
    for (int i = 0; i < d.teacher.size(); i++){
        cout << *d.teacher[i];
    } 
    o << endl;
    return o;
}