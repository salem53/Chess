#ifndef ROIBLANC_H
#define ROIBLANC_H
#include "RoiNoir.h"


class RoiBlanc : virtual public RoiNoir
{
    public:
        RoiBlanc():RoiNoir(){colour="Blanc";};
        RoiBlanc(Position p) :RoiNoir(p){colour="Blanc";};
        void afficher()  {
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 15);
            std::cout << name ;
        }
        virtual ~RoiBlanc(){};

    protected:

    private:
};

#endif // ROIBLANC_H
