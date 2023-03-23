
#include "G4VPhysicalVolume.hh"

#include "YourActionInitialization.hh"

#include "YourPrimaryGeneratorAction.hh"

#include "YourDetectorConstruction.hh"

#include "YourEventAction.hh"
#include "YourSteppingAction.hh"

YourActionInitialization::YourActionInitialization(YourDetectorConstruction* det)
  : G4VUserActionInitialization(),
    fDetectorCon(det)
{
}
    

YourActionInitialization::~YourActionInitialization()
{
}


#include "G4RunManager.hh"

// NOT CALLED IN SEQUENTIAL MODE i.e. ONLY FOR MT: 
// - ONLY FOR creating RunAction for the Master thread
void YourActionInitialization::BuildForMaster() const
{
   G4RunManager* rm = G4RunManager::GetRunManager();

   const G4VUserDetectorConstruction* dc= rm->GetUserDetectorConstruction();
   auto ydc= reinterpret_cast<const YourDetectorConstruction*>(dc);

   // auto ea = reinterpret_cast<YourEventAction*>(rm->GetUserEventAction());
   const G4UserSteppingAction* csa = rm->GetUserSteppingAction();
   auto stpAct = const_cast<G4UserSteppingAction*>(csa);
   auto yrStepAction = reinterpret_cast<YourSteppingAction*>(stpAct);

   const G4VPhysicalVolume* target = ydc ? ydc->GetTargetPhysicalVolume() : nullptr;
   // Now we can 'forward' the target volume to the stepping Action ..
   if( yrStepAction ) {
     yrStepAction->SetTargetVolume( target );
   } else { 
     G4cerr << "YourActionInitialization::BuildForMaster: UserSteppingAction is not yet available." << G4endl;
   }
}


// Create all User Actions here: 
// - it will be invoked immediately by G4RunManager 
//   when the ActionInitialization object is registered in the main
void YourActionInitialization::Build() const
{
  // Set UserPrimaryGeneratorAction
  YourPrimaryGeneratorAction* primaryAction = new YourPrimaryGeneratorAction();
  SetUserAction(primaryAction);

  const G4VPhysicalVolume* targetVolume = fDetectorCon->GetTargetPhysicalVolume();
  if( targetVolume == nullptr ){
      G4cerr << "WARNING>  target Volume is not (yet) defined !! " << G4endl;
  }
  YourSteppingAction* stepAction = new YourSteppingAction(targetVolume);
  //   The SteppingAction needs the target volume from the DetectorConstruction !!

  // Set UserSteppingAction
  SetUserAction( stepAction );
  
    // Set UserEventAction
  YourEventAction* eventAction = new YourEventAction(stepAction, fDetectorCon);
  SetUserAction(eventAction);
}  
