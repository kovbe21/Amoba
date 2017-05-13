
#include "graphics.hpp"
#include "editor.hpp"

using namespace genv;
using namespace std;

editor::editor(int x, int y, int sx, int sy , string s  )
    : Widget(x,y,sx,sy)
{
_s = s;
_sx= gout.twidth(s)+10;
}


void editor::kirajzol() const{

    gout<<move_to(_x , _y)<<color(0,0,0)<<box(_sx , _sy);
    gout<<move_to(_x+2 , _y+2)<<color(255,255,255)<<box(_sx-4, _sy-4);
    gout<<move_to(_x+3,_sy/2+gout.cascent()/2)<<color(0,0,0)<<text(_s)<<text('|');
}

void editor::handle(event ev, int &lepesszam)
{
    if (ev.type == ev_key && ev.keycode!=key_backspace && ev.keycode>0 && gout.twidth(_s)+10<_sx && isprint(ev.keycode)) {
            _s+=ev.keycode;
    }

    if(ev.type == ev_key && ev.keycode==key_backspace){
            _s=_s.substr(0,_s.length()-1);
    }

}
