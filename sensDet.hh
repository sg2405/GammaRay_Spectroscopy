#ifndef SENSDET_HH
#define SENSDET_HH

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

class sensDet : public G4VSensitiveDetector
{
    public:
        sensDet(G4String);
        virtual ~sensDet();

    private:

        G4double fTotalEnergyDeposited;

        virtual void Initialize(G4HCofThisEvent *) override;
        virtual void EndOfEvent(G4HCofThisEvent *) override;

        virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) override;
};

#endif