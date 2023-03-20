
#include "YourPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "Randomize.hh"
#include "G4SystemOfUnits.hh"


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
