#include "statikstring.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

statikstring::statikstring(int x, int y, int sx, int sy , string s_  )
    : Widget(x,y,sx,sy)
{
s = s_;
_sx= gout.twidth(s)+10;
}


void statikstring::kirajzol() const{

    gout<<move_to(_x , _y)<<color(255,255,255)<<box(_sx , _sy);
    gout<<move_to(_x+2 , _y+2)<<color(0,0,0)<<box(_sx-4, _sy-4);
    gout<<move_to(_x+3,_y+_sy/2+gout.cascent()/2)<<color(255,255,255)<<text(s);
}
