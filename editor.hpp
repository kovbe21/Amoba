#ifndef EDITOR_HPP_INCLUDED
#define EDITOR_HPP_INCLUDED
#include "window.hpp"
#include "graphics.hpp"
#include "oswidget.hpp"

using namespace std;


class editor : public Widget{
protected:
    string _s;
    string _azonosito;
    window * _parent;
public:
    editor(window * parent , int x, int y, int sx, int sy , string s , string azonosito );
    virtual void kirajzol() const;
    virtual void handle(genv::event ev,int &lepesszam);
};

#endif // EDITOR_HPP_INCLUDED
