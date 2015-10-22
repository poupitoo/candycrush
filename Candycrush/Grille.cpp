//
//  Grille.cpp
//  Candycrush
//
//  Created by utilisateur on 22/10/2015.
//  Copyright © 2015 utilisateur. All rights reserved.
//

#include "Grille.hpp"
#include <ctime>
#include <cstdlib>



using namespace std;


//COnstructeur
Grille::Grille()
{
}


//initialisation de la grille
void Grille::initialisation()
{
    int i,j;
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            m_grille[i][j]=aleatoire();
            
        }
    }
}



//affichage grille
void Grille::affiche(ostream &flux) const
{
    int i,j;
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            flux<<m_grille[i][j]<<" ";
            
        }
        flux<<endl;
    }
}

//inversion de deux cases

void Grille::inversion(int i, int j, int k, int l)
{
    int provisoire;
    provisoire=m_grille[i][j];
    m_grille[i][j]=m_grille[k][l];
    m_grille[k][l]=provisoire;
    
}




//en dehors de la classe


//création de l'opérateur << pour l'objet grille
ostream &operator<<( ostream &flux, Grille const& grille)
{
    grille.affiche(flux) ;
    return flux;
}



//génération aléatoire d'un nombre entre 1 et 4
int aleatoire()
{
    int nbAleatoire;
    nbAleatoire = rand() % 4;
    return nbAleatoire + 1;
}
