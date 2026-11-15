
import numpy as np
import pytest

import cum_mediane


def test_exemple_diapositive():
    donnees = np.array([2, 3, 0, 1, 5], dtype=float)
    medianes_attendues = np.array([2, 2.5, 2, 1.5, 2])

    medianes_obtenues = cum_mediane.cum_mediane(donnees)

    np.testing.assert_array_equal(
        medianes_obtenues,
        medianes_attendues,
    )


def test_donnees_repetees():
    donnees = np.array([2, 3, 2], dtype=float)

    with pytest.raises(RuntimeError, match="valeurs repetees"):
        cum_mediane.cum_mediane(donnees)


def test_une_seule_valeur():
    donnees = np.array([7.0])

    medianes_obtenues = cum_mediane.cum_mediane(donnees)

    np.testing.assert_array_equal(medianes_obtenues, donnees)


def test_tableau_vide():
    donnees = np.array([], dtype=float)

    with pytest.raises(ValueError, match="vide"):
        cum_mediane.cum_mediane(donnees)


def test_valeurs_non_finies():
    for valeur_invalide in [np.nan, np.inf, -np.inf]:
        donnees = np.array([2.0, valeur_invalide])

        with pytest.raises(ValueError, match="finies"):
            cum_mediane.cum_mediane(donnees)


def test_tableau_multidimensionnel():
    donnees = np.array([[2.0, 3.0], [0.0, 1.0]])

    with pytest.raises(ValueError, match="dimension"):
        cum_mediane.cum_mediane(donnees)
