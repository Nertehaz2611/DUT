#include<iostream>
using namespace std;

class SV {
    protected:
        string MSSV;
        string Name;
        bool Gender;
        double DTB;
    public:
        SV(string = "", string = "", bool = true, double = 0.0);
        virtual ~SV();
        friend ostream& operator<<(ostream&, const SV&);
        virtual void Show();
        const SV& operator=(const SV&);
        virtual bool operator==(const SV&);
};