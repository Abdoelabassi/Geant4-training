#ifndef YOURACTIONINITIALIZATION_HH
#define YOURACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"

// forward declarations
class YourDetectorConstruction;

class YourActionInitialization : public G4VUserActionInitialization {

  // Method declaration:
  public:
    
    YourActionInitialization(YourDetectorConstruction* det);
    //  Changed: Added argument for detector constructor - needed to initialize data members

    virtual ~YourActionInitialization(); 

    // (Pure) Virtual method -- must be implemented
    virtual void Build() const;

    // 
    virtual void BuildForMaster() const;


  // Data member declarations:
  private:
     // New data members HERE
     YourDetectorConstruction* fDetectorCon = nullptr;
};

#endif
