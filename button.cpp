
#include "graphics.hpp"
#include "button.hpp"

using namespace genv;
using namespace std;

button::button(window * parent,int x, int y, int sx, int sy , string s , string azonosito )
    : Widget(x,y,sx,sy)
{
_parent=parent;
_azonosito=azonosito;
_s = s;
_sx= gout.twidth(s)+10;
}


void button::kirajzol() const{

    gout<<move_to(_x , _y)<<color(255,255,255)<<box(_sx , _sy);
    gout<<move_to(_x+2 , _y+2)<<color(0,0,0)<<box(_sx-4, _sy-4);
    gout<<move_to(_x+3,_y+_sy/2+gout.cascent()/2)<<color(255,255,255)<<text(_s);
}

void button::handle(event ev, int &lepesszam)
{
    _parent->esemeny(_azonosito);


}
