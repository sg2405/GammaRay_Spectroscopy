#include "Physicslists.hh"

physicslists::physicslists()
{
    //EM Physics
    RegisterPhysics(new G4EmStandardPhysics());

    //Radioactive Decay
    RegisterPhysics(new G4RadioactiveDecayPhysics());

    // Decay Physics

    RegisterPhysics(new G4DecayPhysics());
}

physicslists::~physicslists()
{

}