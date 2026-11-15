
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <cmath>
#include <limits>
#include <stdexcept>

#include "cum_mediane.h"

namespace py = pybind11;

py::array_t<double> cum_mediane_python(
    py::array_t<double, py::array::c_style |
                        py::array::forcecast> donnees
) {
    const py::buffer_info entree = donnees.request();

    if (entree.ndim != 1) {
        throw std::invalid_argument(
            "Les donnees doivent avoir une dimension"
        );
    }

    if (entree.size == 0) {
        throw std::invalid_argument(
            "Le tableau ne doit pas etre vide"
        );
    }

    if (entree.size > std::numeric_limits<int>::max()) {
        throw std::invalid_argument(
            "Le tableau contient trop de valeurs"
        );
    }

    const auto* donnees_ptr =
        static_cast<const double*>(entree.ptr);

    for (py::ssize_t indice = 0; indice < entree.size; ++indice) {
        if (!std::isfinite(donnees_ptr[indice])) {
            throw std::invalid_argument(
                "Les donnees doivent etre finies"
            );
        }
    }

    py::array_t<double> sortie(entree.size);
    const py::buffer_info resultat = sortie.request();
    auto* sortie_ptr = static_cast<double*>(resultat.ptr);

    const int statut = cum_mediane(
        donnees_ptr,
        static_cast<int>(entree.size),
        sortie_ptr
    );

    if (statut == ERROR_DONNEES_REPETEES) {
        throw std::runtime_error(
            "Les donnees contiennent des valeurs repetees"
        );
    }

    if (statut != SUCCESS) {
        throw std::runtime_error(
            "Le calcul de la mediane cumulative a echoue"
        );
    }

    return sortie;
}



PYBIND11_MODULE(cum_mediane, module) {
    module.def(
        "cum_mediane",
        &cum_mediane_python,
        py::arg("donnees"),
        R"doc(
Calculer les medianes cumulatives.

Parameters
----------
donnees : numpy.ndarray
    Tableau unidimensionnel de valeurs finies et distinctes.

Returns
-------
numpy.ndarray
    Mediane cumulative apres chaque insertion.

Raises
------
ValueError
    Si les donnees sont invalides.
RuntimeError
    Si les donnees contiennent des doublons.
)doc"
    );
}
