#include "Action.hh"

Action::Action()
{}
Action::~Action()
{}

void Action::Build() const
{
    PrimaryGenerator *generator = new PrimaryGenerator();
    SetUserAction(generator);

    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
}