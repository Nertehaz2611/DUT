#include"LTT.h"
class MyClass : public LTT {
    private:
        string sms;
    public:
        MyClass(string = "");
        ~MyClass();
        void MC();
        //A() -> vỉrtual void
        //B()
        void A();
};