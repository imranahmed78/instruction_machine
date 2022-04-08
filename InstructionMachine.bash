#!/bin/sh

BUILDFOLDER=build

if [ ! -d "$BUILDFOLDER" ]; then
  mkdir "$BUILDFOLDER"
  echo "$BUILDFOLDER folder is created."
else
  echo "$BUILDFOLDER folder already exists"
  echo "clean"
  cd build 
  rm -rf *
  cd ..
fi

cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
./InstructionMachine