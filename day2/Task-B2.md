Material: Hands-on
==================

We will keep using the source code in exDay2/ in these exercises.
The goal is to exercise the different ways to create material in Geant4.

Exercise 1.
-----------
Run the application in interactive mode. Use the NIST data base:
- a. print (isotopes, composition, etc) the "Al" element entry
- b. print the list of pre-defined NIST "bio" materials:
  
Exercise 2.  
-----------
From now on, we will use the application in batch mode. 

- a. Identify and investigate the material definitions in the B1 application B1DetectorConstruction::Construct() method!
- b. Print the Envelope material with all its properties (use G4cout)!
- c. Change the Envelope material from Water to liquid Argon using the NIST material data base.
- d. Define your own Water material instead of the predefined NIST one (see   slide #9) and use it as the Envelop material.
 
Exercise 3.  
-----------
We will create Uranium material in 3 different ways then we will compare their 
properties by printing them out (in B1DetectorConstruction::Construct() method):
- a. Create the pre-defined NIST Uranium material (see slide #15)! 
- b. Create Uranium material as simple (single element) material with natural  isotope abundance using the appropriate G4Material constructor with: "name="

```
name = "Natural U mat", atomic number = 92, molar mass = 238.03*g/mole
```
and 
```
      density = 18.95*g/cm3 // (see slide #8)! 
```
- c. Create enriched Uranium material (90% of U235 and 10% of U238 isotopes) as
      a one component material with: name "Enriched U mat", density = 18.95*g/cm3 
      (see slide #7 for creating the enriched U element and slide #9 for 
      creating the single component material)    
  

Exercise 4.
-----------
Print out all the materials constructed in the application at the beginning of 
the run!

