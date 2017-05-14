#include "oswidget.hpp"
#include "statikstring.hpp"
#include "window.hpp"
#include "square.hpp"
#include "button.hpp"
#include <iostream>
using namespace std;

//todo: actplayer ref ki

const int XX=400;
const int YY=500;

class Mywindow : public window{
    protected:
    button *r;
    button *q;
    statikstring *s;

    int sx;
    int sy;


    public:
    Mywindow(int xx, int yy){


        sx=XX/xx;
        sy=(YY-100)/yy;
       for(int i=0; i<xx; i++){
        for(int j=0; j<yy; j++){

            t[i][j]=new Square(i*sx,100+j*sy,sx,sy);
            w.push_back(t[i][j]);
        }

       }
    r = new button(this,5,5,0,30,"New Game / RESET" , "reset");
    w.push_back(r);
    s = new statikstring(100,70,0,30,"Next: ");
    w.push_back(s);
    q = new button(this,220,5,0,30,"Exit (or press esc)", "exit");
    w.push_back(q);
    }

void esemeny(string azonosito){
    if(azonosito=="reset"){
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                t[i][j]->reSet();
            }
        }
    kinyert=0;
    }
    if(azonosito=="exit"){
        exit=true;
    }
}
};

int main()
{

    Mywindow *Mw = new Mywindow(20,20);
    Mw->eventloop(XX,YY);

    return 0;
}
