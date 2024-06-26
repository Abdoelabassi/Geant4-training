
#ifndef YOUREVENTACTION_HH
#define YOUREVENTACTION_HH

#include "G4UserEventAction.hh"

#include "globals.hh"

// Forward declaration
class YourSteppingAction; 
class YourDetectorConstruction;

class YourEventAction : public G4UserEventAction {

  // Method declaration:
  public:
    
    // Constructor / CTR
   YourEventAction(YourSteppingAction *       stepAction,
                   YourDetectorConstruction * detectorCon);
    // Destructor
    virtual ~YourEventAction( );

    // Two virtual method called at the beginning and at the end of each event 
    virtual void BeginOfEventAction(const G4Event* anEvent);
    virtual void EndOfEventAction(const G4Event* anEvent);

  // Data member declarations:
  private:
    YourSteppingAction          *fSteppingAction = nullptr;
    const YourDetectorConstruction *fDetectorCon = nullptr;
};

#endif
