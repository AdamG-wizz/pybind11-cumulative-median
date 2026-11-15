
#include "cum_mediane.h"

#include <iterator>
#include <set>

int cum_mediane(
    const double* donnees_ptr,
    const int taille,
    double* sortie_ptr
) {
    std::set<double> valeurs_triees;
    std::set<double>::iterator mediane_it;

    for (int indice = 0; indice < taille; ++indice) {
        const double valeur = donnees_ptr[indice];
        const auto insertion = valeurs_triees.insert(valeur);

        if (!insertion.second) {
            return ERROR_DONNEES_REPETEES;
        }

        if (indice == 0) {
            mediane_it = insertion.first;
        } else if (valeurs_triees.size() % 2 == 0) {
            if (valeur < *mediane_it) {
                --mediane_it;
            }
        } else if (valeur > *mediane_it) {
            ++mediane_it;
        }

        if (valeurs_triees.size() % 2 == 0) {
            const auto suivant_it = std::next(mediane_it);
            sortie_ptr[indice] =
                *mediane_it / 2.0 + *suivant_it / 2.0;
        } else {
            sortie_ptr[indice] = *mediane_it;
        }
    }

    return SUCCESS;
}
