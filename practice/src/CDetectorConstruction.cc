#include "include/CDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"

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
    // define a World material
    G4Material* worldmat = nist->FindOrBuildMaterial("G4_AIR");
    // solid world
    G4Box* solidWorld = new G4Box("solidWorld", 0.5*m, 0,5*m, 0.5*m);

    G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, worldmat, "logicWorld");

    // physical volume
    G4VPhysicalVolume* phyworld = new G4PVPlacement(
        0,
        G4ThreeVector(0,0,0),
        logicalWorld,
        "phyworld",
        0,
        false,
        true

    )

    return phyworld;


}