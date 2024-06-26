
#include "YourDetectorConstruction.hh"

// for geometry definitions
#include "G4Box.hh"
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
    : G4VUserDetectorConstruction() {}

// Destructor
//
YourDetectorConstruction::~YourDetectorConstruction() {}

// The detector is a simple slab with a thickness along the x-direction.
//
G4VPhysicalVolume *YourDetectorConstruction::Construct() {
  // I. CREATE MATERIALS:
  // 1. Material for the world: low density hydrogen defined by "hand"
  G4double zet = 1.0;
  G4double amass = 1.01 * g / mole;
  G4double density = universe_mean_density;
  G4double pressure = 3.e-18 * pascal;
  G4double tempture = 2.73 * kelvin;
  G4Material *materialWorld = new G4Material("Galactic", zet, amass, density,
                                             kStateGas, tempture, pressure);
  // 2. Material for the target: set to be Silicon
  G4Material *targetMaterial =
      G4NistManager::Instance()->FindOrBuildMaterial("G4_Si");

  // II. CREATE GEOMETRY:

  // a. Create the world (a box), defining first its size:
  G4double worldXSize = 1.1 * cm;
  G4double worldYZSize = 1.25 * worldXSize;
  G4Box *worldSolid = new G4Box("solid-World",                    // name
                                0.5 * worldXSize,                 // half x-size
                                0.5 * worldYZSize,                // half y-size
                                0.5 * worldYZSize);               // half z-size
  G4LogicalVolume *worldLogical = new G4LogicalVolume(worldSolid, // solid
                                                      materialWorld, // material
                                                      "logic-World"); // name
  G4VPhysicalVolume *worldPhysical =
      new G4PVPlacement(0,                         // (no) rotation
                        G4ThreeVector(0., 0., 0.), // translation
                        worldLogical,              // its logical volume
                        "World",                   // its name
                        0,                         // its mother volume
                        false,                     // not used
                        0);                        // copy number

  // ++++++++++++++++++++++++++ TASK-A2 ++++++++++++++++++++++++
  G4Box *targetSolid = new G4Box("targetSolid", 1 * cm, 1.25 * cm, 1.25 * cm);
  G4LogicalVolume *targetLogical =
      new G4LogicalVolume(targetSolid, targetMaterial, "logic-target");
  G4VPhysicalVolume *targetPhysical =
      new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), // centered
                        targetLogical,                // its logical volume
                        "Target",                     // target
                        0,              // phy volume
                        false, 0);

  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // III. RETURN THE World PHYSICAL-VOLUME POINTER:
  return worldPhysical;
}
