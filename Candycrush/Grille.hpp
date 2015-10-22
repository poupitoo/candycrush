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
    
    
    
private:
    int m_grille[8][8]; //tableau8x8
    
};


//opérateur <<
std::ostream &operator<<(std::ostream&flux, Grille const& grille);


//génération aléatoire d'un nombre entre 1 et 4
int aleatoire();


#endif /* Grille_hpp */
