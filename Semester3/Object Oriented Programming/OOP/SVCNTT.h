#include"SV.h"

class SVCNTT : public SV {
    private:
        string LT;
    public:
        SVCNTT(string = "", string = "", bool = true, double = 0.0, string = "GIOI");
        virtual ~SVCNTT();
        void LapTrinh();
        void Show();
        friend ostream& operator<<(ostream&, const SVCNTT&);
        const SVCNTT& operator=(const SVCNTT&);
        bool operator==(const SVCNTT&);
};