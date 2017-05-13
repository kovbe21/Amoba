#include "graphics.hpp"

#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include "editor.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;


void ellenor(Square* t[20][20],int akt,int kinyert){

int x,y,n,w,s,e,nw,sw,se,ne;
n=w=s=e=nw=ne=sw=se=0;
x=akt/20; //hányszor van meg benne a 20, hanyadik oszlop
y=akt%20; //hanyadik sor
/*westsum: */
for(int i=1 ; i<x+1 ; i++){
    if(t[x][y]->GetAllapot()==t[x-i][y]->GetAllapot()){
        w++;

    }else{break;}
}
//eastsum
for(int i=1 ; i<=19-x  ; i++){
    if(t[x][y]->GetAllapot()==t[x+i][y]->GetAllapot()){
        e++;

    }else{break;}
}
//northsum
for(int i=1 ; i<y+1  ; i++){
    if(t[x][y]->GetAllapot()==t[x][y-i]->GetAllapot()){
        n++;

    }else{break;}
}
//southsum
for(int i=1 ; i<=19-y  ; i++){
    if(t[x][y]->GetAllapot()==t[x][y+i]->GetAllapot()){
        s++;

    }else{break;}
}
//nwsum
for(int i=1 ; i<y+1 && i<x+1  ; i++){
    if(t[x][y]->GetAllapot()==t[x-i][y-i]->GetAllapot()){
        nw++;
    }else{break;}
}
//sesum
for(int i=1 ; i<=19-y && i<=19-x  ; i++){
    if(t[x][y]->GetAllapot()==t[x+i][y+i]->GetAllapot()){
        se++;
    }else{break;}
}
//ne
for(int i=1 ; i<y+1 && i<19-x  ; i++){
    if(t[x][y]->GetAllapot()==t[x+i][y-i]->GetAllapot()){
        ne++;
    }else{break;}
}
//sw
for(int i=1 ; i<19-y && i<x+1  ; i++){
    if(t[x][y]->GetAllapot()==t[x-i][y+i]->GetAllapot()){
        nw++;
    }else{break;}
}
if(w+e==4 || n+s==4 || nw+se==4 || ne+sw==4){
        cout<<"Nyert a player"<<t[x][y]->GetAllapot()<<endl;
    kinyert=t[x][y]->GetAllapot();
}


}







window::window()
{

}

void window::esemeny(string azonosito) {}

void window::eventloop( int XX, int YY){

int akt=-1;
//int aktj=-1;
int posx, posy;
int lepesszam=1;
int kinyert=0;
event ev;

    while(gin >> ev && ev.keycode!=key_escape){
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);

        for(int i=0 ; i<w.size() ; i++){




            if (ev.type==ev_mouse&& ev.button==btn_left && akt==-1  && w[i]->is_selected(ev.pos_x , ev.pos_y)){
                akt=i;

                posx=ev.pos_x;
                posy=ev.pos_y;


            }


        }


            if(akt!=-1){
                    cout<<"akt koord: "<<akt<<' '<<endl;
                w[akt]->handle(ev , lepesszam);
                ellenor(t,akt,kinyert);
            }



        akt=-1;



        for(int i=0 ; i<w.size() ; i++){

            w[i]->kirajzol();


        }

       gout<<refresh;


       }


}
