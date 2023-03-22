
#include "YourPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "Randomize.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

YourPrimaryGeneratorAction::YourPrimaryGeneratorAction()
  : G4VUserPrimaryGeneratorAction()
{
   // create the particle-gun object
   G4int nParticle = 1;
   fParticleGun    = new G4ParticleGun(nParticle);
   SetDefaultKinematic();
}


YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction()
{
   delete fParticleGun;
}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* evt)
{
   // here it is possible to place extra code
   //Define random positions
   G4double x = 1.1*cm;
   G4double y = (-1.25 + 2.5*G4UniformRand())*cm;
   G4double z = (-1.25 + 2.5*G4UniformRand())*cm;
   //G4ParticleDefinition* particle;
   G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
   G4ParticleDefinition* particle = particleTable->FindParticle("e+");
   fParticleGun->SetParticleDefinition(particle);
   fParticleGun->SetParticleEnergy(100*MeV);
   fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
   //
   fParticleGun->GeneratePrimaryVertex(evt);
}

void YourPrimaryGeneratorAction::SetDefaultKinematic()
{
   // here it is possible to place extra code
   fParticleGun->SetParticleMomentumDirection( G4ThreeVector(1., 0., 0.) );
   fParticleGun->SetParticlePosition( G4ThreeVector(-1.1*cm, 0., 0.) );
   fParticleGun->SetParticleEnergy( 100*MeV );
   //
}
