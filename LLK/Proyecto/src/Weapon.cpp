#include "Weapon.h"
#include <Personaje.h>
Weapon::Weapon(char x)
{
    model=x;
}
Weapon::Weapon()
{
    model=4;
}
void Weapon::Draw(Position pos)
{
    DrawPixel(q,model);
}
void Weapon::Delete(Position pos)
{
    Position q;
    q.x=pos.x;
    q.y=pos.y;
    GotoXY(q.x,q.y);
    cout<<" ";
}
