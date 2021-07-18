@echo off
mkdir build
cd build
cmake ../ -A x64 -G "Visual Studio 17 2022"
pause