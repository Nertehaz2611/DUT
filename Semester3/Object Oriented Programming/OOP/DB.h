#pragma once
#include"BenhAn.h"

class DB {
    static DB Instance;
    string name;
    vector<Doctor*> doctor;
    vector<Patient*> patient;
    vector<BenhAn*> benhan;
    DB(string);
};