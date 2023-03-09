#ifndef __RACCORDEUR_ITERATIF_HPP__
#define __RACCORDEUR_ITERATIF_HPP__

#include "raccordeur.h"
#include <stdio.h>
#include <algorithm>


class RaccordeurIteratif : public Raccordeur {
    
   
    virtual ~RaccordeurIteratif(){}; 
    virtual int calculerRaccord(MatInt2 *,  int *);

    private :
        void calculerCoupeAlgo(MatInt2 *, int **) ;
};





#endif // __RACCORDEUR_ITERATIF_HPP__
