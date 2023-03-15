Task A1 - Inspect basic example B1
==================================

- Build and run example B1:
```
mkdir $HOME/geant4
cd $HOME/geant4
cp -r $G4EXAMPLES/basic/B1 .
cd B1
mkdir build; cd build
cmake ..
make -j4
./exampleB1
```

We are running example B1 interactively.  We can explore a few simple comands

```
/run/initialize
/run/beamOn 1
```
and to get basic information about what happens to each track at every step
```
/tracking/verbose 1
/run/beamOn 1
```

- Inspect structure of directories and their contents
We examine the key files required for a simple Geant4 application
```
cd $HOME/geant4/B1
ls -F
ls -F include
ls -F src
```

- Analysis of main() program
We will briefly go over the key elements of a simple Geant4 application's 'main()' function.

- Analysis of B1DetectorConstruction class:
```
gedit include/B1DetectorConstruction.hh src/B1DetectorConstruction.cc
nedit */B1DetectorConstruction.*
```

- More interactive commands

We explore a few additional interactive commands. To find available commands:
```
ls
help
```
Some interrogate the (optional) particle gun that generates primaries in B1:
```
cd /gun
?particle
?energy
?position
?direction
particle e-
energy   10 MeV
cd /
```
we then set them again using the full command 'directory' path
```
cd /
/gun/particle e+
/gun/energy 100 MeV
/gun/position -1.0 0.0 0.0 mm
/gun/direction   1. 0.  0.
```
