#ifndef CHESSGAME_H
#define CHESSGAME_H
#include "PionNoir.h"
#include "TourNoir.h"
#include "FouNoir.h"
#include "ChevalNoir.h"
#include "RoiNoir.h"
#include "DameNoir.h"
#include "DameBlanc.h"
#include "RoiBlanc.h"
#include "PionBlanc.h"
#include "FouBlanc.h"
#include "TourBlanc.h"
#include  "ChevalBlanc.h"

class ChessGame
{
    public:
        ChessGame() {

            deplacementRoiNoir=0;
            deplacementRoiBlanc=0;
            deplacementTourBlancDroit=0;
            deplacementTourBlancGauche=0;
            deplacementTourNoirDroit=0;
            deplacementTourNoirGauche=0;
            for (int i=0;i<8;i++) {
                ligne.push_back(NULL);
            }
            for (int i=0;i<8;i++) {
                ensemblePieces.push_back(ligne);
            }
            ensemblePieces[0][0]=new TourNoir(Position('a',8));
            ensemblePieces[0][1]=new ChevalNoir(Position('b',8));
            ensemblePieces[0][2]=new FouNoir(Position('c',8));
            ensemblePieces[0][3]=new DameNoir(Position('d',8));
            ensemblePieces[0][4]=new RoiNoir(Position('e',8));
            ensemblePieces[0][5]=new FouNoir(Position('f',8));
            ensemblePieces[0][6]=new ChevalNoir(Position('g',8));
            ensemblePieces[0][7]=new TourNoir(Position('h',8));
            for (int i=0;i<8;i++) {
                ensemblePieces[1][i]=new PionNoir(Position(char('a'+i),7));
            }
            for (int i=2;i<6;i++) {
                for (int j=0;j<8;j++){
                    ensemblePieces[i][j]=NULL ;
                }
            }
            for (int i=0;i<8;i++) {
                ensemblePieces[6][i]=new PionBlanc(Position(char('a'+i),2));
            }
             ensemblePieces[7][0]=new TourBlanc(Position('a',1));
            ensemblePieces[7][1]=new ChevalBlanc(Position('b',1));
            ensemblePieces[7][2]=new FouBlanc(Position('c',1));
            ensemblePieces[7][3]=new DameBlanc(Position('d',1));
            ensemblePieces[7][4]=new RoiBlanc(Position('e',1));
            ensemblePieces[7][5]=new FouBlanc(Position('f',1));
            ensemblePieces[7][6]=new ChevalBlanc(Position('g',1));
            ensemblePieces[7][7]=new TourBlanc(Position('h',1));
            for(int i=0;i<2;i++){
                    for(int j=0;j<8;j++){
                        piecesNoir.push_back(ensemblePieces[i][j]);
                        piecesBlanc.push_back(ensemblePieces[7-i][j]);
            }


        }
        };

