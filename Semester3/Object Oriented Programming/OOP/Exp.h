#include<iostream>
using namespace std;
class  Exp
{
protected:
    string sms;
public:
    Exp(string = "");
    ~Exp();
    friend ostream& operator<<(ostream&, const Exp&);
};

