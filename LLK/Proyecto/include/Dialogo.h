#ifndef DIALOGO_H
#define DIALOGO_H
#include <MyWindow.h>
class Dialogo
{
    public:
        Dialogo();
        Dialogo(string a,Position b);
        Dialogo(string a);
        void GetD(MyWindow *w);
        void SetD(string a);
    protected:
        string d;
        Position pos;
};

#endif // DIALOGO_H
