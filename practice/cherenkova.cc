#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "CDetectorConstruction.hh"
#include "PhysicsList.hh"

int main(int argc, char** argv){

    G4RunManager* runManager = new G4RunManager();
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsLists());
    runManager->Initialize();


    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    G4UImanager *uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVoulme");

    ui->SessionStart();



    return 0;
}