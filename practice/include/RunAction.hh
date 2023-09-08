#ifndef RUNACTION_HH
#define RUNACTION_HH

// include necessary headers
#include "G4VUserActionInitialization.hh"

class RunAction : public G4VUserActionInitialization
{
    RunAction();
    ~RunAction();

    virtual void Build() const;

};


#endif