#include "CSensitiveDetector.hh"

CSensitiveDetector::CSensitiveDetector(G4String detector_name)
:G4VSensitiveDetector(detector_name)
{}

CSensitiveDetector::~CSensitiveDetector()
{}

G4bool CSensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* history)
{
    // particle track
    G4Track* track = aStep->GetTrack();
    // kill the tracks ouside the entry
    track->SetTrackStatus(fStopAndKill);
    // Pre step point : entry
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    // post step point
    G4StepPoint* postStepPoint = aStep->GetPostStepPoint();
    // prestep position
    G4ThreeVector posPhoton = preStepPoint->GetPosition();

    G4cout << "Photon position: " << posPhoton << G4endl;

    // Detector copy number
    const G4VTouchable* touchable = aStep->GetPreStepPoint()->GetTouchable();
    G4int copynumber = touchable->GetCopyNumber();

    G4cout << "Copy number: " << copynumber << G4endl;

    // Detector position
    G4VPhysicalVolume* phyvol = touchable->GetVolume();
    G4ThreeVector posDetector = phyvol->GetTranslation();

    G4cout << "detector position: " << posDetector << G4endl;
}

