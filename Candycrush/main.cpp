//
//  main.cpp
//  Candycrush
//
//  Created by utilisateur on 22/10/2015.
//  Copyright © 2015 utilisateur. All rights reserved.
//

#include <iostream>
#include "Grille.hpp"


using namespace std;

int main(int argc, const char * argv[])
{
    srand(time(0));
    Grille tableau;
    tableau.initialisation();
    cout<<tableau;
    //tableau.affiche(<#std::ostream &flux#>);
    cout<<endl;
    int i,j,k,l;
    cout<<"quelles cases voulez-vous échanger?"<<endl;
    cout<<"abscisse de la première case ?"<<endl;
    cin>>i;
    cout<<"ordonnée de la première case ?"<<endl;
    cin>>j;
    cout<<"abscisse de la deuxième case ?"<<endl;
    cin>>k;
    cout<<"ordonnée de la deuxième case ?"<<endl;
    cin>>l;
    tableau.inversion(i-1,j-1,k-1,l-1);
    //met à jour le tableau
    cout<<tableau;
    return 0;
}











