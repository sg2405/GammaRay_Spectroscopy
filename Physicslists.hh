#ifndef PHYSICSLISTS_HH
#define PHYSICSLISTS_HH 1

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"

class physicslists : public G4VModularPhysicsList
{
    public:
        physicslists();
        virtual ~physicslists();
};

#endif