      void  afficher(){
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 8);
            std::cout<< "   : a : b : c : d : e : f : g : h :   \n";
            std::cout <<"_____________________________________\n";
            for (int i=0;i<8;i++) {
                HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(color, 8);
                std::cout << 8-i << "  : ";
                for (int j=0;j<8;j++) {
                        if(ensemblePieces[i][j]) {
                            ensemblePieces[i][j]->afficher();
                            std :: cout << " : " ;

                        }
                        else {
                                HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
                                SetConsoleTextAttribute(color, 8);
                            std :: cout << "  : " ;
                        }
                }
                SetConsoleTextAttribute(color, 8);
                std::cout << 8-i << " :\n\n";
            }
            SetConsoleTextAttribute(color, 8);
            std::cout <<"_____________________________________\n";
            std::cout<< "   : a : b : c : d : e : f : g : h :   \n";


        };
        void startGame () {
            std::string positionDepart , positionArivee ;
            afficher();
            std::cout << "Le nom de premier joueur ( Pieces Blanches )  : " ; std:: cin >> joueur1 ; std::cout << "\n" ;
            std::cout << "Le nom de deuxieme joueur ( Pieces noires ) : " ; std:: cin >> joueur2 ; std::cout << "\n" ;
            std:: cout << "---------------Debut de la partie -------------------" ; std::cout << "\n" ;
            while (!echecMateRoiBlanc() && !echecMateRoiNoir()) {
                bool mouvementImpossible=true ;
                while (mouvementImpossible){
                    std:: cout << getNomJoueur1() ;std::cout << " : Deplacement de " ; std ::cin >> positionDepart ; std::cout << " à " ; std ::cin >> positionArivee ; std::cout << "\n" ;
                    char h1 = positionDepart[0]; char h2 = positionArivee[0] ;
                    int v1 = (int) (positionDepart[1]-'0') ;int v2 = (int) (positionArivee[1]-'0') ;
                    Position pos1 = Position(h1,v1);
                    Position pos2 = Position(h2,v2);
                    if (pos1.verifPosition()&& pos2.verifPosition()&&verifDeplacement(getPieceByPosition(pos1),po2)) {

                    }

                }

            }







        }
        std::string getNomJoueur1() {
            return joueur1;
        }
        std::string getNomJoueur2() {
            return joueur2;
        }

        void setNomJoueur1 (std::string nom ){
            joueur1=nom ;

        }
        void setNomJoueur2 (std::string nom ){
            joueur2=nom ;

        }
        bool echecMateRoiNoir() {
            Position p = getPositionRoiNoir() ;
            bool mate=false ;
            if (echecRoiNoir()){
                if (!verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV())) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV())) && !verifDeplacement(getPieceByPosition(p),Position(p.getH(),p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH(),p.getV()-1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV()-1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV()-1)) )  {
                        mate = true ;
                }
            }
            return mate ;



        }
        bool echecMateRoiBlanc() {
            Position p = getPositionRoiBlanc() ;
            bool mate=false ;
            if (echecRoiBlanc()){
                if (!verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV())) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV())) && !verifDeplacement(getPieceByPosition(p),Position(p.getH(),p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH(),p.getV()-1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV()+1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()+1,p.getV()-1)) && !verifDeplacement(getPieceByPosition(p),Position(p.getH()-1,p.getV()-1)) )  {
                        mate = true ;
                }
            }
            return mate ;



        }
        bool echecRoiNoir(){
           bool echec=false;
            for(int i=0;i<piecesBlanc.size()&&!echec;i++){
                if (verifDeplacement(piecesBlanc[i],getPositionRoiNoir())) {
                    echec=true;


                }

            }
            return echec ;


        }
       bool echecRoiBlanc(){
           bool echec=false;
            for(int i=0;i<piecesNoir.size()&&!echec;i++){
                if (verifDeplacement(piecesNoir[i],getPositionRoiBlanc())) {
                    echec=true;


                }

            }
            return echec ;


        }

        Position getPositionRoiNoir(){
            for(int i=0;i<piecesNoir.size();i++){
                if(piecesNoir[i]->getNom()=="roi") {
                    return piecesNoir[i]->getPosition();
                }
            }

        }
        Position getPositionRoiBlanc(){
            for(int i=0;i<piecesBlanc.size();i++){
                if(piecesBlanc[i]->getNom()=="roi") {
                    return piecesBlanc[i]->getPosition();
                }
            }

        }
        std::vector <std::vector <Piece*> > getEnsemblePieces() {
            return ensemblePieces ;
        };
          std::vector <Piece*> getPiecesBlanc() {
            return piecesBlanc;
        };
        std::vector <Piece*> getPiecesNoir() {
            return piecesNoir;
        };
        Piece* getPieceByPosition(Position p){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(ensemblePieces[i][j]){
                        if(ensemblePieces[i][j]->getPosition().egale(p)){
                            return ensemblePieces[i][j];
                        }
                    }

                }
            }
            return NULL ;
        }
        bool verifAttackPionNoir(Piece* pn){
            bool t=false;
            Position p1(char(pn->getPosition().getH()+1),pn->getPosition().getV()-1);
            Position p2(char(pn->getPosition().getH()-1),pn->getPosition().getV()-1);
            if(p1.verifPosition()){
                if(getPieceByPosition(p1) && getPieceByPosition(p1)->getCouleur()=="Blanc"){
                    t=true;
                }
            }
            if(p2.verifPosition()){
                if(getPieceByPosition(p2) &&  getPieceByPosition(p1)->getCouleur()=="Blanc"){
                    t=true;
                }
            }
            if(t){
                pn->setPeutAttaquer(true);
            }
            else pn->setPeutAttaquer(false);
            return t ;
        }
        bool verifAttackPionBlanc(Piece* pn){
            bool t=false;
            Position p1(char(pn->getPosition().getH()+1),pn->getPosition().getV()+1);
            Position p2(char(pn->getPosition().getH()-1),pn->getPosition().getV()+1);
            if(p1.verifPosition()){
                if(getPieceByPosition(p1) && getPieceByPosition(p1)->getCouleur()=="Noir"){
                    t=true;
                }
            }
            if(p2.verifPosition() && getPieceByPosition(p1)->getCouleur()=="Noir"){
                if(getPieceByPosition(p2)){
                    t=true;
                }
            }
            if(t){
                pn->setPeutAttaquer(true);
            }
            else pn->setPeutAttaquer(false);
            return t ;
        }
        bool verifDeplacement(Piece* piece,Position p){
            bool t=false ; int s=0;
//verification de deplacement de pieces noires
                if(piece->getCouleur()=="Noir" ){
//verification de deplacement de pion noir
                    if(piece->getNom()=="pion"){
                            verifAttackPionNoir(piece);
                            if(verifAttackPionNoir(piece)&&piece->verifMove(p)&&piece->getPosition().getH()!=p.getH()){
                                t=true;
                            }
                            else if(piece->verifMove(p)&&piece->getPosition().getH()==p.getH()){
                                if(getPieceByPosition(p)==NULL){
                                    t=true;
                                }
                            }

                    }
//verification de deplacement de cheval noir
                    if(piece->getNom()=="cheval"){
                        if(piece->verifMove(p) ){
                                {
                                    if (getPieceByPosition(p)==NULL) {
                                        return true ;
                                    }
                                    else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                        return true ;
                                    }
                                }
                        }
                    }
//verification de deplacement de tour noire
                    if (piece->getNom()=="tour" && piece->verifMove(p) ) {
                            if(piece->getPosition().getH()==p.getH()){
                                if(piece->getPosition().getV()>p.getV()){

                                    for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()-j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getV()<p.getV()){
                                    for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()+j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }
                            }
                            if(piece->getPosition().getH()!=p.getH()){
                                if(piece->getPosition().getH()>p.getH()){

                                    for(int j=1;j<piece->getPosition().getH()-p.getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()-j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getH()<p.getH()){
                                    for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()+j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }



                            }

                    }
////verification de deplacement de fou noir
                    if (piece->getNom()=="fou" && piece->verifMove(p) ){
                        if(p.getH()>piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()<piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                          if(p.getH()<piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()>piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }



                    }
//verification de deplacement de dame noire
                    if (piece->getNom()=="dame" && piece->verifMove(p) ){

                            if(piece->getPosition().getH()==p.getH()){
                                if(piece->getPosition().getV()>p.getV()){

                                    for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()-j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getV()<p.getV()){
                                    for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()+j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }
                            }
                            if(piece->getPosition().getH()!=p.getH()){
                                if(piece->getPosition().getH()>p.getH()){

                                    for(int j=1;j<piece->getPosition().getH()-p.getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()-j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getH()<p.getH()){
                                    for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()+j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }



                            }



                            //critere-fou
                        if(p.getH()>piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()<piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                          if(p.getH()<piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()>piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Blanc") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }





                    }
//verification de deplacement de roi noir
                    if(piece->getNom()=="roi"){

                            if(piece->verifMove(p)&&(getPieceByPosition(p)->getCouleur()=="Blanc" || getPieceByPosition(p)==NULL )){
                                return true ;

                            }


                    }


                }
//verification de deplacement de pieces blancs//////////////////////////////////////////////////////////////////////
                if(piece->getCouleur()=="Blanc" ){
//verification de deplacement de pion blanc
                    if(piece->getNom()=="pion"){
                            verifAttackPionBlanc(piece);
                            if(verifAttackPionBlanc(piece)&&piece->verifMove(p)&&piece->getPosition().getH()!=p.getH()){
                                t=true;
                            }
                            else if(piece->verifMove(p)&&piece->getPosition().getH()==p.getH()){
                                if(getPieceByPosition(p)==NULL){
                                    t=true;
                                }
                            }

                    }
//verification de deplacement de cheval blanc
                    if(piece->getNom()=="cheval"){
                        if(piece->verifMove(p) ){
                                {
                                    if (getPieceByPosition(p)==NULL) {
                                        return true ;
                                    }
                                    else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                        return true ;
                                    }
                                }
                        }
                    }
//verification de deplacement de tour blanche
                    if (piece->getNom()=="tour" && piece->verifMove(p) ) {
                            if(piece->getPosition().getH()==p.getH()){
                                if(piece->getPosition().getV()>p.getV()){

                                    for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()-j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getV()<p.getV()){
                                    for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()+j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }
                            }
                            if(piece->getPosition().getH()!=p.getH()){
                                if(piece->getPosition().getH()>p.getH()){

                                    for(int j=1;j<piece->getPosition().getH()-p.getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()-j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getH()<p.getH()){
                                    for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()+j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }



                            }

                    }
////verification de deplacement de fou blanc
                    if (piece->getNom()=="fou" && piece->verifMove(p) ){
                        if(p.getH()>piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()<piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                          if(p.getH()<piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()>piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }



                    }
//verification de deplacement de dame Blanche
                    if (piece->getNom()=="dame" && piece->verifMove(p) ){

                            if(piece->getPosition().getH()==p.getH()){
                                if(piece->getPosition().getV()>p.getV()){

                                    for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()-j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getV()<p.getV()){
                                    for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                        if (getPieceByPosition(Position(p.getH(),piece->getPosition().getV()+j))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }
                            }
                            if(piece->getPosition().getH()!=p.getH()){
                                if(piece->getPosition().getH()>p.getH()){

                                    for(int j=1;j<piece->getPosition().getH()-p.getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()-j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                                }
                                if(piece->getPosition().getH()<p.getH()){
                                    for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                        if (getPieceByPosition(Position(char(piece->getPosition().getH()+j),p.getV()))){
                                            s++;
                                        }
                                    }
                                    if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;

                                }



                            }



                            //critere-fou
                        if(p.getH()>piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getH()-piece->getPosition().getH();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()<piece->getPosition().getH()&&p.getV()>piece->getPosition().getV()){
                            for(int j=1;j<p.getV()-piece->getPosition().getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()-1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                          if(p.getH()<piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()+1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }
                        if(p.getH()>piece->getPosition().getH()&&p.getV()<piece->getPosition().getV()){
                            for(int j=1;j<piece->getPosition().getV()-p.getV();j++){
                                if(getPieceByPosition(Position(char(p.getH()-1),p.getV()+1))){
                                    s++;
                                }
                            }
                             if (!s){
                                            if (getPieceByPosition(p)==NULL) {
                                                return true ;
                                            }
                                            else if (getPieceByPosition(p)->getCouleur()=="Noir") {
                                                return true ;
                                            }

                                    }
                                    s=0;
                        }





                    }
//verification de deplacement de roi blanc
                    if(piece->getNom()=="roi"){

                            if(piece->verifMove(p)&&(getPieceByPosition(p)->getCouleur()=="Noir" || getPieceByPosition(p)==NULL )){
                                return true ;

                            }


                    }


                }
                return false ;



            }



        virtual ~ChessGame(){
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++){
                        if(ensemblePieces[i][j])
                            delete(ensemblePieces[i][j]) ;

                }

            }
            for(int j=0;piecesBlanc.size();j++){
                        if(piecesBlanc[j])
                            delete(piecesBlanc[j]) ;


                }
                for(int j=0;piecesNoir.size();j++){
                        if(piecesBlanc[j])
                            delete(piecesNoir[j]) ;


                }


        };
    protected:

        int deplacementRoiNoir;
        int deplacementRoiBlanc;
        int deplacementTourBlancDroit;
        int deplacementTourBlancGauche;
        int deplacementTourNoirDroit;
        int deplacementTourNoirGauche;
        std::string joueur1,joueur2 ;
        std::vector <Piece*> ligne ;
        std::vector <Piece*> piecesBlanc ;
        std::vector <Piece*> piecesNoir ;
        std::vector <std::vector <Piece*> > ensemblePieces;//={{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}} ;
    private:
};

#endif // CHESSGAME_H
