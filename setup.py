
import os
from pathlib import Path

from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

extensions = [
    Pybind11Extension(
        "cum_median",
        [
            "src/interface.cpp",
            "src/cum_median.cpp",
        ],
        cxx_std=17,
        extra_compile_args=(
            ["/O2", "/GL-"] if os.name == "nt" else []
        ),
    ),
]

setup(
    name="cum-median",
    version="0.1.1",
    description="Cumulative median computation using C++ and pybind11",
    long_description=Path("README.md").read_text(encoding="utf-8"),
    long_description_content_type="text/markdown",
    author="AdamG-wizz",
    url="https://github.com/AdamG-wizz/pybind11-cumulative-median",
    project_urls={
        "Documentation": (
            "https://pybind11-cumulative-median."
            "readthedocs.io/en/latest/"
        ),
        "Source": (
            "https://github.com/AdamG-wizz/"
            "pybind11-cumulative-median"
        ),
    },
    ext_modules=extensions,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
    install_requires=["numpy"],
    zip_safe=False,
)
