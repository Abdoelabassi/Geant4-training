#include "CDetectorConstruction.hh"


DetectorConstruction::DetectorConstruction()
{

}

DetectorConstruction::~DetectorConstruction()
{

}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // define the Nist instance
    G4NistManager* nist = G4NistManager::Instance();
    // build the optical material to use for the cherenkov: consisting of Silicon dioxyde, water molecule, and Carbon
    G4Material* SiO2 = new G4Material("SiO2", 2.201 *g/cm3, 2);
    SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
    SiO2->AddElement(nist->FindOrBuildElement("O"), 2);
    // build water molecule
    G4Material* H2O = new G4Material("H2O", 1.000 *g/cm3, 2);
    H2O->AddElement(nist->FindOrBuildElement("H"), 1);
    H2O->AddElement(nist->FindOrBuildElement("O"), 2);
    // build carbon element
    G4Element* C = nist->FindOrBuildElement("C");
    // our material: Aerogel
    G4Material* Aerogel = new G4Material("Aerogel", 0.200 *g/cm3, 3);
    Aerogel->AddMaterial(SiO2, 62.5 *perCent);
    Aerogel->AddMaterial(H2O, 37.4 *perCent);
    Aerogel->AddElement(C, 0.1 *perCent);
    // optical properties
    G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
    G4double rindexAerogel[2] = {1.1, 1.1};
    G4double rindexWorld[2] = {1.0, 1.0};

    G4MaterialPropertiesTable* mptAergoel = new G4MaterialPropertiesTable();
    mptAergoel->AddProperty("RINDEX", energy, rindexAerogel, 2);

    Aerogel->SetMaterialPropertiesTable(mptAergoel);

    G4MaterialPropertiesTable* mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy ,rindexWorld, 2);
    // define a World material
    G4Material* worldmat = nist->FindOrBuildMaterial("G4_AIR");
    worldmat->SetMaterialPropertiesTable(mptWorld);
    // solid world
    G4Box* solidWorld = new G4Box("solidworld", 0.5*m, 0.5*m, 0.5*m);

    G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, worldmat, "logicWorld");

    // build the radiator, where the Aerogel will be placed
    G4Box* solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);
    G4LogicalVolume* logicalRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "LogicalRadiator");



    // physical volume for air
    G4VPhysicalVolume* phyworld = new G4PVPlacement(
        0,
        G4ThreeVector(0,0,0),
        logicalWorld,
        "phyworld",
        0,
        false,
        true

    );

    // physical volume for the Aerogel
    G4VPhysicalVolume* phyradiator = new G4PVPlacement(
        0,
        G4ThreeVector(0., 0., 0.25*m),
        logicalRadiator,
        "phyRadiator",
        logicalWorld,
        false,
        0,
        true

    );
    

    return phyworld;


}