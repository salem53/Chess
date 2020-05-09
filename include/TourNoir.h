#ifndef TOURNOIR_H
#define TOURNOIR_H
#include <Piece.h>


class TourNoir : virtual public Piece
{
    public:
        TourNoir() {
            name='T';colour="Noir";nom="tour";
        };
         TourNoir(Position p) {
           pos.editPosition(p);name='T';colour="Noir";nom="tour";
        };
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }
         bool verifMove(Position p) {
                if(p.getH()==pos.getH() && p.getV()!=pos.getV() ) return true ;
                else if (p.getH()!=pos.getH() && p.getV()==pos.getV()) return true;
                 else {
                return false;
                }
        }
        void moveP(Position p){
                        if (verifMove(p)){
                            std::cout << "Tour "<< colour << "a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout << std :: endl ;
                            pos.editPosition(p)
                        ;}
                        else {
                            std::cout << "Deplacement de Tour "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
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
         std::string getNom(){
            return nom ;
        }
        std::string getCouleur() {
            return colour;
        }
        virtual ~TourNoir(){};

    protected:

    private:
};

#endif // TOURNOIR_H
