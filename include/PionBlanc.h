#ifndef PIONBLANC_H
#define PIONBLANC_H
#include "PionNoir.h"


class PionBlanc : virtual public PionNoir
{
public :
        PionBlanc ():PionNoir (){colour="Blanc";};
        PionBlanc(Position p) :PionNoir (p){colour="Blanc";};
        bool verifMove(Position p) {
                //if(p.getH()!=pos.getH() && !peutAttaquer) return false;
                if( (p.getH()-pos.getH()==1 || p.getH()-pos.getH()==-1) && peutAttaquer  ) return true ;
                //else if(p.getV()-pos.getV()<=0 || p.getV()-pos.getV()>2) return false;
                else if(p.getV()-pos.getV()==2 && (pos.getV()==2 )  && p.getH()==pos.getH()) return true ;
                else if (p.getV()-pos.getV()==1 && p.getH()==pos.getH()) return true ;
                else {

                return false;
                }
        }
         void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~PionBlanc (){};

    protected:

    private:
};

#endif // PIONBLANC_H
