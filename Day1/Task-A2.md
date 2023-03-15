Task A2 - Adding a "target" volume
==================================

Exercise "ExDay1"
----------------
- Compile and execute the existing code in "ExDay1" directory
- Edit the YourDetectorConstruction.cc file
  - Inspect it
- Starting from line #74, define a box of dimensions:
  - X: 1 cm
  - Y: 1.25 cm
  - Z: 1.25 cm
- Define its logical volume:
  - Define a pointer 'targetLogical' to G4LogicalVolume and give
    "logic-Target" as its name
  - Associate to it the target material already defined above
- Place the box in the world volume:
  - Centered in 0,0,0
  - With no rotation
- Assign its physical volume pointer to the existing 'fTargetPhysical' pointer
- Compile and execute
  - Visualise your detector
