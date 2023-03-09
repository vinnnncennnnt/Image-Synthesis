#ifndef __RACCORDEUR_RECURSIF_OPTIMISE_NAIF_HPP__
#define __RACCORDEUR_RECURSIF_OPTIMISE_NAIF_HPP__

#include "raccordeur.h"
#include <stdio.h>
#include <algorithm>


class RaccordeurRecursifNaifOptimise : public Raccordeur {
    
   
    virtual ~RaccordeurRecursifNaifOptimise(){}; 
    virtual int calculerRaccord(MatInt2 *,  int *);

    private :
        int calculerCoupeAlgo(int**tab ,MatInt2 *, int, int) ;
};





#endif // __RACCORDEUR_RECURSIF_NAIF_HPP__
