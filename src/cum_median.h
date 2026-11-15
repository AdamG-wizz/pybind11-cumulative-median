
#ifndef CUM_MEDIANE_H
#define CUM_MEDIANE_H

#define SUCCESS 0
#define ERROR_DONNEES_REPETEES 1

int cum_mediane(
    const double* donnees_ptr,
    const int taille,
    double* sortie_ptr
);

#endif
