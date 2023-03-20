
# Introduction to Geant4 Visualization

Visualisation helps us understand our setup - and lets us create pretty pictures.

In these exercises we will demonstrate basic functionality for the visualisation in Geant4.

Let's confirm what classes are responsible for visualization.  

To start we have commented out the code in yourMainApplication.cc which creates the Visualization.

Let's confirm that visualisation is missing.  Let's build and run:
```shell
cd day2/ExDay2
cd build
make -j 2
./yourMainApplication
```

## Enabling visualization

Now reactivate the visualization manager by editing yourMainApplication.cc
```
// Add visualization: 
    // - create a G4VisExecutive object as the Visualization Manager
    // - initialize the Visualization Manager (will handle all vis components)
    //
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
```
then recompile and run
```shell
cd build
make -j 2
./yourMainApplication
```

You will see the same Qt interface, but all the visualization is missing.   Let's build it up, one command at a time.

In the Qt command window, copy and paste the following:
```
/vis/open OGL
```
You should see a black panel appear.

Let's initialize the geometry
```
/run/initialize
```

## Making the geometry visible 

Then draw the geometry 
```
/vis/drawVolume
```

We can set the World volume invisible
``` 
/vis/geometry/set/visibility logic-World 0  false
```
or make it visible
``` 
/vis/geometry/set/visibility logic-World 0  true
/vis/geometry/set/colour logic-World 0 0 1 1 0.1
```
and control the visibility of the 'target' volume:
```
/vis/geometry/set/colour logic-Target 0 0 0 1 0.3
```
then set the style of viewing to 'surface':
```
/vis/viewer/set/style surface 
```

### Setting the scale and view

Let's add axes (orientation) and a scale (size)
```
/vis/scene/add/axes 
/vis/scene/add/scale
```

Add (smooth) trajectories 
```
/vis/scene/add/trajectories smooth
```

Set to accumulate trajectories up to 100 events
```
/vis/scene/endOfEventAction accumulate 100
```

Set the view point in terms angles 
```
/vis/viewer/set/viewpointThetaPhi -40 -50
```

## Re-enabling vis.mac

All this functionality was 'automatically' enabled previous by the line
```
UImanager->ApplyCommand("/control/execute vis.mac");
```
which read the file vis.mac and executed the same visualization commands we ran one by one above.

You can put it back -- by uncommenting it.

Note that this file must exist in the directory from which you run the Geant4 executable.  You can confirm that it won't just find it anywhere:
```shell
cd build
mkdir run-here
cd run-here
../yourMainApplication
```
If vis.mac is not copied to your new run directory, it cannot be executed.

## Alternative viz configuration

You can replace vis.mac with a different file, that has more options (many commented)
```
UImanager->ApplyCommand("/control/execute ../alt-vis.mac");
```

## Viewing a muon track

```
cd /gun
particle mu-
position -4.0 -4.0 -4.0 mm
direction  1  1  1
cd /
```
You can vary the muon energy until you see that it slows down and is captured
```
/gun/energy 500 MeV
/run/beamOn   3
/gun/energy 250 MeV
```

And then compare what you see is confirmed by the verbose output of Geant4
```
/event/verbose 1
/tracking/verbose 1
/run/beamOn 1
```