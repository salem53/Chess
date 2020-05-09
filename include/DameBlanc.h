#ifndef DAMEBLANC_H
#define DAMEBLANC_H
#include "DameNoir.h"


class DameBlanc : virtual public DameNoir
{
    public:
        DameBlanc():DameNoir(){colour="Blanc";};
        DameBlanc(Position p) :DameNoir(p){colour="Blanc";};
        void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~DameBlanc(){};

    protected:

    private:
};

#endif // DAMEBLANC_H
