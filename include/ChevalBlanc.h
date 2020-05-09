#ifndef CHEVALBLANC_H
#define CHEVALBLANC_H
#include "ChevalNoir.h"


class ChevalBlanc : virtual public ChevalNoir
{  public:
    ChevalBlanc():ChevalNoir(){colour="Blanc";};
        ChevalBlanc(Position p) :ChevalNoir(p){colour="Blanc";};
        void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~ChevalBlanc(){};
    protected:

    private:
};

#endif // CHEVALBLANC_H
