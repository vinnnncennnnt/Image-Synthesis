#ifndef __RACCORDEUR_RECURSIF_NAIF_HPP__
#define __RACCORDEUR_RECURSIF_NAIF_HPP__

#include "raccordeur.h"
#include <stdio.h>
#include <algorithm>


class RaccordeurRecursifNaif : public Raccordeur {
    
   
    virtual ~RaccordeurRecursifNaif(){}; 
    virtual int calculerRaccord(MatInt2 *,  int *);

    private :
        int calculerCoupeAlgo(MatInt2 *, int, int) ;
};





#endif // __RACCORDEUR_RECURSIF_NAIF_HPP__
