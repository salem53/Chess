#ifndef PION_H
#define PION_H
#include "Piece.h"



class PionNoir : virtual public Piece
{
    public:
        PionNoir(){
            name='P';colour="Noir";peutAttaquer=false;nom="pion";
        };
        PionNoir(Position p){
            pos.editPosition(p);name='P';colour="Noir";peutAttaquer=false;nom="pion";
        };
        virtual ~PionNoir(){};
        bool verifMove(Position p) {
                //if(p.getH()!=pos.getH() && !peutAttaquer) return false;
                if( (p.getH()-pos.getH()==1 || p.getH()-pos.getH()==-1) && (pos.getV()-p.getV()==1)
                     && peutAttaquer  ) return true ;
                //else if(p.getV()-pos.getV()<=0 || p.getV()-pos.getV()>2) return false;
                else if(pos.getV()-p.getV()==2 && (pos.getV()==7 )  && p.getH()==pos.getH()) return true ;
                else if (pos.getV()-p.getV()==1 && p.getH()==pos.getH()) return true ;
                else {

                return false;
                }
        }
        void moveP(Position p){
            if (verifMove(p)){
                std::cout << "Pion " << colour << " a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
                pos.editPosition(p);
            }
            else {
                std::cout << "Deplacement de Pion "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
            }
        }
        std::string getCouleur() {
            return colour;
        }
        virtual void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 10);
            std::cout << name ;
        }
        Position getPosition() {
            return pos;

        }
         std::string getNom(){
            return nom ;
        }
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }
    protected:

    private:
};

#endif // PION_H

