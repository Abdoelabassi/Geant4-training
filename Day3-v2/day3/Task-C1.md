Goal: Accumulate energy deposit using Stepping Action
=====================================================

The User Actions can inspect almost anything in a running simulation.
We will use them accumulate energy and step length in the target volume.

Setup
-----
Get the tar file day3.tar (add instructions HERE) and extract it's contents:
```
    cd ~/g4
    wget ............... Add URL HERE
    tar xf day3.tar
    cd day3
    ls -l
    cd ExDay3 
```

Inspection
----------
Let's look at the classes for user action that we will use
```
    ls -l 
    ls -l include
    ls -l src
```
Let's look at the stepping action class
```
    gedit include/YourSteppingAction.hh
    gedit src/YourSteppingAction.cc
```
First we implemented the UserSteppingAction method that's called by the G4 kernel.

Then we collect the sums at the end of an event using an EventAction.
```
    gedit include/YourEventAction.hh
    gedit src/YourEventAction.cc
```
Its 'EndOfEventAction' method uses the  'GetSumEnergyDeposit' (and 'GetSumChangedSteps') methods of 'YourSteppingAction' to retrieve the sum(s).

And 'ResetSums' must be called to zero their values at the start of each event.  That is done in the 'BeginOfEventAction'.

To enable this we passed the YourSteppingAction object to the constructor of YourEventAction ( see YourSteppingAction::YourSteppingAction ).

Let's build and run it
```
    mkdir build
    cd build
    cmake ..
    ./yourMainApplication
```
and to simulate one event with a primary electon:
```
    /gun/particle e-
    /run/initialize
    /tracking/verbose 1
    /run/beamOn 1
```
You should see something like:
```
  Energy deposit = 0.01
  Energy deposit = 0.01
  Event 0  energy deposit = 0.02  sum charged step len = 0.002
```
They are 'placeholder' values - as though every step deposited 10 KeV exactly.

You can see that they are wrong by using the interactive command
```
     /tracking/verbose 1
```
and comparing with the correct energy deposition reported by G4
```
Idle> /tracking/verbose 1
Idle> /run/beamOn 1      

*******************************************************************************
* G4Track Information:   Particle = e-,   Track ID = 1,   Parent ID = 0
*******************************************************************************

Step#  X(mm)  Y(mm) Z(mm) KinE/MeV dE/MeV StepL TrackL NextVolume ProcessName
   0    0      0     0     1000       0      0     0   Target    initStep
   1    5      0     0      998    2.36      5     5   World     Transportation
 Energy deposit = 0.01
   2    5.5 -0.0004 -0.0004 998  2.e-26    0.5   5.5  OutOfWorld Transportation
 Energy deposit = 0.01
 Event 0  energy deposit = 0.02  sum charged step len = 0.002
```
it is clear that it is only a placeholder.

Now the tasks are first to get the correct energy deposit, and then to limit it to the target volume.

Sum energy deposits in the 'target' volume
------------------------------------------
1. Change YourSteppingAction class to sum up all energy deposit

  Currently there is a 'fake' energy deposit for each step in [YourSteppingAction.cc](src/YourSteppingAction.cc)
```
    G4double edep = 0.01;       // -> CHANGE this
    fSumEnergyDeposit += edep;
```

  Let's instead fetch the energy deposit from the current [G4Step](https://geant4.kek.jp/lxr/source/track/include/G4Step.hh)
  Hint: look for methods with 'EnergyDeposit' in their name.  ( More hints: [Get](https://geant4.kek.jp/lxr/source/track/include/G4Step.hh#L94) )

  Now build and run it.  Do the results change ?

2. Change the code to sum only the energy if the step is in the 'Target' volume

So we must inform 'YourSteppingAction' about the volume (G4VPhysicalVolume) of the target.

This will involve a few steps - first we deal with the SteppingAction:
- first revise the method 'UserSteppingAction' assuming that we know the target volume (and it is stored in the data member 'fTargetVol');
- compare the current [G4Track](https://geant4.kek.jp/lxr/source/track/include/G4Track.hh)'s volume to see if it is that 'Target'
- next change the constructor of 'YourSteppingAction' to take the Target 'G4VPhysicalVolume' as an argument and store it.

3. How to pass the target volume to 'YourSteppingAction'

What object calls the constructor of 'YourSteppingAction' get the Target volume ?
- Which class created it ?
- That class needs pass either the target's PhysicalVolume (takenfrom YourDetectorConstruction) or else just pass it a pointer/reference to YourDetectorConstruction;
- Let's revise the constructor of YourActionInitialisation.

Finally we can now 'pass' the target to the 'UserSteppingAction' when we create it in YourActionInitialization::Build().


  

- Pass the energy deposit to