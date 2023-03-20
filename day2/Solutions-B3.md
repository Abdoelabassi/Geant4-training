**Solutions for Task B3
---------------------**


Exercise 1
----------

- a. 
  /gun/particle e-
  /gun/particle e+
  /gun/particle proton
  /gun/particle gamma
  /gun/particle mu-

- b. 
  /gun/energy 30 MeV

- c. 
  /tracking/verbose 1  
  /run/beamOn 1

Exercise 2.
-----------

- a.
    G4ParticleDefinition* part = G4ParticleTable::GetParticleTable()->FindParticle( "e-" );
    fParticleGun->SetParticleDefinition( part );

- b.
    fParticleGun->SetParticleEnergy( 10.*CLHEP::MeV );

- c.
    fParticleGun->SetParticlePosition( G4ThreeVector(-1.1*cm,0.,0.) );
n
- d.
    fParticleGun->SetParticleMomentumDirection( G4ThreeVector(0.,0.,0.) );

Exercise 3
----------

Change primary particle parameters in YourPrimaryGenerator class
- a. define primary e+
- b. define position on the surface of the target
- c. define random position on the surface for each new primary

- a.
    G4ParticleDefinition* part = G4ParticleTable::GetParticleTable()->FindParticle( "e+" );
    fParticleGun->SetParticleDefinition( part );

- b.
    fParticleGun->SetParticlePosition( G4ThreeVector(-1.*cm,0.,0.) );

- c.
    G4double x = - 1. * cm;
    G4double y = (-1.25 + 2.5*G4UniformRand()) * cm;
    G4double z = (-1.25 + 2.5*G4UniformRand()) * cm;
    fParticleGun->SetParticlePosition( G4ThreeVector( x, y, z) );

