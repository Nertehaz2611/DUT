#pragma once
#include<iostream>
#include<vector>
#include"Patient.h"
#include"Doctor.h"

using namespace std;

class BenhAn {
    private:
        int IDBA;
        Patient* p;
        Doctor* d;
        public:
            BenhAn(int, Patient*, Doctor*);
            ~BenhAn();
            void setIDBA(int);
            int getIDBA();
            Patient* getPatient();
            Doctor* getDoctor();
};