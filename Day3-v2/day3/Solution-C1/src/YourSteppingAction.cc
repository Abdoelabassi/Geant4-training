
#include "YourSteppingAction.hh"

#include "G4Step.hh"

YourSteppingAction::YourSteppingAction(const G4VPhysicalVolume *targetVol)  // Changed
:   G4UserSteppingAction()
{
//  3. We need to obtain and remember the Target Volume in this constructor
   fTargetVol= targetVol;   // Changed
   if( targetVol != nullptr ) 
      std::cout << " YourSteppingAction: with target volume " 
       << targetVol->GetName() << std::endl;
       
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
    G4double edep = theStep->GetTotalEnergyDeposit();       // -> Changed


    // 2. Report it -- as a check
    // G4cout << " Energy deposit (any)= " << edep << G4endl;

    // 3. Check whether step was done inside the Target
    // 
    //   Let's change what we sum:
    //      Score only steps in the *target*: i.e. pre-step point was in target
    //
    //  YOUR CODE HERE
    //
    //  Steps:
    //  a) Fetch the current volume from G4Step or G4Track
    G4VPhysicalVolume* currVol = theTrack->GetVolume();  
    //  b) Make sure that the 'target' volume is given to 'Stepping Action' when it is created!
    //         ( Hint: look at the constructor in the header and above )

    //  c) Compare !

    if( currVol->GetCopyNo()
        // currVol == fTargetVol 
        //      == fYourDetector->GetTargetPhysicalVolume()
       ){
        // G4cout << " Energy dep (in Target) = " << edep << G4endl;
    //  d) Sum the energy only in 'target' volume        
        fSumEnergyDeposit += edep;
    } else {
        if( fTargetVol == nullptr ){
           G4cerr << "WARNING> Target volume is NOT set." << G4endl;
        }
    }

    // 5. Find the length of the current step 
    G4double step_length = theStep->GetStepLength();  // -> Changed

    // 6. Check whether the particle is charged
    const G4ParticleDefinition* pDef = theTrack->GetParticleDefinition();
    G4double charge = pDef->GetPDGCharge() ;       // ->  Changed

    // 7. Sum the length of charged steps - everywhere?
    if( charge != 0.0 && currVol == fTargetVol )
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
