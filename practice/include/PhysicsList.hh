#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

// include all necessary headers for the physics process
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"



class PhysicsLists : public G4VModularPhysicsList{

    public:
        PhysicsLists();
        ~PhysicsLists();




};

#endif