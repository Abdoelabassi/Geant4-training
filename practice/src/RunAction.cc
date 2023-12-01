#include "RunAction.hh"
#include "globals.hh"

RunAction::RunAction()
{}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager* analysis = G4AnalysisManager::Instance();

    analysis->OpenFile("Cherenkov.root");

    analysis->CreateNtuple("Hits", "Cherenkov hits");
    analysis->CreateNtupleIColumn("fEvents");
    analysis->CreateNtupleDColumn("fX");
    analysis->CreateNtupleDColumn("fY");
    analysis->CreateNtupleDColumn("fZ");
    analysis->FinishNtuple(0);
}

void RunAction::EndOfRunAction(const G4Run*)
{

    G4AnalysisManager* ana = G4AnalysisManager::Instance();

    ana->Write();
    ana->CloseFile();


}