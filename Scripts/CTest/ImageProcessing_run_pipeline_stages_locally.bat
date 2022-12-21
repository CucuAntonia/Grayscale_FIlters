@echo off

::Set variables, give values

set "ProjName=ImageProcessingApp"
set "Compiler=VS2019"
set "BuildConfig=Debug"
set "Platform=x64"

set "Stage=Config"
call ImageProcessing_run.bat "%ProjName%" "%Compiler%" "%BuildConfig%" "%Platform%" "%Stage%"

set "Stage=Build"
call ImageProcessing_run.bat "%ProjName%" "%Compiler%" "%BuildConfig%" "%Platform%" "%Stage%"

set "Stage=Test"
call ImageProcessing_run.bat "%ProjName%" "%Compiler%" "%BuildConfig%" "%Platform%" "%Stage%"
pause