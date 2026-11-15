
import os

from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

extensions = [
    Pybind11Extension(
        "cum_mediane",
        [
            "src/interface.cpp",
            "src/cum_mediane.cpp",
        ],
        cxx_std=17,
        extra_compile_args=["/O2", "/GL-"] if os.name == "nt" else [],
    ),
]

setup(
    name="cum-mediane",
    version="0.1.0",
    description="Calcul de medianes cumulatives en C++",
    ext_modules=extensions,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
    install_requires=["numpy"],
    zip_safe=False,
)
