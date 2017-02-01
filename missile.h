#ifndef MISSILE
#define MISSILE

class missile{
    private:
        int x;
        int y;
        int height;
        int width;
    public:
        missile(int x, int y, int width, int height);
        int get_x();
        int get_y();
        void move_up();
};

#endif // MISSILE

