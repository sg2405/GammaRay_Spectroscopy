#include "construct.hh"
#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4SDManager.hh"
#include "sensDet.hh"

detectorconstruct::detectorconstruct()
{

}

detectorconstruct::~detectorconstruct()
{

}

G4VPhysicalVolume* detectorconstruct::Construct()
{
    G4bool checkOverlaps = true;

    G4NistManager* nist = G4NistManager::Instance();
    G4Material *world_mat = nist -> FindOrBuildMaterial("G4_AIR");
    G4Material *lead = nist -> FindOrBuildMaterial("G4_Pb");
    G4Material *det = nist -> FindOrBuildMaterial("G4_SODIUM_IODIDE");
    
    G4Isotope *F18 = new G4Isotope("F18",9,18, 18.000938 *g/mole);
    G4Element *elF18 = new G4Element("elF18","F-18",1);
    elF18 -> AddIsotope(F18, 100 *perCent);
    G4Material *mat_f18 = new G4Material("F18Source",1.51 *g/cm3, 1);
    mat_f18 -> AddElement(elF18, 100 * perCent);

    G4double leadThickness = 2 *mm;
    G4double leadSize = 10 *cm;


    G4double xWorld = 1 *m;
    G4double yWorld = 1 *m;
    G4double zWorld = 1 *m;

    G4Box *solidWorld = new G4Box("solidWorld", xWorld/2, yWorld/2, zWorld/2);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidWorld, world_mat, "logicworld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(), logicworld, "physworld", 0, false, 0, checkOverlaps);

    G4Box *solidLead = new G4Box("solidLead", 0.5* leadSize, 0.5* leadSize, 0.5 *leadThickness);
    G4LogicalVolume *logicLead = new G4LogicalVolume(solidLead, lead, "logicLead");
    G4VPhysicalVolume *physLead = new G4PVPlacement(0, G4ThreeVector(0,0,5 *cm), logicLead, "physLead", logicworld, false, 0, checkOverlaps);


    G4VisAttributes *visLead = new G4VisAttributes(G4Color(1,0,0, 0.5));
    visLead -> SetForceSolid(true);
    logicLead -> SetVisAttributes(visLead);

    G4double detSize = 5 *cm;

    G4Box *solidDet = new G4Box("solidDet", 0.5* detSize, 0.5* detSize, 0.5* detSize);
    logicDet = new G4LogicalVolume(solidDet, det, "logicDet");
    G4VPhysicalVolume *physDet = new G4PVPlacement(0 ,G4ThreeVector(0,0, 10.5 *cm), logicDet, "physDet", logicworld, false,0 , checkOverlaps);

    G4VisAttributes *visDet = new G4VisAttributes(G4Color(1,1,0,0.5));
    visDet -> SetForceSolid(true);
    logicDet -> SetVisAttributes(visDet);

    //Fluorine

    G4double sourceRadius = 1 *mm;
    G4Sphere *solidSource = new G4Sphere("solidsource",0,sourceRadius, 0, 360 *deg, 0 *deg, 180 *deg);
    G4LogicalVolume *logicSource = new G4LogicalVolume(solidSource, mat_f18, "logicsource");
    G4VPhysicalVolume *physSource = new G4PVPlacement(0, G4ThreeVector(0,0,-0.5 *cm), logicSource, "physsource", logicworld, 0, checkOverlaps);

    G4VisAttributes *visSource = new G4VisAttributes(G4Color(1,0,1,0.5));
    visSource -> SetForceSolid(true);
    logicSource -> SetVisAttributes(visSource);

    return physWorld;
}

void detectorconstruct::ConstructSDandField()
{
    sensDet *detector = new sensDet("detector");
    logicDet -> SetSensitiveDetector(detector);
    G4SDManager::GetSDMpointer()->AddNewDetector(detector); //Look again for the utility of this line

}