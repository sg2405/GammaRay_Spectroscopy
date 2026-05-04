#ifndef CONSTRUCT_HH
#define CONSTRUCT_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Isotope.hh"
#include "G4Sphere.hh"

class detectorconstruct : public G4VUserDetectorConstruction
{
    public:
        detectorconstruct();
        virtual ~detectorconstruct();
        virtual G4VPhysicalVolume* Construct();

    private:
        G4LogicalVolume* logicDet;
        virtual void ConstructSDandField();
};

#endif

