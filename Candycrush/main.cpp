//
//  main.cpp
//  Candycrush
//
//  Created by utilisateur on 22/10/2015.
//  Copyright © 2015 utilisateur. All rights reserved.
//

#include <iostream>
#include "Grille.hpp"
#include <curses.h>


using namespace std;

int main(int argc, const char * argv[])
{
    srand(time(0));
    Grille tableau;
    tableau.initialisation();


//Boucle pour une mise à jour de la console
	int i = 0;
	while (i >= 0)
{     
    
    cout<<tableau;
    //tableau.affiche(<#std::ostream &flux#>);
    tableau.pareil(0,0,tableau);
    

    
/*

    //Effacer l'écran de la console
	system("cls");
    system("clear"); //prb : ni le clear ni le cls ne marchent sur xcode...j'ai regardé sur internet et je n'ai pas réussi à me débloquer
    
    cout<<tableau;
    system("cls");
    system("clear");
    tableau.pareil(0,0,tableau);
    cout<<
 */
    
    
}



    return 0;
}











