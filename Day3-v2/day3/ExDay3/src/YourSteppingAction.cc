
#include "YourSteppingAction.hh"

#include "G4Step.hh"

YourSteppingAction::YourSteppingAction(const G4VPhysicalVolume* targetVol)
:   G4UserSteppingAction()
{
//  3. We need to obtain and remember the Target Volume - in this constructor?
      fTargetVol = targetVol;
      if(targetVol != nullptr){
        G4cout << "Your SteppingAction with target volume"
        << target->GetName() << G4endl;

      }
}

YourSteppingAction::~YourSteppingAction() {}

// Goals
//  1. Score energy deposition in the 'Target' volume:
//     - collect energy deposit to the mean (per-event) energy deposit computation
//  2. 'Score' the total length of steps of charged particles

void YourSteppingAction::UserSteppingAction(const G4Step* theStep)
{
    const G4Track* theTrack = theStep->GetTrack();

    // 1. Get the energy deposit
    //                                          Hint: look at the methods of G4Step
    G4double edep = theStep->GetTotalEnergyDeposit();       // -> CHANGE this




    // 2. Report it as a check -- comment this out later!
    //G4cout << " Energy deposity = " << edep << G4endl;

    // 3. Check whether step was done inside the Target
    //
    //   Let's change what we sum:
    //      Score only steps in the *target*: i.e. pre-step point was in target
    //
    //  YOUR CODE HERE
    //
    //  Steps:
    //  a) Fetch the current volume from G4Step or G4Track
    G4VPhysicalVolume* currVolume =  theTrack->GetVolume();
    //  b) Make sure that the 'target' volume is given to 'Stepping Action' when it is created!
    //         ( Hint: look at the constructor in the header and above )
    //  assert( fTargetVol != nullptr );   // A check
    //  c) Compare !
    if(currVolume->GetCopyNo()){


    //  d) Sum the energy only in 'target' volume (instead of all, as above)
    fSumChargedSteps += edep;
  }else{
    if( fTargetVol != nullptr){
      G4cerr << "WARNING> Target volume is not set" << G4endl;
    }
  }
    // 5. Find the length of the current step
    G4double step_length = theStep->GetStepLength();  // ->  CHANGE this

    // 6. Check whether the particle is charged
    const G4ParticleDefinition* pdef = theTrack->GetParticleDefinition();
    G4double charge = pdef->GetPDGCharge() ;       // ->  CHANGE this

    // 7. Sum the length of charged steps - everywhere?
    if( charge != 0.0 && currVolume == fTargetVol)
    {
      fSumChargedSteps += step_length;
    }
    //  add current energy deposit to the charged particle track length per-event

}

G4double YourSteppingAction::GetSumEnergyDeposit() const
{
    return fSumEnergyDeposit;
}

G4double YourSteppingAction::GetSumChargedSteps() const
{
    return fSumChargedSteps;
}

void      YourSteppingAction::ResetSums()
{
    fSumEnergyDeposit= 0.0;
    fSumChargedSteps = 0.0;
}
