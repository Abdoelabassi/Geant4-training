#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"




class DetectorConstruction: public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction();
        ~DetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

};



#endif