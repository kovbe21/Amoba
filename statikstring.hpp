#ifndef STATIKSTRING_HPP_INCLUDED
#define STATIKSTRING_HPP_INCLUDED

#include "graphics.hpp"
#include "oswidget.hpp"
#include "window.hpp"

class statikstring : public Widget{
protected:
    std::string _s;
    std::string _azonosito;
    window * _parent;

public:
    statikstring(window * parent , int x, int y, int sx, int sy , std::string s, std::string azonosito );
    virtual void kirajzol() const;
    virtual void unidraw(int lepesszam, int kinyert,int XX,int YY);

};


#endif // STATIKSTRING_HPP_INCLUDED
