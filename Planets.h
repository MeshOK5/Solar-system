#include <math.h>
#pragma once

class Planets
{
    private:
        int x0=0,y0=0,rad=0,x=0,y=0,vector=1;

    public:
        double angle = 0;
        bool isPressed = false;
        Planets(int startx, int starty, int r, int vec);
        Planets(int r, int vec);
        int getx();
        int gety();
        void move(double s);
        void setposition(int startx, int starty);
};

Planets::Planets(int startx, int starty, int r, int vec)
{
    if (vec > 1) vec = 1;
    if (vec < -1 || vec == 0) vec = -1;

    vector = vec;
    x0 = startx;
    y0 = starty;
    rad = r;
}

Planets::Planets(int r, int vec)
{
    if (vec > 1) vec = 1;
    if (vec < -1 || vec == 0) vec = -1;

    vector = vec;
    rad = r;
}

int Planets::getx()
{
    return x;
}

int Planets::gety()
{
    return y;
}

void Planets::move(double s)
{
    angle += s;
    if (angle > 360) angle = 0;

    x = x0 + round(rad * cos(angle * M_PI / 180));
    y = y0 + round(rad * sin(angle * M_PI / 180)) * vector;

}

void Planets::setposition(int startx, int starty)
{
    x0 = startx;
    y0 = starty;
}
