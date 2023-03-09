#include <algorithm>
#include <random>
#include "../headers/permuteur.h"
using namespace std;

Permuteur::Permuteur(int max)
{
    this->max=max;
    this->indices = (int*)malloc(max*sizeof(int));
    this->perm = (int*)malloc(max*sizeof(int));
    this->i_perm=0;


    for (int i =0 ; i < max ; i++){
      indices[i]=i;
      perm[i]=i;
    }

    for (int i=0; i<max; i++) {
      int r=rand()%(max-i);
      int c=perm[r];
      perm[r]=perm[i];
      perm[i]=c;
    }
    for (int i =0 ; i < max ; i++){
      fprintf(stdout, "case  : %d retourne %d\n",i,perm[i]);
    }
}

int Permuteur::suivant()
{
  if(this->i_perm==this->max){
    for (int i=0; i<this->max; i++) {
      int r=rand()%(this->max-i);
      int c=this->perm[r];
      this->perm[r]=this->perm[i];
      this->perm[i]=c;
    }
    this->i_perm=0;
  }
  return this->perm[this->i_perm++];
}

Permuteur::~Permuteur()
{
  free(this->indices);
  free(this->perm);
}