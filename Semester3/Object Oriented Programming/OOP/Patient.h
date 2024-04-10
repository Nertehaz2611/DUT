#pragma once
#include"BenhAn.h"

class Patient {
    int IDPatient;
    string nameP;
    vector<BenhAn*> ListB;
    public:
        Patient(int, string = NULL);
        ~Patient();
        void setIDPatient(int);
        int getIDPatient() const;
        void setnameP(string);
        string getnameP() const;
        void addBenhAn(BenhAn*);
};
