#ifndef EDITOR_HPP_INCLUDED
#define EDITOR_HPP_INCLUDED

#include "graphics.hpp"
#include "oswidget.hpp"

using namespace std;


class editor : public Widget{
protected:
    string _s;

public:
    editor(int x, int y, int sx, int sy , string s );
    virtual void kirajzol() const;
    virtual void handle(genv::event ev,int &lepesszam);
};

#endif // EDITOR_HPP_INCLUDED
