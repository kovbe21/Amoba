#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "window.hpp"
#include "graphics.hpp"
#include "oswidget.hpp"



class button : public Widget{
protected:
    std::string _s;
    std::string _azonosito;
    window * _parent;
public:
    button(window * parent , int x, int y, int sx, int sy , std::string s ,std:: string azonosito );
    virtual void kirajzol() const;
    virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
