#include "PhysicsList.hh"


// intialize the construsctor 
PhysicsLists::PhysicsLists()
{
    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());
}

// initialize the destrcutor, mainly for to free memory
PhysicsLists::~PhysicsLists()
{

}