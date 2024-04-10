#include"QLSV.h"

QLSV::QLSV(){
    this->n = 0;
    this->p = NULL;
}

QLSV::~QLSV(){
    delete[] this->p;
}

ostream& operator<<(ostream& o, const QLSV& ql){
    for (int i = 0; i < ql.n; i++){
        o << *(ql.p + i);
    }
    return o;
}

SV& QLSV::operator[](const int& i){
    static SV NGU;
    return (i >= 0 && i < this-> n)? *(this->p + i) : NGU;
}

void QLSV::Add(const SV& s){
    if (this->n == 0){
        this->p = new SV[this->n + 1];
        *(this->p + this->n) = s;
    }
    else{
        SV* tmp = new SV[this->n];
        for (int i = 0; i < this->n; i++){
            tmp[i] = (*this)[i];
        }
        delete[] this->p;
        this->p = new SV[this->n + 1];
        for (int i = 0; i < this->n; i++){
            *(this->p + i) = tmp[i];
        }
        *(this->p + this->n) = s;
        delete[] tmp;
    }
    this->n++;
}

void QLSV::Insert(const SV& s, const int& index){
    if (this->n == 0){
        this->p = new SV[this->n + 1];
        *(this->p + this->n) = s;
    }
    else{
        SV* tmp = new SV[this->n+1];
        for (int i = 0; i < this->n+1; i++){
            if (i < index){
                tmp[i] = (*this)[i];
            }
            else if (i == index){
                tmp[i] = s;
            }
            else {
                tmp[i] = (*this)[i-1];
            }
        }
        delete[] this->p;
        this->p = new SV[this->n + 1];
        for (int i = 0; i < this->n + 1; i++){
            *(this->p + i) = tmp[i];
        }
        delete[] tmp;
    }
    this->n++;
}

int QLSV::IndexOf(const SV& s){
    int index = -1;
    for (int i = 0; i < this->n; i++){
        if ((*this)[i] == s){
            index = i;
            break;
        }
    }
    return index;
}

void QLSV::RemoveAt(const int& index){
    if (index >= 0 && index < this->n){
        if (this->n == 1){
            this->p == NULL;
        }
        else{
            SV* tmp = new SV[this->n-1];
            for (int i = 0; i < this->n; i++){
                if (i < index){
                    tmp[i] = (*this)[i];
                }
                else if (i == index){
                    continue;
                }
                else if (i > index){
                    tmp[i-1] = (*this)[i];
                }
            }
            delete[] p;
            this->p = new SV[this->n-1];
            for (int i = 0; i < this->n-1; i++){
                (*this)[i] = tmp[i];
            }
            delete[] tmp;
        }
        this->n++;
    }
}

void QLSV::Remove(const SV& s){
    if (IndexOf(s) >= 0){
        RemoveAt(IndexOf(s));
    }
}

void QLSV::Update(const int& m){
    for (int i = 0; i < this->n; i++){
        if ((*this)[i].getMSSV() == m){
            //goi toan tu nhap de update thong tin
            //ko thay doi gia tri MSSV
        }
    }
}
