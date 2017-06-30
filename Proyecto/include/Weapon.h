#ifndef WEAPON_H
#define WEAPON_H
#include <Screen.h>
#include "iostream"
#include <Position.h>
#include <vector>
using namespace std;
class Weapon:public Screen
{
    public:
        Weapon();
        Weapon(char x);
        void Draw(Position);
        void Delete(Position pos);
    protected:
        char model;
};

#endif // WEAPON_H
