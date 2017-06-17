#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void Menu()
{
    cout<<"                ___    ___     __         __ ___             __            "<<endl;
    cout<<"|    /\\    |   |__ \\ /|__ |\\ ||  \\ /\\    |  ||__    |__/|  ||__)|     /\\ \\ / "<<endl;
    cout<<"|___/__\\   |___|___ | |___| \\||__//__\\   |__/|___   |  \\|__||__)|___ /__\\ |  "<<endl;
}

void Instrucciones()
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
}

void Creditos()
{
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Rafa"<<endl;
    cout<<"Inigo"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    int usuario_creditos=0;
    switch (usuario_creditos)
            {
                case 1:
                    cout<<"Juego Empieza"<<endl;;
                    break;
                case 2:
                    Instrucciones();
                    break;
                case 3:
                    Creditos();
                    break;
                case 4:
                    cout<<"El Juego Termino"<<endl;;
                    break;
            }
}

int main()
{
    int usuario=0;
    Menu();
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"1) Iniciar el Juego"<<endl;
    cout<<"2) Instrucciones"<<endl;
    cout<<"3) Creditos"<<endl;
    cout<<"4) Salir del Juego"<<endl;
    cout<<""<<endl;
    cout<<"Que desea hacer?"<<endl;
    cin>>usuario;
    int m=usuario;
        switch (m)
            {
                case 1:
                    cout<<"Juego Empieza"<<endl;;
                    break;
                case 2:
                    Instrucciones();
                    break;
                case 3:
                    Creditos();
                    break;
                case 4:
                    cout<<"El Juego Termino"<<endl;;
                    break;
            }
    return 0;
}
