#ifndef POSITION_H
#define POSITION_H
#include <bits/stdc++.h>
#include <windows.h>

class Position
{
    public:
        Position(){
            h='_';
            v=0;
        };
        Position(char h, int v){
            if(h>='a' && h<='h' && v>=1 && v<=8 ) {
                this->h=h;
                this->v=v;
                position=true;
            }
            else {
            std::cout << "Merci de verifier la position ." << std::endl ;
            position=false;
            }
        };
        void editPosition(Position p){
            if (p.verifPosition()) {
            this->h=p.getH();
            this->v=p.getV();
            }
        }
        char getH() {
            return h;
        }
        int getV(){
        return v;
        }
        void afficher(){
           std::cout << h << v ;
        }
        bool verifPosition(){
            return position ;
        }
        bool egale(Position p) {
            return h==p.getH() && v==p.getV() ;
        }
        virtual ~Position(){};
    protected:
        char h;
        int v;
        bool position ;
    private:
};

#endif // POSITION_H
