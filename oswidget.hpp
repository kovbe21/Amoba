#ifndef OSWIDGET_HPP_INCLUDED
#define OSWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <iostream>
using namespace std;

using namespace std;

class Widget{
protected:
    int _x, _y, _sx, _sy;

public:
    Widget(int x, int y, int sx, int sy);
    virtual void kirajzol() const;
    virtual void handle(genv::event ev) ;
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void Setsquare();



};

#endif // OSWIDGET_HPP_INCLUDED
