
#include "YourDetectorConstruction.hh"

// for geometry definitions 
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

// for material definitions
#include "G4Material.hh"
#include "G4NistManager.hh"

// for having units and constants
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"


// Constructor
//
YourDetectorConstruction::YourDetectorConstruction()
  : G4VUserDetectorConstruction()
{
}

// Destructor
//
YourDetectorConstruction::~YourDetectorConstruction()
{
}

// The detector is a simple slab with a thickness along the x-direction.
//
G4VPhysicalVolume* YourDetectorConstruction::Construct()
{
    // I. CREATE MATERIALS:
    // 1. Material for the world: low density hydrogen defined by "hand"
    G4double zet      = 1.0;
    G4double amass    = 1.01*g/mole;
    G4double density  = universe_mean_density;
    G4double pressure = 3.e-18*pascal;
    G4double tempture = 2.73*kelvin;
    G4Material* materialWorld
           = new G4Material("Galactic", zet, amass, density,
                            kStateGas, tempture, pressure);
    // 2. Material for the target: set to be Silicon
    G4Material* targetMaterial
           = G4NistManager::Instance()->FindOrBuildMaterial("G4_Si");

    // II. CREATE GEOMETRY:

    // a. Create the world (a box), defining first its size:
    G4double worldXSize   = 1.1*cm;
    G4double worldYZSize  = 1.25*worldXSize;
    G4Box* worldSolid
           = new G4Box("solid-World",    // name
    	               0.5*worldXSize,   // half x-size
    	               0.5*worldYZSize,  // half y-size 
    	               0.5*worldYZSize); // half z-size
    G4LogicalVolume* worldLogical
           = new G4LogicalVolume(worldSolid,     // solid
                                 materialWorld,  // material
                                 "logic-World"); // name
    G4VPhysicalVolume* worldPhysical
           = new G4PVPlacement(nullptr,                 // (no) rotation
                               G4ThreeVector(0.,0.,0.), // translation
                               worldLogical,            // its logical volume
                               "World",                 // its name
                               nullptr,                 // its mother volume
                               false,                   // not used
                               0);                      // copy number

    // ++++++++++++++++++++++++++ YOUR CODE FROM HERE ++++++++++++++++++++++++

    // b. Create the target (a box), defining first its size:
    G4double targetXSize  = 1.0*cm;
    G4double targetYZSize = 1.25*targetXSize;
    G4Box* targetSolid 
           = new G4Box("solid-Target",    // name
    	               0.5*targetXSize,   // half x-size
    	               0.5*targetYZSize,  // half y-size 
    	               0.5*targetYZSize); // half z-size
    G4LogicalVolume* targetLogical
           = new G4LogicalVolume(targetSolid,     // solid
                                 targetMaterial,  // material
                                 "logic-Target"); // name
    fTargetPhysical
           = new G4PVPlacement(nullptr,                 // (no) rotation
                               G4ThreeVector(0.,0.,0.), // translation
                               targetLogical,           // its logical volume
                               "Target",                // its name
                               worldLogical,            // its mother volume
                               false,                   // not used
                               1,                       // copy number
                               true);                   // enable overlap check

    // c. Create a target disc (a full tube), defining first its dimensions:
    G4double discZLength = 0.5*mm;
    G4double discRadius  = 5.5*mm;
    G4Tubs* targetDisc 
           = new G4Tubs("disc-Target",    // name
                        0,                // minimum radius, 0 == full-tube
    	                discRadius,       // maximum radius
    	                0.5*discZLength,  // Z half-length
    	                0,                // start-Phi angle
                        twopi*rad);       // delta-Phi angle,
                                          // 2*pi == unsegmented tube
    G4LogicalVolume* discLogical
           = new G4LogicalVolume(targetDisc,      // solid
                                 targetMaterial,  // material
                                 "logic-Disc");   // name
    // G4VPhysicalVolume* discPhysical =
             new G4PVPlacement(nullptr,                 // (no) rotation
                               G4ThreeVector(0.,0.,0.65*cm), // translation
                               discLogical,             // its logical volume
                               "Disc",                  // its name
                               worldLogical,            // its mother volume
                               false,                   // not used
                               2,                       // copy number
                               true);                   // enable overlap check

    // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // III. RETURN THE World PHYSICAL-VOLUME POINTER:
    return worldPhysical;
}
