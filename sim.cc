#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Physicslists.hh"
#include "construct.hh"
#include "ActionInitialization.hh"

int main(int argc, char** argv)
{
    G4UIExecutive* ui = nullptr;

    #ifdef G4MULTITHREADED
        G4MTRunManager* runManager = new G4MTRunManager;
    #else 
        G4RunManager* runManager = new G4RunManager;
    #endif

    // Physics List 

    runManager -> SetUserInitialization(new physicslists());
    runManager -> SetUserInitialization(new detectorconstruct());
    runManager -> SetUserInitialization(new actioninit());

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    if (argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    };

    G4UImanager *UIManager = G4UImanager::GetUIpointer();

    if (ui)
    {
        UIManager -> ApplyCommand("/control/execute vis.mac");
        ui -> SessionStart();
    }

    else
    {
        G4String command = "/control/execute ";
        G4String filename = argv[1];
        UIManager -> ApplyCommand(command + filename);
    };



    

    delete ui;
    delete visManager;
    delete runManager;

    return 0;

}