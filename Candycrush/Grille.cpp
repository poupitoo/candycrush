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



//parcours pour trouver les éléments identiques 2 à 2
void Grille::pareil(int i,int j, Grille tableau)
{
    
    int c(1);

      if (m_grille[i][j]==m_grille[i][j+1] and j<7)
      {
          c=c+1;
          pareilhorizontal(i,j+1,c, tableau);
      }
      
      if (m_grille[i][j]==m_grille[i+1][j] and i<7)
      {
          c=c+1;
          //pareilvertical(i+1,j,c);
      }
    
      if (j<7)
          {
              pareil(i,j+1, tableau);
          }
      if (i<7)
          {
              pareil(i+1,j, tableau);
          }
      if (c<3)
      {
        
        swipe(tableau);
        
      }

    
}


//si on a deux éléments horizontaux égaux
void Grille::pareilhorizontal(int i,int j, int c, Grille tableau)
{
    while (j<8 and i<8)
    {
        if (m_grille[i][j]!=m_grille[i][j+1])
        {
            pareil(i,j+1,tableau);
        }
        else
        {
            while (j<8 and m_grille[i][j]==m_grille[i][j+1])
            {
                c=c+1;
                j++;
            }
            combohorizontal(i,j,c);
            pareil(i+1,j,tableau);
            //la il faut optimiser pour éviter de tout reparcourir (par exemple commencer par le bas comme ca on a pas besoin de retraiter les lignes inférieures, mais la j'ai la flemme faudrait que je refasse tout :-), on verra ca plus tard)
        }
    }
}


//une fois qu'on a trois éléments identiques, on peut chercher ceux liés verticalements pour les détruires aussi
void Grille::combohorizontal(int i, int j, int c)
{
    int bonus=c;
    int numero;
    numero=m_grille[i][j];
    int l=i;
    int m=i;
    int derniereligne=i;
    int premiereligne=i;
    for (int k(j-c);k<j;k++)
    {
        derniereligne = max(l,derniereligne);
        premiereligne = min(m,premiereligne);
        m_grille[i][k]=0;
        while (m_grille[l][k]==m_grille[l+1][k] and l<=8)
        {
            bonus++;
            l++;
            m_grille[l][k]=0;
        }
        while (m_grille[m][k]==m_grille[m-1][k] and m>=0)
        {
            bonus++;
            m--;
            m_grille[m][k]=0;
        }
    }
    
    voisins(i,j-c,numero, derniereligne, premiereligne, c, bonus);
}


//une fois que t'as fait les liaisons verticales il faut continuer à chercher les voisins pour tout éliminer
void Grille::voisins(int i, int j,int numero, int derniereligne, int premiereligne, int c, int bonus)
{
    for (int l(j);l<j+c;l++)

        for (int m(premiereligne);m<derniereligne+1;m++)
        {
            if (m_grille[m][l]==0)
            {
              if (m_grille[m][l-1]==numero)
                {
                    bonus++;
                    voisinsg(m, l-1, numero, bonus);
                }
            }
            
        }
    //finir avec la derniere colonne : voisinsd
    //attention, dans voisinsd, il faudra aussi inclure des voisinsg si on a une forme bizarre, c'est possible
}

            
            
void Grille::voisinsg(int i, int j,int numero,int bonus)
{
    
    m_grille[i][j]=0;
    if (j==0)
    {
        if (i!=0)
        {
        if (m_grille[i-1][j]==numero)
        {
            bonus++;
            voisinsg(i-1, j, numero, bonus);
        }
        if (m_grille[i+1][j]==numero)
            {
                bonus++;
                voisinsg(i+1, j, numero, bonus);
            }
        }
        else
        {
            if (m_grille[i+1][j]==numero)
            {
                bonus++;
                voisinsg(i+1, j, numero, bonus);
            }

        }
    }
    else
    {
        if (i!=0)
            {
                if (m_grille[i-1][j]==numero)
                {
                    bonus++;
                    voisinsg(i-1, j, numero, bonus);
                }
                if (m_grille[i+1][j]==numero)
                {
                    bonus++;
                    voisinsg(i+1, j, numero, bonus);
                }
                if (m_grille[i][j-1]==numero)
                {
                    bonus++;
                    voisinsg(i, j-1, numero, bonus);
                }
            }
        else
        {
            if (m_grille[i+1][j]==numero)
            {
                bonus++;
                voisinsg(i+1, j, numero, bonus);
            }
            if (m_grille[i][j-1]==numero)
            {
                bonus++;
                voisinsg(i, j-1, numero, bonus);
            }

        }
    }
    
    
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

void swipe(Grille tableau)
{
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
//la il faut mettre un filtre pour qu'on ne puisse pas switcher deux trucs identiques
    tableau.inversion(i-1,j-1,k-1,l-1);
    cout<<tableau;
    tableau.pareil(0,0,tableau);
    system("cls");
    cout<<tableau;
    
    
}
