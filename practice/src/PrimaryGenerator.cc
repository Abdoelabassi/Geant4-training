#include "PrimaryGenerator.hh"


PrimaryGenerator::PrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

PrimaryGenerator::~PrimaryGenerator()
{
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
    // get the particle table
    G4ParticleTable* particletable = G4ParticleTable::GetParticleTable();
    G4String particlename = "proton";

    // find the particle
    G4ParticleDefinition* particle = particletable->FindParticle("proton");

    // set position, momentum and direcion
    G4ThreeVector position(0., 0., 0.);
    G4ThreeVector momentum(0., 0., 1.); // along z axis

    // set the particle position and momentum, and direction
    fParticleGun->SetParticlePosition(position);
    fParticleGun->SetParticleMomentumDirection(momentum);
    fParticleGun->SetParticleMomentum(10 *MeV);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(anEvent);



}