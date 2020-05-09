#ifndef FOUNOIR_H
#define FOUNOIR_H
#include "Piece.h"

class FouNoir : virtual public Piece
{
    public:
        FouNoir() {
            name='F';colour="Noir";nom="fou";

        };
        FouNoir(Position p){
            pos.editPosition(p);name='F';colour="Noir";nom="fou";
        };
        bool verifMove(Position p) {
                if (abs(p.getH()-pos.getH())==abs(p.getV()-pos.getV()) && abs(p.getH()-pos.getH())>0) return true ;
                //else if(pos.getV()-p.getV()==2 && (pos.getV()==7 )  && p.getH()==pos.getH()) return true ;
                //else if (pos.getV()-p.getV()==1 && p.getH()==pos.getH()) return true ;
                 else {

                return false;
                }
        }
        void moveP(Position p){
                        if (verifMove(p)){
                            std::cout << "Fou "<< colour << " a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout << std :: endl ;
                            pos.editPosition(p)
                        ;}
                        else {
                            std::cout << "Deplacement de Fou "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
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
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }
        Position getPosition() {
            return pos;

        }
        std::string getCouleur() {
            return colour;
        }





        virtual ~FouNoir(){};

    protected:

    private:
};

#endif // FOUNOIR_H
