#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "CDetectorConstruction.hh"
#include "PhysicsList.hh"
#include "RunAction.hh"
#include "PrimaryGenerator.hh"

int main(int argc, char** argv){

    // user initializatio
    G4RunManager* runManager = new G4RunManager();
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsLists());
    runManager->SetUserInitialization(new RunAction());
    

    // user run action
    runManager->SetUserAction(new PrimaryGenerator());

    runManager->Initialize();



    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialise();

    

    G4UImanager *uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");
    uiManager->ApplyCommand("/vis/scene/add/trajectories smooth");
    uiManager->ApplyCommand("/vis/scene/endOfEventAction accumulate");
    uiManager->ApplyCommand("/vis/viewer/set/autoRefresh true");



    ui->SessionStart();



    return 0;
}