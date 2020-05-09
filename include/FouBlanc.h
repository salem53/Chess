#ifndef FOUBLANC_H
#define FOUBLANC_H
#include "FouNoir.h"


class FouBlanc : virtual public FouNoir
{
public:
       FouBlanc():FouNoir(){colour="Blanc";};
        FouBlanc(Position p) :FouNoir(p){colour="Blanc";};
        void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~FouBlanc(){};

    protected:

    private:
};

#endif // FOUBLANC_H
