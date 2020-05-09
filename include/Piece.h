#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <Position.h>



    class Piece
{
    public:
        Piece(){};
        virtual ~Piece(){};
        virtual void moveP(Position p) = 0 ;
        virtual bool verifMove(Position po)=0;
        virtual void afficher()=0;
        virtual Position getPosition()=0;
        virtual std::string getCouleur()=0;
        virtual std::string getNom()=0;
        virtual void setPeutAttaquer(bool t)=0;

    protected:
        std::string colour;
        Position pos;
        char name ;
        bool peutAttaquer ;
        std::string nom;

    private:
};

#endif // PIECE_H
