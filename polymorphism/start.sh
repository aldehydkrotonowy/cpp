#!/bin/bash
FOLDER="build"

PROGRAM_NAME=$1
echo "START"
echo "Program executable name is" $PROGRAM_NAME
echo "----------------------------------"
echo "removing target folder" $FOLDER
rm -rf $FOLDER
echo "DONE"
echo "creating fresh target folder" $FOLDER
mkdir $FOLDER
echo "entering folder"
cd $FOLDER
echo "executing cmake"
cmake ..
echo "cmake DONE"
echo "----------------------------------"
echo "starting make"
make
echo "make DONE"
echo "----------------------------------"
if [ $PROGRAM_NAME ]
then
	echo "fire program"
	./$PROGRAM_NAME
	echo "END"
else
	echo "Pass executable name as first parameter to this script: ./script.sh exename"
	echo "END"
fi