#include "square.hpp"
#include "graphics.hpp"
using namespace genv;

Square::Square(int x, int y, int sx, int sy)
    :Widget(x,y,sx,sy)
{
    _allapot=0;
}

void Square::kirajzol() const
{
    gout<< move_to(_x, _y) << color(255,255,255) << box(_sx, _sy)
        << move_to(_x+1, _y+1) << color(0,0,0) << box(_sx-2, _sy-2);
    if (_allapot==1){
        gout << color(255,0,0);
    }
    if (_allapot==2){
        gout<<color(0,0,255);
    }
    gout << move_to(_x+5, _y+5) << box(_sx-10, _sy-10);
}



int Square::GetAllapot() const{
    return _allapot;
}

void Square::Setsquare(int all){
_allapot=all;
}
