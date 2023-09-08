#include "RunAction.hh"

// constructor
RunAction::RunAction()
{}

// destructor
RunAction::~RunAction()
{}

void RunAction::Build() const
{
    PrimaryGenerator* Pgenerator = new PrimaryGenerator();
    SetUserAction(Pgenerator);
}