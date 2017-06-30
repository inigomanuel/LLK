#include "lvl.h"
#include <Personaje.h>
#include <Menu.h>
#include <vector>
#include <iostream>
using namespace std;
lvl::lvl()
{
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
    npcs.push_back(Personaje (t,'o',"Todos tomamos decisiones en esta vida, pero al final nuestras decisiones nos hacen."));
    t.x=20;
    t.y=18;
    npcs.push_back(Personaje (t,'s',"El hombre correcto en el lugar equivocado puede hacer una diferencia en este mundo."));
    t.x=20;
    t.y=15;
    npcs.push_back(Personaje (t,'t',"Querer algo no te da el derecho de tenerlo."));
    MySize st=windowGame->GetMySize();
    t=windowGame->GetPosition();
    t.x++;
    t.y++;
    takenDamageC=0;
    srand (time(NULL));
    mobs.push_back(npcs);
    mobs.push_back(enemies);
}

void lvl::Refresh()
{
    myPersonaje->Draw();
    for (int i=0;i< mobs[0].size();i++)
    {
            mobs[0][i].Draw();
    }
    for (int i=0;i<mobs[1].size();i++)
    {
        mobs[1][i].Draw();
    }
    VerifyHP();
    UseTDC();
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
    for(int j=0;j<mobs[0].size();j++){
    Position i=mobs[0][j].GetPos();
    if(pb.PosComp(i)==true)
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
    for(int j=0;j<mobs[0].size();j++)
    {
    c=mobs[0][j].GetPos();
    if((d.x<=c.x+1&&d.x>=c.x-1)&&(d.y<=c.y+1&&d.y>=c.y-1))
    {
        val=j;
    }
    }
    if(val>=0)
         windowGame->ShowMessage(Position(0,22),mobs[0][val].dialogue);
    else
        windowGame->ShowMessage(Position(0,22),"                                                                                                           ");
    Position a,b;
    a=Kub->GetPos();
    for (int i=0;i< mobs[1].size();i++)
    {
        b= mobs[1][i].GetPos();
        if(a.x==b.x&a.y==b.y)
        {
            Kub->hit();
            Kub->ChangePos(retr);
            windowGame->ShowMessage(Position(0,21),"Ouch!");
            takenDamageC+=1;
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
                    m.Inventario();
                    windowGame->Draw();
                    break;
                case SPACE:
                    Attack();
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
            windowGame->ShowMessage(Position(0,21),string("Te han asesinado"));
        }

   Sleep(30);

    }while(!endGame);

    windowGame->ShowMessage(Position(0,22),"GG");
}

lvl::~lvl()
{
    delete windowGame;
}
void lvl::Attack()
{
   Position q;
    q.x=myPersonaje->GetPos().x;
    q.y=myPersonaje->GetPos().y;
    for (int i=0;i<2;i++)
        {
            switch(myPersonaje->getcara())
            {
            case 0:
                q.y-=1;
                for (int i=0;i< mobs[1].size();i++)
                {
                    if(q.PosComp( mobs[1][i].GetPos())==true)
                         mobs[1][i].hit();
                }
                myPersonaje->getweapon().Draw(q);
                break;
            case 1:
                q.y+=1;
                for (int i=0;i< mobs[1].size();i++)
                {
                    if(q.PosComp( mobs[1][i].GetPos())==true)
                         mobs[1][i].hit();
                }
                myPersonaje->getweapon().Draw(q);
                break;
            case 2:
                q.x-=1;
                for (int i=0;i< mobs[1].size();i++)
                {
                    if(q.PosComp( mobs[1][i].GetPos())==true)
                         mobs[1][i].hit();
                }
                myPersonaje->getweapon().Draw(q);
                break;
            case 3:
                q.x+=1;
                for (int i=0;i< mobs[1].size();i++)
                {
                    if(q.PosComp( mobs[1][i].GetPos())==true)
                         mobs[1][i].hit();
                }
                myPersonaje->getweapon().Draw(q);
                break;
            }
        }
    Sleep(200);
    q.x=myPersonaje->GetPos().x;
    q.y=myPersonaje->GetPos().y;
    for (int i=0;i<2;i++)
        {
            switch(myPersonaje->getcara())
            {
            case 0:
                q.y-=1;
                myPersonaje->getweapon().Delete(q);
                break;
            case 1:
                q.y+=1;
                myPersonaje->getweapon().Delete(q);
                break;
            case 2:
                q.x-=1;
                myPersonaje->getweapon().Delete(q);
                break;
            case 3:
                q.x+=1;
                myPersonaje->getweapon().Delete(q);
                break;
            }
        }
}
void lvl::VerifyHP()
{
    for(int i=0;i< mobs[1].size();i++)
    {
        if( mobs[1][i].GetHealth()<=0)
        {
             mobs[1].erase( mobs[1].begin() + i);
        }
    }
}
void lvl::UseTDC()
{
    if(takenDamageC>=1)
        takenDamageC+=1;
    if(takenDamageC==25){
        takenDamageC=0;
        windowGame->ShowMessage(Position(0,21),"      ");}
}
