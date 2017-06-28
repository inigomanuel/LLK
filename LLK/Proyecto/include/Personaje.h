#ifndef Personaje_H
#define Personaje_H
#include <Screen.h>
#include <Position.h>
#include <iostream>
#include <Dialogo.h>
#include <Weapon.h>
#include <vector>
using namespace std;
class Personaje:public Screen
{
    protected:
        Weapon espada;
        Position pos;
        char shape;
        int health;
        int cara;
    public:
        string dialogue;
        Personaje();
        Personaje(char);
        Personaje(Position,char);
        Personaje(Position,char,string);
        virtual void Draw();
        void SetShape(char);
        void Move(int a,int b);
        void ChangePos(Position h);
        int GetHealth();
        int setcara(int dir);
        int getcara();
        Position GetPos();
        void hit();
        void Attack(vector<Personaje>e,int t);
        Weapon getweapon();
        void MHP(int);
        bool PosComp(Position,Position);
};
#endif // PERSONAJE_H
