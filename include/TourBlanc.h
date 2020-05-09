#ifndef TOURBLANC_H
#define TOURBLANC_H
#include "TourNoir.h"


class TourBlanc : virtual public TourNoir
{  public :
   TourBlanc ():TourNoir (){colour="Blanc";};
        TourBlanc (Position p) :TourNoir (p){colour="Blanc";};
         void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~TourBlanc (){};

    protected:

    private:
};

#endif // TOURBLANC_H
