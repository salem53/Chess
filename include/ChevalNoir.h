#ifndef CHEVALNOIR_H
#define CHEVALNOIR_H


class ChevalNoir : virtual public Piece
{
    public:
        ChevalNoir() {
            name='C';colour="Noir";nom="cheval";
        };
        ChevalNoir(Position p){
            pos.editPosition(p);name='C';colour="Noir";nom="cheval";
        };
        bool verifMove(Position p) {
                if (abs(p.getH()-pos.getH())==1 && abs(p.getV()-pos.getV())==2) return true ;
                else if (abs(p.getH()-pos.getH())==2 && abs(p.getV()-pos.getV())==1) return true ;
                else {

                return false;
                }
        }
        void moveP(Position p){
                        if (verifMove(p)){
                            std::cout << "Cheval "<< colour << " a deplace avec succees de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout << std :: endl ;
                            pos.editPosition(p)
                        ;}
                        else {
                            std::cout << "Deplacement de Cheval "<< colour << " impossible de " ; pos.afficher() ;std::cout <<" a " ;  p.afficher() ; std::cout <<"." <<std :: endl ;
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
        std::string getCouleur() {
            return colour;
        }
        std::string getNom(){
            return nom ;
        }
        virtual void setPeutAttaquer(bool t) {
            peutAttaquer=t;
        }
        virtual ~ChevalNoir(){};

    protected:

    private:
};

#endif // CHEVALNOIR_H

