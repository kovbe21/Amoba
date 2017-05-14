#include "graphics.hpp"

#include "oswidget.hpp"
#include "window.hpp"
#include "square.hpp"
#include "button.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;


void ellenor(Square* t[20][20],int akt,int& kinyert){

int x,y,n,w,s,e,nw,sw,se,ne;
n=w=s=e=nw=ne=sw=se=0;
x=akt/20; //hányszor van meg benne a 20, hanyadik oszlop
y=akt%20;//hanyadik sor
int allapot=t[x][y]->GetAllapot();
int tele=0;
//westsum:
cout<<x<<' '<<y<<' '<<akt<<endl;
for(int i=1 ; i<x+1 ; i++){
    if(allapot==t[x-i][y]->GetAllapot()){
        w++;

    }else{break;}
}
//eastsum
for(int i=1 ; i<=19-x  ; i++){
    if(allapot==t[x+i][y]->GetAllapot()){
        e++;

    }else{break;}
}
//northsum
for(int i=1 ; i<y+1  ; i++){
    if(allapot==t[x][y-i]->GetAllapot()){
        n++;

    }else{break;}
}
//southsum
for(int i=1 ; i<=19-y  ; i++){
    if(allapot==t[x][y+i]->GetAllapot()){
        s++;

    }else{break;}
}
//nwsum
for(int i=1 ; i<y+1 && i<x+1  ; i++){
    if(allapot==t[x-i][y-i]->GetAllapot()){
        nw++;
    }else{break;}
}
//sesum
for(int i=1 ; i<=19-y && i<=19-x  ; i++){
    if(allapot==t[x+i][y+i]->GetAllapot()){
        se++;
    }else{break;}
}
//ne
for(int i=1 ; i<y+1 && i<19-x  ; i++){
    if(allapot==t[x+i][y-i]->GetAllapot()){
        ne++;
    }else{break;}
}
//sw
for(int i=1 ; i<19-y && i<x+1  ; i++){
    if(allapot==t[x-i][y+i]->GetAllapot()){
        nw++;
    }else{break;}
}
if(w+e>=4 || n+s>=4 || nw+se>=4 || ne+sw>=4){
        cout<<"Nyert a player"<<t[x][y]->GetAllapot()<<endl;
    kinyert=allapot;
}

for(int i=0 ; i<20 ; i++){
    for( int j=0 ; j<20 ; j++){
            if(t[i][j]->GetAllapot()!=0){
                tele++;
            }
    }
}
if(tele==400 && kinyert==0){kinyert=3;}

}


void nextstep(int lepesszam){
int allapot=(lepesszam % 2)+1;
if(allapot==1){
    gout<<color(255,0,0);
}else{gout<<color(0,0,255);}
gout<<move_to(100+gout.twidth("Next: ")+10,70)<<box(30,30);
}




window::window()
{
kinyert=0;
exit=false;
}

void window::esemeny(string azonosito) {}

void window::eventloop( int XX, int YY){
gout.open(XX,YY);
int akt=-1;
int posx, posy;
int lepesszam=1;


event ev;

    while(gin >> ev && ev.keycode!=key_escape && !exit){
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
                if(akt<400){                    //todo: eleg csunya, feltételezem hogy a widget vector elején vannak a square-ek
                    ellenor(t,akt,kinyert);
                }
            }



        akt=-1;




        for(int i=0 ; i<w.size() ; i++){
            w[i]->kirajzol();
        }
        if(kinyert!=0){
            if(kinyert==1){
                    gout<<color(255,0,0)
                        <<move_to(0,100)<<box(400,400)
                        <<color(255,255,255)<<move_to(150,250)<<text("Nyert a piros!");}
            else if(kinyert==2){
                    gout<<color(0,0,255)
                    <<move_to(0,100)<<box(400,400)
                        <<color(255,255,255)<<move_to(150,250)<<text("Nyert a kék!");}
            else{
                gout<<color(255,0,255)
                <<move_to(0,100)<<box(400,400)
                        <<color(255,255,255)<<move_to(150,250)<<text("Döntetlen!");}
            ;

            }
        nextstep(lepesszam);
       gout<<refresh;


       }


}
