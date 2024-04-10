#include"Teacher.h"
#include<vector>

class Department{
    vector<Teacher *> teacher;
    string nameDep;
    public:
        Department(string = "");
        ~Department();
        void addTeacher(Teacher*);
        friend ostream& operator<<(ostream&, const Department&);
};