#include "oswidget.hpp"
#include "statikstring.hpp"
#include "window.hpp"
#include "square.hpp"
#include "button.hpp"

//todo: actplayer ref ki

const int XX=400;
const int YY=500;

class Mywindow : public window{
    protected:
        button *r;
        button *q;
        statikstring *u;
        int sx;
        int sy;
    public:
    Mywindow(){


        sx=XX/20;
        sy=(XX)/20;
       for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){

            t[i][j]=new Square(i*sx,YY-XX+j*sy,sx,sy);
            w.push_back(t[i][j]);
        }
       }
    r = new button(this,5,5,0,30,"New Game / RESET" , "reset");
    u = new statikstring(this,150,70,0,30,"Next: ","uni");
    q = new button(this,220,5,0,30,"Exit (or press esc)", "exit");
    w.push_back(u);
    w.push_back(r);
    w.push_back(q);
    }


    void esemeny(std::string azonosito){
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
        if(azonosito=="uni"){
            u->unidraw(lepesszam, kinyert,XX,YY);
        }
    }
};

int main()
{
    Mywindow *Mw = new Mywindow;
    Mw->eventloop(XX,YY);

    return 0;
}
