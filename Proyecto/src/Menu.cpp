#include "Menu.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

void Menu::Preguntar()
{
    int usuario;
    cout<<"1) Iniciar el Juego"<<endl;
    cout<<"2) Instrucciones"<<endl;
    cout<<"3) Creditos"<<endl;
    cout<<"Que desea hacer?"<<endl;
    cin>>usuario;
        switch (usuario)
            {
                case 1:
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    Instrucciones();
                    break;
                case 3:
                    system("cls");
                    Creditos();
                    break;
            }
}
void Menu::Title()
{
    cout<<"                ___    ___     __         __ ___             __            "<<endl;
    cout<<"|    /\\    |   |__ \\ /|__ |\\ ||  \\ /\\    |  ||__    |__/|  ||__)|     /\\ \\ / "<<endl;
    cout<<"|___/__\\   |___|___ | |___| \\||__//__\\   |__/|___   |  \\|__||__)|___ /__\\ |  "<<endl;
}

void Menu::Instrucciones()
{
    cout<<"Use las flechas para moverse"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Use la barra espaciadora para atacar"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Use ESC para abrir el inventario"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    Preguntar();
}

void Menu::Creditos()
{
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Rafa"<<endl;
    cout<<"Inigo"<<endl;
    cout<<""<<endl;
    Preguntar();

}

void Menu::Body()
{
    int usuario=0;
    Title();
    cout<<""<<endl;
    cout<<""<<endl;
    Preguntar();
}
void Menu::Inventario()
{
    system("cls");
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Objetos:  "<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"-Espada"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Presione ESC para seguir jugando."<<endl;
    char c;
    while(c!=27)
    {
        c=getch();
    }
    system("cls");
}
