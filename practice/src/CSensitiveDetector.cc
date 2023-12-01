#include "CSensitiveDetector.hh"

CSensitiveDetector::CSensitiveDetector(G4String detector_name)
:G4VSensitiveDetector(detector_name)
{}

CSensitiveDetector::~CSensitiveDetector()
{}

G4bool CSensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* history)
{

}

