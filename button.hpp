#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "window.hpp"
#include "graphics.hpp"
#include "oswidget.hpp"

using namespace std;


class button : public Widget{
protected:
    string _s;
    string _azonosito;
    window * _parent;
public:
    button(window * parent , int x, int y, int sx, int sy , string s , string azonosito );
    virtual void kirajzol() const;
    virtual void handle(genv::event ev,int &lepesszam);
};

#endif // BUTTON_HPP_INCLUDED
