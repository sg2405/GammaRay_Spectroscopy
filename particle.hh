#ifndef PARTICLE_HH
#define PARTICLE_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4IonTable.hh"



class generator : public G4VUserPrimaryGeneratorAction
{
    public:
        generator();
        virtual ~generator();

        virtual void GeneratePrimaries(G4Event* anEvent);
    
    private:
        G4ParticleGun* fParticleGun;
};

#endif