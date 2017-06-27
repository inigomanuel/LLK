#include "Weapon.h"

Weapon::Weapon(char x)
{
    model=x;
}
Weapon::Weapon()
{
    model='♠';
}
void Weapon::Draw(Position pos,int cara)
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
                DrawPixel(q,model);
                break;
            case 1:
                q.y+=1;
                DrawPixel(q,model);
                break;
            case 2:
                q.x-=1;
                DrawPixel(q,model);
                break;
            case 3:
                q.x+=1;
                DrawPixel(q,model);
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
                Delete(q);
                break;
            case 1:
                q.y+=1;
                Delete(q);
                break;
            case 2:
                q.x-=1;
                Delete(q);
                break;
            case 3:
                q.x+=1;
                Delete(q);
                break;
            }
        }
}
void Weapon::Delete(Position pos)
{
    Position q;
    q.x=pos.x;
    q.y=pos.y;
    GotoXY(q.x,q.y);
    cout<<" ";
}
