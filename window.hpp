#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "square.hpp"
#include "oswidget.hpp"
#include <vector>
#include <iostream>
using namespace std;
class window{
protected:
    vector<Widget*> w;
    Square* t[20][20];
    int kinyert;
    bool exit;

public:
    window();
    virtual void eventloop(int XX,int YY);
    virtual void esemeny(std :: string azonosito);
};

#endif // WINDOW_HPP_INCLUDED
