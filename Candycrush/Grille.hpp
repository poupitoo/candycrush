//
//  Grille.hpp
//  Candycrush
//
//  Created by utilisateur on 22/10/2015.
//  Copyright © 2015 utilisateur. All rights reserved.
//

#ifndef Grille_hpp
#define Grille_hpp
#include <iostream>

#include <stdio.h>

class Grille
{
public:
    
    Grille();
    
    
    //initialisation de la grille
    void initialisation();
    
    //affichage grille
    void affiche(std::ostream &flux) const;
    
    
    //inversion de deux cases
    void inversion(int i, int j, int k, int l);
    
    //parcours du tableau pour trouver deux éléments identiques qui se suivent
    void pareil(int i, int j, Grille tableau);
    
    //parcours horizontal (si on a trouvé eux éléments identiques qui se suivaient horizontalement)
    void pareilhorizontal(int i,int j, int c, Grille tableau);
    
    //une fois qu'on a trois éléments identiques, on peut chercher ceux liés pour les détruires aussi
    void combohorizontal(int i, int j, int c);
    
    //voisins des 0
    void voisins(int i, int j, int numero, int derniereligne, int premiereligne, int c, int bonus);
    
    //voisins éloignés à gauche
    void voisinsg(int m, int j,int numero,int bonus);
    
    
private:
    int m_grille[8][8]; //tableau8x8
    
};


//opérateur <<
std::ostream &operator<<(std::ostream&flux, Grille const& grille);


//génération aléatoire d'un nombre entre 1 et 4
int aleatoire();

//swipe
void swipe(Grille tableau);


#endif /* Grille_hpp */
