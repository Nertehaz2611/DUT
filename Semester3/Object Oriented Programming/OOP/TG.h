#include "Point.h"

class TG {
    private:
        Point A, B, C;
    public:
        TG(const Point&, const Point&, const Point&);
        TG(int = 1, int = 1, int = 2, int = 2, int = 3, int = 3);
        ~TG();
        void Show();
};

