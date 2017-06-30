#ifndef LVL_H
#define LVL_H
#include <MyWindow.h>
#include <Personaje.h>
#include <time.h>
#include <sstream>
#include <vector>
#include <Weapon.h>
#include <Menu.h>
const char UP = 72;
const char LEFT = 75;
const char RIGHT = 77;
const char DOWN = 80;
const char ESC = 27;
const char SPACE = 32;

class lvl
{
    protected:
        Menu m;
        vector<vector<Personaje> > mobs;
        MyWindow *windowGame;
        vector <Personaje> npcs;
        Personaje *myPersonaje;
        vector <Personaje> enemies;
        int takenDamageC;
    public:
        lvl();
        void Start();
        void Refresh();
        void ReachLimit(Personaje*,Position);
        void GR1(Personaje*,Position);
        void Attack();
        void VerifyHP();
        ~lvl();
        void UseTDC();
};

#endif // LVL_H
