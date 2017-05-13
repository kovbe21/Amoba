#include "graphics.hpp"

#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

window::window()
{

}

void window::esemeny(string azonosito) {}

void window::eventloop( int XX, int YY){

int akti=-1;
int aktj=-1;
int posx, posy;
int actplayer=1;
event ev;

    while(gin >> ev && ev.keycode!=key_escape){
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);

        for(int i=0 ; i<20 ; i++){
            for(int j=0 ; j<20 ; j++){



            if (ev.type==ev_mouse&& ev.button==btn_left && akti==-1 && aktj==-1 && w[i][j]->is_selected(ev.pos_x , ev.pos_y)){
                akti=i;
                aktj=j;
                posx=ev.pos_x;
                posy=ev.pos_y;
                //actplayer++;
cout<<"lepesszam: "<<actplayer<<endl;
            }

            }
        }
cout<<"akt koord: "<<akti<<' '<<aktj<<endl;

            if(akti!=-1 && aktj!=-1){
                w[akti][aktj]->handle(ev , actplayer);
            }


        akti=-1;
        aktj=-1;


        for(int i=0 ; i<20 ; i++){
            for(int j=0 ; j<20; j++){
            w[i][j]->kirajzol();

            }
        }

       gout<<refresh;


       }


}
