#include "oswidget.hpp"
#include "graphics.hpp"



Widget::Widget(int x, int y, int sx, int sy)
{

_x=x;
_y=y;
_sx=sx;
_sy=sy;

}

void Widget::kirajzol() const {}
void Widget::handle(genv::event ev)  {}
bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
}


