#ifndef DAMENOIR_H
#define DAMENOIR_H
#include "TourNoir.h"
#include "FouNoir.h"


class DameNoir : virtual public FouNoir , virtual public TourNoir
{
public:
        DameNoir() {
            name='D';colour="Noir";nom="dame";

        };
        DameNoir(Position p){
            pos.editPosition(p);name='D';colour="Noir";nom="dame";
        };
        bool verifMove(Position p) {
                if (FouNoir::verifMove(p) || TourNoir::verifMove(p)) return true ;
                //else if(pos.getV()-p.getV()==2 && (pos.getV()==7 )  && p.getH()==pos.getH()) return true ;
                //else if (pos.getV()-p.getV()==1 && p.getH()==pos.getH()) return true ;
                 else {

                return false;
                }
        }
        void moveP(Position p){
                        if (verifMove(p)){
                            std::cout << "Dame "<< colour << " a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout << std :: endl ;
                            pos.editPosition(p)
                        ;}
                        else {
                        std::cout << "Deplacement de Dame "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
                        }
        }
        virtual void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 10);
            std::cout << name ;
        }
        std::string getNom(){
            return nom ;
        }
        std::string getCouleur() {
            return colour;
        }
        Position getPosition() {
            return pos;

        }
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }





        virtual ~DameNoir(){};

    protected:

    private:
};

#endif // DAMENOIR_H
