#include "sensDet.hh"

sensDet::sensDet(G4String name) : G4VSensitiveDetector(name)
/*G4VSensitiveDetector has no default constructor — its only constructor takes a G4String name 
(the detector's name,
 used so you can later look it up via G4SDManager). When your class inherits from it, the 
 C++ compiler tries to call the base class's default constructor 
 automatically before yours runs. Since none exists, compilation fails.

You receive G4String name as your own constructor parameter, but you never forward it to the base. 
You have to do that explicitly with a member-initializer list:*/
{
    fTotalEnergyDeposited = 0.0;

}

sensDet::~sensDet()
{

}

void sensDet::Initialize(G4HCofThisEvent *)
{
    fTotalEnergyDeposited = 0;
}

void sensDet::EndOfEvent(G4HCofThisEvent *)
{
    G4cout << "Total energy deposited in " << GetName() << ": " << fTotalEnergyDeposited/keV << " keV" << G4endl;

    G4AnalysisManager *analysismanager = G4AnalysisManager::Instance();
    analysismanager -> FillH1(0, fTotalEnergyDeposited/MeV);
}

G4bool sensDet::ProcessHits(G4Step *astep, G4TouchableHistory *hist)
{
    G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
    G4AnalysisManager *analysismanager = G4AnalysisManager::Instance();

    G4StepPoint *preStep = astep -> GetPreStepPoint();
    G4StepPoint *postStep = astep -> GetPostStepPoint();

    G4double fGlobalTime = preStep -> GetGlobalTime();
    G4ThreeVector posPhoton = preStep -> GetPosition();
    G4ThreeVector momPhoton = preStep -> GetMomentum();

    G4double momPhoton_mag = momPhoton.mag();
    G4double wavelength = (1.239841939 * eV / momPhoton_mag) * 1E+03;

    analysismanager -> FillNtupleIColumn(0,0,eventID);
    analysismanager -> FillNtupleDColumn(0,1,posPhoton[0]);
    analysismanager -> FillNtupleDColumn(0,2,posPhoton[1]);
    analysismanager -> FillNtupleDColumn(0,3,posPhoton[2]);

    analysismanager -> FillNtupleDColumn(0,4,fGlobalTime);
    analysismanager -> FillNtupleDColumn(0,5, wavelength);

    analysismanager -> AddNtupleRow(0);

    G4double fenergy = astep -> GetTotalEnergyDeposit();

    if (fenergy > 0)
    {
        fTotalEnergyDeposited += fenergy;
    };

    
    return true;
}