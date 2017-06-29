#include "Personaje.h"
#include <Screen.h>
#include <Position.h>
Personaje::Personaje()
{
    pos.x=0;
    pos.y=0;
    shape='è';
    health=3;
}

Personaje::Personaje(char c)
{
    pos.x=0;
    pos.y=0;
    shape=c;
    health=3;
}

Personaje::Personaje(Position p,char c)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
}
Personaje::Personaje(Position p,char c,string a)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
    dialogue=a;
}
void Personaje::Draw()
{
    DrawPixel(pos,shape);
}

void Personaje::SetShape(char s)
{
    shape= s;
}

void Personaje::Move(int a, int b)
{
    Position j(pos.x+a,pos.y+b);
    DeletePixel(pos);
    pos=j;
}

Position Personaje::GetPos()
{
    return pos;
}
void Personaje::ChangePos(Position h)
{
    pos=h;
}
int Personaje::GetHealth()
{
    return health;
}
void Personaje::hit()
{
    health+=-1;
}
int Personaje::getcara()
{
   return cara;
}
int Personaje::setcara(int dir)
{
    cara=dir;
}
Weapon Personaje::getweapon()
{
    return espada;
}
void Personaje::Attack(vector<Personaje>e,int t)
{
    Position q;
    q.x=pos.x;
    q.y=pos.y;
    for (int i=0;i<2;i++)
        {
            switch(cara)
            {
            case 0:
                q.y-=1;
                for (int i=0;i<t;i++)
                {
                    if(PosComp(q,pos)==true)
                        e[i].hit();
                }
                espada.Draw(q);
                break;
            case 1:
                q.y+=1;
                for (int i=0;i<t;i++)
                {
                    if(PosComp(q,pos)==true)
                        e[i].hit();
                }
                espada.Draw(q);
                break;
            case 2:
                q.x-=1;
                for (int i=0;i<t;i++)
                {
                    if(PosComp(q,pos)==true)
                        e[i].hit();
                }
                espada.Draw(q);
                break;
            case 3:
                q.x+=1;
                for (int i=0;i<t;i++)
                {
                    if(PosComp(q,pos)==true)
                        e[i].hit();
                }
                espada.Draw(q);
                break;
            }
        }
    Sleep(200);
    q.x=pos.x;
    q.y=pos.y;
    for (int i=0;i<2;i++)
        {
            switch(cara)
            {
            case 0:
                q.y-=1;
                espada.Delete(q);
                break;
            case 1:
                q.y+=1;
                espada.Delete(q);
                break;
            case 2:
                q.x-=1;
                espada.Delete(q);
                break;
            case 3:
                q.x+=1;
                espada.Delete(q);
                break;
            }
        }
}
bool Personaje::PosComp(Position a,Position b)
{
    if (a.x==b.x)
    {
        if(b.y==a.y)
            return true;
        return false;
    }
}
