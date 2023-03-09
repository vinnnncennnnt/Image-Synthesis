#include "../headers/raccordeurIteratif.hpp"

void RaccordeurIteratif::calculerCoupeAlgo(MatInt2 *e, int **E){
    int lignes = e->nLignes();
    int colonnes = e->nColonnes();

    //cas de base : pour i=0 on remplit la 1ere ligne de E avec les elements de la 1ere ligne de e
    for (int j = 0; j < colonnes; j++){
        E[0][j] = e->get(0,j);
    }
    //pour chaque ligne i+1 , on calcule Eij on se basant sur les elements de precedents [i-1,j-1], [i-1,j],[i-1,j+1]  
    for (int i = 1; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            if (j <= 0){
                E[i][j] = e->get(i,j) + std::min(E[i - 1][j], E[i - 1][j + 1]);
            }
            else if (j >= colonnes - 1) {
                E[i][j] = e->get(i,j) + std::min(E[i - 1][j - 1], E[i - 1][j]);
            }
            else{
                E[i][j] = e->get(i,j) + std::min(E[i - 1][j - 1], std::min(E[i - 1][j], E[i - 1][j + 1]));
            }
        }
    }
}

// cette fontion est pareil pour les trois versions 
// elle calcule la coupe optimale à partir d'un tableau E

int RaccordeurIteratif::calculerRaccord(MatInt2 *e, int *coupe)
{
    int coupeMini = 0;

    int **E = (int **)malloc(e->nLignes() * sizeof(int *));
    for (int i = 0; i < e->nLignes(); i++)
    {
        E[i] = (int *)malloc(e->nColonnes() * sizeof(int));
    }

    calculerCoupeAlgo(e, E) ;

    int indiceMin = 0;
    // trouver l'indice min de la dernière ligne
    int k = e->nLignes() - 1;
    for (int j = 0; j < e->nColonnes(); j++)
    {
        if (E[e->nLignes() - 1][j] < E[e->nLignes() - 1][indiceMin])
            indiceMin = j;
    }
    coupe[k--] = indiceMin;
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
        coupe[k--] = indiceMin;
    }

    for (int i = 0; i < e->nLignes(); i++)
    {
        free(E[i]);
    }
    free(E);

    return coupeMini;
}