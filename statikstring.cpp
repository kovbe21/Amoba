#include "statikstring.hpp"
#include "graphics.hpp"

using namespace genv;

statikstring::statikstring(window * parent , int x, int y, int sx, int sy ,std:: string s ,std::string azonosito )
    : Widget(x,y,sx,sy)
{
_s = s;
_azonosito = azonosito;
_sx= gout.twidth(s)+10;
_parent=parent;
}

void statikstring:: unidraw(int lepesszam, int kinyert,int XX,int YY){

if(kinyert!=0){
            if(kinyert==1){
                    gout<<color(255,0,0)
                        <<move_to(0,100)<<box(XX,XX)
                        <<color(255,255,255)<<move_to(150,250)<<text("Nyert a piros!");}
            else if(kinyert==2){
                    gout<<color(0,0,255)
                    <<move_to(0,100)<<box(XX,XX)
                        <<color(255,255,255)<<move_to(150,250)<<text("Nyert a kék!");}
            else{
                gout<<color(255,0,255)
                <<move_to(0,100)<<box(XX,XX)
                        <<color(255,255,255)<<move_to(150,250)<<text("Döntetlen!");}


            }

            int allapot=(lepesszam % 2)+1;
            if(allapot==1){
                gout<<color(255,0,0);
            }else if(allapot==2){
                gout<<color(0,0,255);
            }
            gout<<move_to(_x+_sx,_y)<<box(30,30);
            if(kinyert>0){
                gout<<color(0,0,0)<<move_to(_x+_sx,_y)<<box(30,30)
                    <<color(255,255,255)<<move_to(_x+_sx,_y)
                    <<line_to(_x+_sx+30,_y+30)<<move_to(_x+_sx+30,_y)
                    <<line_to(_x+_sx,_y+30);
            }



}

void statikstring::kirajzol() const{

    gout<<move_to(_x , _y)<<color(255,255,255)<<box(_sx , _sy);
    gout<<move_to(_x+2 , _y+2)<<color(0,0,0)<<box(_sx-4, _sy-4);
    gout<<move_to(_x+3,_y+_sy/2+gout.cascent()/2)<<color(255,255,255)<<text(_s);
    gout<<move_to(110,_y-10)<<text("5 in a row. Have fun!");

    _parent->esemeny(_azonosito);
}
