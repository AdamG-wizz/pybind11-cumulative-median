
cum-mediane
===========

Package Python utilisant C++ pour calculer les medianes cumulatives.

Installation
------------

.. code-block:: bash

   pip install cum-mediane

Utilisation
-----------

.. code-block:: python

   import numpy as np
   import cum_mediane

   donnees = np.array([2, 3, 0, 1, 5], dtype=float)
   medianes = cum_mediane.cum_mediane(donnees)
   print(medianes)

Resultat attendu :

.. code-block:: text

   [2.  2.5 2.  1.5 2. ]

Documentation de la fonction
----------------------------

.. autofunction:: cum_mediane.cum_mediane
