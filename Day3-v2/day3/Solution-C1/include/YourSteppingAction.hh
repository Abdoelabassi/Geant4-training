#ifndef YOURSTEPPINGACTION_HH
#define YOURSTEPPINGACTION_HH

#include "G4UserSteppingAction.hh"

// forward declarations
class G4VPhysicalVolume;

class YourSteppingAction : public G4UserSteppingAction {

  // Method declaration:
  public:

    // --- Mandatory methods
    YourSteppingAction( const G4VPhysicalVolume* target); // Changed
    virtual ~YourSteppingAction();

    // Virtual method called by the kernel after each step
    virtual void UserSteppingAction(const G4Step* step);
    // It will accumulate the quantities

    // -----------------------

    // --- Our own methods
    //
    //  The event action must collect the cumulative values at the end of an event
    double GetSumEnergyDeposit() const;
    double GetSumChargedSteps() const;
    void   ResetSums();

    void   SetTargetVolume(const G4VPhysicalVolume* vol) { fTargetVol = vol; }
    const G4VPhysicalVolume* GetTargetVolume() { return fTargetVol;}
    
    
  // Data member declarations:
  private:
    const G4VPhysicalVolume* fTargetVol = nullptr;
    //   Keep the target volume

    double  fSumEnergyDeposit = 0.0;
    double  fSumChargedSteps  = 0.0;
    //  Total energy deposit - in target volume   
};

#endif
