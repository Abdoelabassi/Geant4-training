**Solutions for Task B2
---------------------**


Exercise 1
a.

  > /material/nist/printElement Al 

b.

  > /material/nist/listMaterials bio

Exercise 2.

a. Open the B1DetectorConstruction class Construct() method.
b. Add the following line after the construction of the "env_mat":

      G4cout << env_mat << G4endl; 

c. Change the "G4_WATER" string in the "env_mat" construction to "G4_lAr"
d. See slide #9 to define elements (H, O) and to construct the material!

Exercise 3.

a:
   G4Material* matNistU = G4NistManager::Instance()->FindOrBuildMaterial("G4_U");  

b:
   G4Material* matU = new G4Material("Natural U mat", 92, 238.03*g/mole, 18.95*g/cm3);

c:
   G4Isotope* U5 = new G4Isotope("U235", 92, 235);
   G4Isotope* U8 = new G4Isotope("U238", 92, 238);
   G4Element* elU = new G4Element("enriched U elem", "U", 2);
   elU->AddIsotope(U5, 0.9);
   elU->AddIsotope(U8, 0.1);
   G4Material* matEnrichedU = new G4Material("Enriched U mat", 18.95*g/cm3, 1);
   matEnrichedU->AddElement(elU,1.0); 
and printing them out:
   G4cout << matNistU     << G4endl;
   G4cout << matU         << G4endl;
   G4cout << matEnrichedU << G4endl;   

Exercise 4.

Add the following lines at the beginning of the BeginOfRunAction(const G4Run*)
method of the run action of the application (i.e. the B1RunAction):
     B1RunAction::BeginOfRunAction(const G4Run*) {
        // print only in case of the master thread 
        if (IsMaster()) {
           G4out << *(G4Material::GetMaterialTable()) << G4endl;
        }
        ...
        ...
     }
