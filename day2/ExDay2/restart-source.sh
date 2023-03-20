
#  (Re)create here the full set of files required for the application
#   - the changed / new files     in this directory
#   - copying the original files  from  day1/ExDay1
#  and create a tar-ball with the full set.
# 
#  2021.05.18  -- J. Apostolakis
#
#

CP="cp -i"  # For first time copying

echo "1. Copying remaining files from ExDay1"

# ./
#  $CP ../../day1/ExDay1/CMakeLists.txt .
#  $CP ../../day1/ExDay1/vis.mac        .

MainFiles="CMakeLists.txt vis.mac"
for file in $MainFiles
do
   $CP ../../day1/ExDay1/$file  . 
done

mkdir -p include src

# include
#---------
#  $CP ../../day1/ExDay1/include/Your{PrimaryGeneratorAction,DetectorConstruction}.hh ./include
IncludeFiles="YourDetectorConstruction.hh YourActionInitialization.hh YourPrimaryGeneratorAction.hh"
for file in $IncludeFiles
do
   $CP ../../day1/ExDay1/include/$file ./include
done

# src
#------
# $CP ../../day1/ExDay1/src/YourPrimaryGeneratorAction.cc ./src
SrcFiles1="YourActionInitialization.cc YourPrimaryGeneratorAction.cc "
for srcfile in $SrcFiles1
do
   $CP ../../day1/ExDay1/src/$srcfile                       ./src
done   
$CP    ../../day1/Solution-A2/YourDetectorConstruction.cc   ./src

tarfile="ExDay2.tar"

echo "2. Creating tarball $tarfile"

if [[ ! -f $tarfile ]] then
   tar cvf $tarfile yourMainApplication.cc include/*.hh src/*.cc || echo "Problem creating tar-ball $tarfile"
else
   echo "ERROR> Refusing to create tar files $tarfile -- as it exists already. "
   ls -l $tarfile   
   exit
fi

echo "Here it is: "
ls -l $tarfile

echo "Done"
