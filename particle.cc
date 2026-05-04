#include "particle.hh"

generator::generator()
{
    fParticleGun = new G4ParticleGun(1);

    //Particle Position

    G4double x0 = 0.0 * m;
    G4double y0 = 0.0 * m;
    G4double z0 = -0.5 * cm;

    //Particle Direction

    G4double px = 0;
    G4double py = 0;
    G4double pz = 0;

    fParticleGun->SetParticlePosition(G4ThreeVector(x0, y0, z0));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(px, py, pz));

    //Particle Definition


}

generator::~generator()
{
    delete fParticleGun;
}

void generator::GeneratePrimaries(G4Event* anEvent)
{
    //Particle Type
    G4int Z = 9;
    G4int A = 18;

    G4double charge = 0 * eplus;
    G4double energy = 0;
    G4ParticleDefinition *ion = G4IonTable::GetIonTable()->GetIon(Z,A,energy);
    fParticleGun -> SetParticleDefinition(ion);
    fParticleGun -> SetParticleCharge(charge);
    fParticleGun -> SetParticleEnergy(energy);
    
    fParticleGun->GeneratePrimaryVertex(anEvent);
}