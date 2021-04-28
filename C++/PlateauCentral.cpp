#include "PlateauCentral.h"


using namespace std;

    //constructeur
    PlateauCentral::PlateauCentral(){
        for(int i=0;i<7;i++){
            for(int j=0;j<6;j++){
                listeTuileCentrale[i][j]="";
            }
        }
    }

    //destructeur
    PlateauCentral::~PlateauCentral(){}

    //methode

    void PlateauCentral::recupPlateau()
    {
        ifstream monFlux("../Donnes/marche.txt");  //Ouverture d'un fichier en lecture
        if(monFlux)
        {
            //Tout est pr�t pour la lecture.
            cout<<"fichier ouvert"<<endl;

            string ligne;

            while(getline(monFlux, ligne)) //Tant qu'on n'est pas � la fin, on lit
              {
                if(ligne.compare("tuile_centrale:")==0) //on lit le tableau du plateau commun
                {
                    for(int i=0;i<7;i++)
                    {
                        getline(monFlux, ligne);

                        istringstream iss( ligne );
                        string morceau;
                        //string resultat;

                        while (getline(iss, morceau, ',' ) )//on decoupe les lignes du doc
                        {
                            //mise en forme des donnees
                            if(morceau.compare("[]")!=0)
                            {
                                //cout<<morceau<<endl;
                                int colonne=0;

                                int taille=morceau.size();
                                //cout<<taille<<endl;

                                if(morceau.at(0)=='[')
                                {
                                    morceau.erase(0,1);
                                    //cout<<morceau<<endl;

                                }

                                else if(morceau.at(taille-1)==']')
                                {

                                    morceau.erase(taille-1,1);

                                }
                                //cout<<"test"<<endl;




                                if(morceau.at(0)==' '){
                                    morceau.erase(0,1);
                                }

                                morceau.erase(0,1);
                                morceau.erase(morceau.size()-1,1);

                                //cout<<"le morceau coupe: "<<morceau<<endl;

                                //fin de la mise en forme

                                if(morceau.at(0)=='m')
                                {
                                    while(listeTuileCentrale[i][colonne].compare("")!=0)
                                    {
                                        colonne=colonne+1;
                                    }
                                    listeTuileCentrale[i][colonne]=morceau;
                                }

                                if(morceau.at(0)=='t')
                                {
                                    if(listeTuileCentrale[i][4].compare("")==0){
                                        listeTuileCentrale[i][4]=morceau;
                                    }
                                    else{
                                        listeTuileCentrale[i][5]=morceau;
                                    }
                                }
                            }


                        }

                        //listeTuileCentrale[i]=ligne;

                        for (int col=0;col<6;col++){
                            cout<<listeTuileCentrale[i][col];
                        }
                        cout<<endl;

                    }


                }

                if(ligne.compare("pions:")==0){
                    getline(monFlux, ligne);
                    //cout<<ligne<<endl;
                    istringstream iss( ligne );
                    string morceau;
                    int test=0;
                    while (getline(iss, morceau, ',' ) )//on decoupe les lignes du doc
                    {
                        if(test==2)//on veut recuperer que le 3eme morceau pour avoir le joueur
                        {
                            string resultat;
                            morceau.erase(0,3);
                            morceau.erase(morceau.size()-2,2);
                            resultat=morceau;
                            if(resultat.compare("0")==0){
                                premierajouer=1;
                                deuxiemeajouer=2;
                            }
                            else{
                                premierajouer=2;
                                deuxiemeajouer=1;
                            }
                            //cout<<resultat<<endl;
                            //cout<<"1er joueur: "<<premierajouer<<endl;
                            //cout<<"2eme joueur: "<<deuxiemeajouer<<endl;

                        }
                        test=test+1;
                    }

                }
              }

            //affichage test
            //cout<<listeTuileCentrale[0]<<listeTuileCentrale[1]<<endl;
            //on ferme le fichier
            monFlux.close();
            cout<<"fichier ferme"<<endl;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }

    int PlateauCentral::recupJoueur(int i){
        int Joueur;
        if(i==1){
            Joueur=premierajouer;
        }
        else{
            Joueur=deuxiemeajouer;
        }
        return Joueur;
    }

    string PlateauCentral::getTuileMarche(int i,int j){
        string tuile=listeTuileCentrale[i][j];
        return tuile;
    }
