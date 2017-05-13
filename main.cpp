#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include "graphics.hpp"
#include "editor.hpp"
#include <iostream>
using namespace std;
using namespace genv;
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
e = new editor(5,5,60,30,"probawidget");
    w.push_back(e);
    }


};

int main()
{
    gout.open(XX,YY);
    Mywindow *Mw = new Mywindow(20,20);
    Mw->eventloop(XX,YY);

    return 0;
}
