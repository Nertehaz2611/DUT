class Number {
    private:
        double d;
    public:
        Number(double = 2.4);
        ~Number();
        operator int();
        operator double();
};