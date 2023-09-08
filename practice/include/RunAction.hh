#ifndef RUNACTION_HH
#define RUNACTION_HH

// include necessary headers
#include "G4VUserActionInitialization.hh"
#include "PrimaryGenerator.hh"
class RunAction : public G4VUserActionInitialization
{
    public:
        RunAction();
        ~RunAction();

        virtual void Build() const;

};


#endif