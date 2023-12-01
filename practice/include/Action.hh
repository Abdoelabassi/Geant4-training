#ifndef ACTION_HH
#define ACTION_HH


#include "G4VUserActionInitialization.hh"
#include "PrimaryGenerator.hh"
#include "RunAction.hh"

class Action : public G4VUserActionInitialization
{
    public:
        Action();
        ~Action();

        virtual void Build() const;
};

#endif
