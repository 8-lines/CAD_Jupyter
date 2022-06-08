# CAD_Jupyter
A Multiuser CAE solution including CAD-to-FEM workflow and live in-browser 3d previews. Docker based, Python3 Focused utilizing Conda, CadQuery, FEniCS, PETSc, TopOpt, PythonOCC, JupyterHub, JupyterLab.

This is ***a local team environment*** meaning one file system for all instance users. An instance is contained inside a docker container (so only folders that you explicitly provide will be visible to it). 

Environment includes:
 - **CAD** tools: *pythonocc-core* and *GMSH*
 - **FEM** tools: *FEniCSx* and *PETSc*
 - **Optimization** tools: *TopOpt*
 - **Visualization** tools: *JupyterLab*

Note that as any real CAE software docker image file is big and requires at least **17GB** and needs more than **1 hour** for installation.

# Install

## Interface

1) get code:
```bash
git clone --recursive https://github.com/8-lines/CAD_Jupyter
cd CAD_Jupyter/
```
2) start building as a detached process:
```bash
nohup docker build -t spbu/cae:latest --squash . > build-logs.out 2>&1&
```
3) build takes time (1h+).
4) check build-logs.out:
```bash
tail build-logs.out
```
5) when build process have finished you shall see something like:
```bash
Removing intermediate container dccc972021d9
---> 513eafc3124f
Successfully built 3b4292862131
Successfully tagged spbu/cae:latest
```
6) start
on 0.0.0.0 (localhost and public IP if node has one) 
on port 8890 (port can be changed)
with admin user password `Scientific`
```bash
 docker run -d -p 8890:8892  -e USER_PASS=Scientific -d /full/path/to/a/shared/folder:/opt/notebook/ spbu/cae:latest
```

## FEniCS

1) First check that Docker is working:
```bash
docker run hello-world
```

You should see a message saying that your Docker installation is working correctly.

2) Pull the quay.io/fenicsproject/stable image:
```bash
docker pull quay.io/fenicsproject/stable:latest
```

3) Start FEniCS, run:
```bash
docker run -ti quay.io/fenicsproject/stable:latest
```
4) You will be presented with a prompt where you can run FEniCS:
```bash
fenics@0521831b5f28:~$
```
fenics is your username inside the container and the number 0521831b5f28 is the CONTAINER ID that Docker has assigned. This ID is unique to your computer and this container and will be different to the one above.

5) Run the DOLFIN poisson.py example using:
```bash
cd ~/demo/documented/poisson/python
python3 demo_poisson.py
```
The results will be outputted to the file poisson.pvd in the same directory. 

## PETSc

1) Enter the PETSc directory:
```bash
cd PETSc/
```

2) Install and configure (MPI and BLAS/LAPACK should already be installed):
```bash
./configure
make all check
```

## TopOpt

1) This code requires the following external software to work:

 - PETSc version 3.11.4 or earlier (though never than 3.8.x)
 - LAPACK/BLAS
 - MPI

2) Compile following rules in makefile_ref

3) Normal compilation time of framework, e.g. 4s: "make topopt -j"

4) Run the base example by typing e.g.: "mpirun -np 4 ./topopt"

## Login
On navigating to it you shall see login screen:
Enter `admin` as login with `Scientific` password - this will bring you to the JupiterLab

## Add a new user
1) Login into an administrator
2) Go to `/tree` view (url like ``) open 
3) Add user to JupyterHub (needed for abilety to login)
4) Open a new termnal
5) Add system user (needed for shared folder access)
```bash
sudo useradd --create-home --no-log-init --shell /bin/bash -g users test 
```
6) Provide user with login and JupyterHub website addres. On his first entrence what ever he will write as a `password` will be saved as his password.

## Cite Articles
 - [Development of a tool for interactive detailing of areas of objects for the strength modeling system. / Budlov E., Iakushkin O., Sedova O., Gogotov A.](http://ceur-ws.org/Vol-3041/101-105-paper-18.pdf) (OpenAccess)
 - [Creating A Tool For Stress Computation With Respect To Surface Defects. / Sedova, O.; Iakushkin O.; Kondratiuk. A.](http://ceur-ws.org/Vol-2507/371-375-paper-68.pdf) (OpenAccess)
 - [Jupyter extension for creating CAD designs and their subsequent analysis by the finite element method. / Iakushkin, O.; Sedova, O.; Grishkin, V. In: CEUR Workshop Proceedings, Vol. 1787, 2016, p. 530-534.](http://ceur-ws.org/Vol-1787/530-534-paper-92.pdf) (OpenAccess)
 - [Creating CAD designs and performing their subsequent analysis using opensource solutions in Python. / Iakushkin, Oleg O.; Sedova, Olga S. In AIP Computer Methods in Mechanics, CMM 2017: Proceedings of the 22nd International Conference on Computer Methods in Mechanics. Vol. 1922 American Institute of Physics, 2018. 140011.](https://aip.scitation.org/doi/abs/10.1063/1.5019153)

## License
CAD_Jupyter is first of all a preconfigured environment combining a wide set of OpenSource Python and C++ Packages, we encourage you to view their various License files. 

CAD_Jupyter provides Sample files and Utilities combining CAD, Meshing, FEM and other CAE required activities. We distribute them under MIT license
