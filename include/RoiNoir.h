#ifndef ROINOIR_H
#define ROINOIR_H
#include "Piece.h"

class RoiNoir : virtual public Piece
{
        public:
        RoiNoir() {
            name='C';colour="Noir"; casteling=true;nom="roi";
        };
        RoiNoir(Position p){
            pos.editPosition(p);name='R';colour="Noir";casteling=true;nom="roi";
        };
        bool verifMove(Position p) {
                if (p.getV()==pos.getV() && abs(p.getH()-pos.getH())==2 && casteling) return true ;
                else if (p.getV()==pos.getV() && abs(p.getH()-pos.getH())==1) return true ;
                else if (abs(p.getV()-pos.getV())==1 && (p.getH()==pos.getH())) return true ;
                else if (abs(p.getV()-pos.getV())==1 && abs(p.getH()-pos.getH())==1) return true ;
                else {

                return false;
                }
        }
        void moveP(Position p){
                        if (verifMove(p)){
                            std::cout << "Roi "<< colour << " a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout << std :: endl ;
                            pos.editPosition(p)
                        ;}
                        else {
                            std::cout << "Deplacement de Roi "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
                        }
        }
        virtual void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 10);
            std::cout << name ;
        }
        Position getPosition() {
            return pos;

        }
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }
        void setCastling(bool t) {
            casteling=t;
        }
        std::string getCouleur() {
            return colour;
        }
         std::string getNom(){
            return nom ;
        }

        virtual ~RoiNoir(){};

    protected:
        bool casteling ;
    private:
};

#endif // ROINOIR_H
