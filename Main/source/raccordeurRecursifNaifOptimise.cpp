#include "../headers/raccordeurRecursifNaifOptimise.hpp"

int RaccordeurRecursifNaifOptimise::calculerCoupeAlgo(int **tab, MatInt2 *e, int i, int j)
{
    if (tab[i][j] == -1)
    {
        int valeur = e->get(i, j);
        if (i == 0)
            tab[i][j] = valeur;
        else if (j <= 0)
            tab[i][j] = valeur + std::min(calculerCoupeAlgo(tab, e, i - 1, j), calculerCoupeAlgo(tab, e, i - 1, j + 1));
        else if (j >= e->nColonnes() - 1)
            tab[i][j] = valeur + std::min(calculerCoupeAlgo(tab, e, i - 1, j - 1), calculerCoupeAlgo(tab, e, i - 1, j));
        else
            tab[i][j] = valeur + std::min(calculerCoupeAlgo(tab, e, i - 1, j - 1), std::min(calculerCoupeAlgo(tab, e, i - 1, j), calculerCoupeAlgo(tab, e, i - 1, j + 1)));
    }

    return tab[i][j];
}

int RaccordeurRecursifNaifOptimise::calculerRaccord(MatInt2 *e, int *coupe)
{
    int coupeMini = 0;
    // tableau pour le E
    int **E = new int *[e->nLignes()];

    // tableau pour la fonction recursive
    int **tab = new int *[e->nLignes()];

    // allocation de memoire
    for (int i = 0; i < e->nLignes(); i++)
    {
        E[i] = new int[e->nColonnes()];
        tab[i] = new int[e->nColonnes()];
    }

    // initialisation du tableau pour les appels recursifs
    for (int i = 0; i < e->nLignes(); i++)
    {
        for (int j = 0; j < e->nColonnes(); j++)
        {
            tab[i][j] = -1;
        }
    }
    // remplire E

    for (int i = 0; i < e->nLignes(); i++)
    {
        for (int j = 0; j < e->nColonnes(); j++)
        {
            E[i][j] = calculerCoupeAlgo(tab, e, i, j);
        }
    }

    int indiceMin = 0;
    // trouver l'indice min de la dernière ligne

    for (int j = 0; j < e->nColonnes(); j++)
    {
        if (E[e->nLignes() - 1][j] < E[e->nLignes() - 1][indiceMin])
        {
            indiceMin = j;
        }
    }
    coupe[e->nLignes() - 1] = indiceMin;

    coupeMini = E[e->nLignes() - 1][indiceMin];

    for (int i = e->nLignes() - 2; i >= 0; i--)
    {
        int start = 0;
        int end = 0;
        if (indiceMin == 0)
        {
            start = 0;
            end = indiceMin + 1;
        }
        else if (indiceMin == e->nColonnes() - 1)
        {
            start = indiceMin - 1;
            end = e->nColonnes() - 1;
        }
        else
        {
            start = indiceMin - 1;
            end = indiceMin + 1;
        }

        indiceMin = start;
        for (int x = start; x <= end; x++)
        {
            if (E[i][x] < E[i][indiceMin])
            {
                indiceMin = x;
            }
        }
        coupe[i] = indiceMin;
    }

    for (int i = 0; i < e->nLignes(); i++) 
        {delete[] E[i];
        delete tab[i] ;}
    delete[] E;
    delete[] tab;


    return coupeMini;
}