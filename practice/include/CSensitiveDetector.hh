#ifndef CSENSITIVE_DETECTOR_HH
#define CSENSITIVE_DETECTOR_HH

#include "G4VSensitiveDetector.hh"

class G4TouchableHistory;
class G4Step;

class CSensitiveDetector : public G4VSensitiveDetector
{
    public:
        CSensitiveDetector(G4String);
        ~CSensitiveDetector();
    private:
        virtual G4bool ProcessHits(G4Step*, G4TouchableHandle*);
};

#endif
