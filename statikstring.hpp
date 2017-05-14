#ifndef STATIKSTRING_HPP_INCLUDED
#define STATIKSTRING_HPP_INCLUDED

#include "graphics.hpp"
#include "oswidget.hpp"

using namespace std;


class statikstring : public Widget{
protected:
    string s;


public:
    statikstring(int x, int y, int sx, int sy , string s );
    virtual void kirajzol() const;
    //virtual void set_s( string s_) ;
};

//gout.twidth(s)+10
#endif // STATIKSTRING_HPP_INCLUDED
