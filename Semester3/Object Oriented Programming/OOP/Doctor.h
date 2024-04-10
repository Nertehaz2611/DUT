#pragma once
#include"BenhAn.h"

class Doctor {
    int IDDoctor;
    string nameD;
    vector<BenhAn*> ListB;
    public:
        Doctor(int, string = NULL);
        ~Doctor();
        void setIDDoctor(int);
        int getIDDoctor() const;
        void setnameD(string);
        string getnameD() const;
        void addBenhAn(BenhAn*);
};