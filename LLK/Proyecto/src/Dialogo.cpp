#include <Dialogo.h>
#include <MyWindow.h>
#include <Position.h>
Dialogo::Dialogo(string a,Position b)
{
    d=a;
    pos=b;
}
Dialogo::Dialogo(string a)
{
    Position b(0,22);
    d=a;
    pos=b;
}
Dialogo::Dialogo()
{
    Position b(0,22);
    d="";
    pos=b;
}
void Dialogo::GetD(MyWindow *w)
{
    w->ShowMessage(Position(0,22),d);
}
