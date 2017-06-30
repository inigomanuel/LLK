#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        int x,y;
        Position();
        Position(int);
        Position(int,int);
        bool PosComp(Position);
};

#endif // POSITION_H
