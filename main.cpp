#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include "editor.hpp"
#include <iostream>
using namespace std;

//todo: actplayer ref ki

const int XX=400;
const int YY=450;

class Mywindow : public window{
    protected:
    editor *e;
    int sx;
    int sy;


    public:
    Mywindow(int xx, int yy){


        sx=XX/xx;
        sy=(YY-50)/yy;
       for(int i=0; i<xx; i++){
        for(int j=0; j<yy; j++){

            t[i][j]=new Square(i*sx,50+j*sy,sx,sy);
            w.push_back(t[i][j]);
        }

       }
    e = new editor(this,5,5,60,30,"New Game / RESET" , "reset");
    w.push_back(e);
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
}
};

int main()
{

    Mywindow *Mw = new Mywindow(20,20);
    Mw->eventloop(XX,YY);

    return 0;
}
