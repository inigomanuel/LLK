#include "lvl.h"
#include <Personaje.h>
#include <Menu.h>
#include <vector>
#include <iostream>
using namespace std;
lvl::lvl()
{
    Menu m;
    m.Body();
    windowGame = new MyWindow(MySize(40,15));
    Position t=windowGame->GetPosition();
    t.x+=3;
    t.y+=2;
    myPersonaje = new Personaje(t,'x');
    t.x=10;
    t.y=8;
    enemies.push_back(Personaje (t,'&'));
    t.x=16;
    t.y=9;
    npcs.push_back(Personaje (t,'o',"Joven, me parece sensual."));
    t.x=20;
    t.y=18;
    npcs.push_back(Personaje (t,'s',"OIEKTPAZAIMBEZILO"));
    t.x=20;
    t.y=15;
    npcs.push_back(Personaje (t,'t',"funciona plz :c"));
    MySize st=windowGame->GetMySize();
    t=windowGame->GetPosition();
    t.x++;
    t.y++;

    srand (time(NULL));
}

void lvl::Refresh()
{
    myPersonaje->Draw();
    for (int i=0;i<npcs.size();i++)
    {
            npcs[i].Draw();
    }
    for (int i=0;i<enemies.size();i++)
    {
            enemies[i].Draw();
    }
    string xd="Llanuras Frias";
    stringstream hb;
    hb<<myPersonaje->GetHealth();
    windowGame->ShowMessage(Position(windowGame->GetMySize().width-xd.size()*1.5,1),xd);
    windowGame->ShowMessage(Position(0,3),string("Salud: ")+hb.str());
}

void lvl::ReachLimit(Personaje *b,Position op)
{
    int g=0;
    Position pb=b->GetPos();
    Position pw=windowGame->GetPosition();
    MySize sw=windowGame->GetMySize();
    for(int j=0;j<npcs.size();j++){
    Position i=npcs[j].GetPos();
    if(pb.x==i.x&pb.y==i.y)
    {
        b->ChangePos(op);
    }
    if(pb.x > pw.x && pb.x < pw.x +sw.width-1 && pb.y > pw.y && pb.y < pw.y +sw.height-1)
        g=g+1;
    else
        b->ChangePos(op);
    }
}

void lvl::GR1(Personaje *Kub,Position retr)
{
    Position d,c;
    int val;
    val=-1;
    d=Kub->GetPos();
    for(int j=0;j<npcs.size();j++)
    {
    c=npcs[j].GetPos();
    if((d.x<=c.x+1&&d.x>=c.x-1)&&(d.y<=c.y+1&&d.y>=c.y-1))
    {
        val=j;
    }
    }
    if(val>=0)
         windowGame->ShowMessage(Position(0,22),npcs[val].dialogue);
    else
        windowGame->ShowMessage(Position(0,22),"                                                                                                           ");
    Position a,b;
    a=Kub->GetPos();
    for (int i=0;i<enemies.size();i++)
    {
        b=enemies[i].GetPos();
        if(a.x==b.x&a.y==b.y)
        {
            Kub->hit();
            Kub->ChangePos(retr);
            windowGame->ShowMessage(Position(0,21),"Ouch!");
        }}}
void lvl::Start()
{
    char c;
    bool endGame=false;
    windowGame->Draw();


    do
    {
        Position pb=myPersonaje->GetPos();
        if(kbhit())
        {
            c = getch();


            switch (c)
            {
                case ESC:
                    break;
                case SPACE:
                    myPersonaje->Attack(enemies,enemies.size());
                    Sleep(200);
                    break;
                case UP:
                    myPersonaje->setcara(0);
                    myPersonaje->Move(0,-1);
                    break;
                case DOWN:
                    myPersonaje->setcara(1);
                    myPersonaje->Move(0,1);
                    break;
                case LEFT:
                    myPersonaje->setcara(2);
                    myPersonaje->Move(-1,0);
                    break;
                case RIGHT:
                    myPersonaje->setcara(3);
                    myPersonaje->Move(1,0);
                    break;
            }
        }
        ReachLimit(myPersonaje,pb);
        GR1(myPersonaje,pb);
        Refresh();

        if(0==myPersonaje->GetHealth())
        {
            endGame=true;
            windowGame->ShowMessage(Position(0,21),string("Perdiste crrano color ianta"));
        }

   Sleep(30);

    }while(!endGame);

    windowGame->ShowMessage(Position(0,22),"The End...");
}

lvl::~lvl()
{
    delete windowGame;
}
//https://i.redd.it/86eah50v896z.png
