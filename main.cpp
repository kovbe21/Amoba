#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace std;
using namespace genv;


const int XX=400;
const int YY=450;

class Mywindow : public window{
    protected:

    int sx;
    int sy;
  //  vector<vector<Square*>> t;
    public:
    Mywindow(int xx, int yy){



        sx=XX/xx;
        sy=(YY-50)/yy;
       for(int i=0; i<xx; i++){
        for(int j=0; j<yy; j++){
            //Square * tmp = new Square(1+i*sx,51+i*sy,sx,sy);
            w[i][j]=new Square(i*sx,50+j*sy,sx,sy);
        }
       // w.push_back(w[i]);
       }

    }

   /* void esemeny(string azonosito){
    if(azonosito=="add"){
        k1->ujelem(e1->Gets());
    }
    if(azonosito=="pop"){
        k1->torol();
    }

    }*/


};

int main()
{
    gout.open(XX,YY);
    Mywindow *Mw = new Mywindow(20,20);
    Mw->eventloop(XX,YY);
   // delete Mw;
    return 0;
}
