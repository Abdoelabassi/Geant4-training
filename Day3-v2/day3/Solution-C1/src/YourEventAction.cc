
#include "YourEventAction.hh"
#include "YourSteppingAction.hh"
// Because we chose to use YourSteppingAction's methods

#include "G4Event.hh"
#include "YourDetectorConstruction.hh"
// class  G4VPhysicalVolume;
#include "G4VPhysicalVolume.hh"

YourEventAction::YourEventAction( YourSteppingAction *       stepAction,
                                  YourDetectorConstruction * detectorCon
                                )
: G4UserEventAction(),
  fSteppingAction(stepAction),
  fDetectorCon(detectorCon)
{}
//  CHANGE this 
//    We need to remember the stepping action:
//    Add an argument 'YourSteppingAction*' and store it in fSteppingAction


YourEventAction::~YourEventAction() {}

// Before each event: reset per-event variables 
void YourEventAction::BeginOfEventAction(const G4Event* /*anEvent*/) {
   if( fSteppingAction ) {
     if( fSteppingAction->GetTargetVolume() == nullptr ){
       G4cerr << "WARNING>  YourEventAction::BeginOfEventAction: target Volume was not (yet) defined." << G4endl;
       const G4VPhysicalVolume* targetVol = fDetectorCon->GetTargetPhysicalVolume();

       fSteppingAction->SetTargetVolume( targetVol );  // Else may not be set
       G4cout << "          Fixing by setting target to "    // fDetectorCon->GetTargetVolume()
              <<  ( targetVol ? targetVol->GetName() : "None" )
              << G4endl;
     }      
     fSteppingAction->ResetSums();
   } else { 
     G4cerr << "ERROR in YourEventAction> There is no stepping action" << G4endl;
   }
}


// After each event:
//   print the energy deposited in target and the length of charged particle steps
void YourEventAction::EndOfEventAction(const G4Event* anEvent) {
    G4double eDep = fSteppingAction->GetSumEnergyDeposit();
    G4double len  = fSteppingAction->GetSumChargedSteps();
    G4cout << " Event " << anEvent->GetEventID() << "  energy deposit = " << eDep 
           << "  sum charged step len = " << len
           << G4endl;
}

