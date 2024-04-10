#pragma once
#include<iostream>

using namespace std;

class User{
    protected:
        string Username;
        string Password;
    public:
        User();
        virtual ~User();
        void setUsername(string);
        string getUsername();
        void setPassword(string);
        string getPassword();
};