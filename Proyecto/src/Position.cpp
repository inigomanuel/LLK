#include "Position.h"

Position::Position(){
    x=0;
    y=0;
}

Position::Position(int c):x(c),y(c){
}

Position::Position(int cx,int cy):x(cx),y(cy){
}
bool Position::PosComp(Position b)
{
    if (x==b.x)
    {
        if(y==b.y)
            return true;
    }
    return false;
}
