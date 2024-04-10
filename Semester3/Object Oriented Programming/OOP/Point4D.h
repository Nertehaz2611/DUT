#include"Point3D.h"

class Point4D : public Point3D {
    private:
        int tVal;
    public:
        Point4D(int = 1, int = 1, int = 1, int = 1);
        ~Point4D();
        void Show4D();
        void Show();
};