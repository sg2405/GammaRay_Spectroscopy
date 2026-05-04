#include "runAction.hh"

runAction::runAction()
{   

    G4AnalysisManager *analysismanager = G4AnalysisManager::Instance();
    analysismanager -> SetNtupleMerging(true);

    analysismanager -> CreateH1("Edep","Energy deposited", 1000, 0 , 1.1 *MeV);

    analysismanager -> CreateNtuple("Photons","Photons");
    analysismanager -> CreateNtupleIColumn("iEvent");
    analysismanager -> CreateNtupleDColumn("fX");
    analysismanager -> CreateNtupleDColumn("fY");
    analysismanager -> CreateNtupleDColumn("fZ");

    analysismanager -> CreateNtupleDColumn("fGlobalTime");

    analysismanager -> CreateNtupleDColumn("fWavelength");
    analysismanager -> FinishNtuple(0);



}

runAction::~runAction()
{

}

void runAction::BeginOfRunAction(const G4Run *run)
{
    G4AnalysisManager *analysismanager = G4AnalysisManager::Instance();

    G4int runID = run -> GetRunID();

    G4bool multiple_files = false;

    if (multiple_files == true){
        std::stringstream strRunID;
        strRunID << runID;

        analysismanager -> OpenFile("output" + strRunID.str() + ".root");
    }

    else
    {
        analysismanager -> OpenFile("output.root");
    };
    
}

void runAction::EndOfRunAction(const G4Run *run)
{
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager -> Write();

    analysisManager -> CloseFile();

    G4int runID = run -> GetRunID();

    G4cout <<"Finishing run" << runID << G4endl;
}

