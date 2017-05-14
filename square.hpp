#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "oswidget.hpp"

class Square : public Widget{
protected:
    int _allapot;
public:

    Square(int x, int y, int sx, int sy) ;
    virtual void kirajzol() const;
    virtual void handle(genv::event ev , int& lepesszam) ;
    virtual int GetAllapot() const;
    virtual void reSet();

};

#endif // SQUARE_HPP_INCLUDED
