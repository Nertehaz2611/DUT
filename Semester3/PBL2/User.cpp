#include"User.h"

User::User(){
}

User::~User(){
}

void User::setUsername(string u){
    this->Username = u;
}

string User::getUsername(){
    return this->Username;
}

void User::setPassword(string p){
    this->Password = p;
}

string User::getPassword(){
    return this->Password;
}