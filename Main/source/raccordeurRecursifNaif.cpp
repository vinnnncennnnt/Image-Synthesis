#include "../headers/raccordeurRecursifNaif.hpp"



int RaccordeurRecursifNaif::calculerCoupeAlgo(MatInt2 *e, int i, int j)
{
    int valeur = e->get(i , j);
    if (i == 0)
        return valeur;
    else if (j <= 0)
        return valeur + std::min(calculerCoupeAlgo(e, i - 1, j), calculerCoupeAlgo(e, i - 1, j + 1));
    else if (j >= e->nColonnes() - 1)
        return valeur + std::min(calculerCoupeAlgo(e, i - 1, j - 1), calculerCoupeAlgo(e, i - 1, j));
    else
        return valeur + std::min(calculerCoupeAlgo(e, i - 1, j - 1), std::min(calculerCoupeAlgo(e, i - 1, j), calculerCoupeAlgo(e, i - 1, j + 1)));
}


 int RaccordeurRecursifNaif::calculerRaccord(MatInt2 *e,  int *coupe)
{
    int coupeMini = 0 ; // variable qui sera la valeur Emin
  
    int **E = new int *[e->nLignes()];  //allocation mémoire de E
    for (int i = 0; i < e->nLignes(); i++)
    {
        E[i] = new int[e->nColonnes()];
    }

    for (int i=0 ; i< e->nLignes() ; i++){
        for(int j=0 ; j< e->nColonnes() ; j++) { 
            E[j][i] = calculerCoupeAlgo(e, i , j) ;  //remplissage des valeurs
        }

    }


    int indiceMin = 0;
    // trouver l'indice min de la dernière ligne
    
    for (int j = 0; j < e->nColonnes() ; j++)
    {
        if (E[e->nLignes() - 1][j] < E[e->nLignes() - 1][indiceMin])
            indiceMin = j;
    }


    coupe[e->nLignes() - 1] = indiceMin;

    coupeMini = E[e->nLignes() - 1][indiceMin];

    // on cherche la coupe optimale on se deplacant en diagonale à droite, à gauche ou au dessus

    for (int i = e->nLignes() - 2; i >= 0; i--)
    {
        int start = 0;
        int end = 0;
        if (indiceMin == 0)
        {
            start = 0;
            end = indiceMin + 1;
        }
        else if (indiceMin == e->nColonnes()  - 1)
        {
            start = indiceMin - 1;
            end = e->nColonnes()  - 1;
        }
        else
        {
            start = indiceMin - 1;
            end = indiceMin + 1;
        }

        indiceMin = start;

        // On cherche l'indice min de j-1, j et j+1 de chaque valeur au dessus
        for (int x = start; x <= end; x++)
        {
            if (E[i][x] < E[i][indiceMin])
            {
                indiceMin = x;
            }
        }
        coupe[i] = indiceMin ;
    }


    for (int i=0 ; i< e->nLignes()  ; i++) {
        delete [] E[i];
    }
    delete [] E ;


    return coupeMini ;
}
