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
    cout<<"4) Salir del Juego"<<endl;
    cout<<""<<endl;
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
                case 4:
                    system("cls");
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
    cout<<"1) Movimiento"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"2) Accion"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"3) Aceptar"<<endl;
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
