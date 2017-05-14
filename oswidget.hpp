#ifndef OSWIDGET_HPP_INCLUDED
#define OSWIDGET_HPP_INCLUDED

#include "graphics.hpp"



class Widget{
protected:
    int _x, _y, _sx, _sy;

public:
    Widget(int x, int y, int sx, int sy);
    virtual void kirajzol() const;
    virtual void handle(genv::event ev,int &lepesszam) ;
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void Setsquare();



};

#endif // OSWIDGET_HPP_INCLUDED
