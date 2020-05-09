#ifndef PION_H
#define PION_H
#include "Piece.h"


class PionNoir : virtual public Piece
{
    public:
        PionNoir(){name="P";colour="Noir";};
        PionNoir(Positin p){pos=p;name="P";colour="Noir";}
        virtual ~Pion(){};
        bool verifMove(Position p,bool peutAttaquer) {
                //if(p.getH()!=pos.getH() && !peutAttaquer) return false;
                if( (p.getH()-pos.getH()==1 || p.getH()-pos.getH()==-1) && peutAttaquer  ) return true ;
                //else if(p.getV()-pos.getV()<=0 || p.getV()-pos.getV()>2) return false;
                else if(pos.getV()-p.getV()==2 && (pos.getV==7 )  && p.getH()==pos.getH()) return true ;
                else if (pos.getV()-p.getV()==1 && p.getH()==pos.getH()) return true ;
                else return false;
            }
        void moveP(Position p,bool peutAttaquer){
            if (verifMove(Position p,bool peutAttaquer))
                {Position=p;}

        void afficher()  {
            cout << name ;
            }

    protected:

    private:
};

#endif // PION_H

