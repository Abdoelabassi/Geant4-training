
## Using Geant4 built-in scorers via UI

A different way to score is to use the built-in scoring system of Geant4.

### 1. Activate UI-based scoring 
First you need to activate it, by adding the following lines in the main() of your program:
```
 // Activate UI-command base scorer
 G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
 scManager->SetVerboseLevel(1);

// The capabilities are from RE03UserScorerWriter 
//====================================================================
```

### 2. Selecting a scoring geometry

Step 2: we issue UI commands to create a scoring mesh:

```
# define scoring mesh
#
/score/create/boxMesh boxMesh_1
#
/score/mesh/boxSize  5.  5.   5. mm
/score/mesh/nBin   100 100  100
#
```
This mesh is in a parallel geometry -- it can overlap with existing volumes.

### 3. Select quantities to score.
```
/score/quantity/energyDeposit eDep
/score/quantity/nOfStep nOfStepGamma
/score/filter/particle gammaFilter gamma
#
/score/close
/score/list
```

### 4. Disable visualisation and run

Disable visualization temporarily
```
/vis/disable
/control/verbose 2
/run/verbose 1
```
then run a few events
```
/gun/particle e-
/run/beamOn   500
```
and re-enable visualisation
```
/vis/enable
```

### 5. View the results

Now we have results that we can now visualize one by one:
```
/score/drawProjection boxMesh_1 eDep
/score/drawProjection boxMesh_1 nOfStepGamma
```

It is possible to draw the slices using a new scene and viewer
```
/vis/open OGL
/vis/drawVolume world
/vis/viewer/copyViewFrom viewer-0
/score/colorMap/setMinMax ! 0. 800.
/control/loop draw-slice.mac iColumn 0 5 1
```

Finally we dump the results of a scorers to a file
```
/score/dumpQuantityToFile boxMesh_1 nOfStepGamma nOfStepGamma.txt
```

You can find additional scorers in run-score.mac

These capabilities are copied from the following example: examples/extended/runAndEvent/RE03