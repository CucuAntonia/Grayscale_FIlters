@echo off
:home
cls
title run Visual Project

set "QtBin=D:\Qt\5.15.2\msvc2019_64\bin"
set "OpenCVBin=D:\OpenCV\opencv\build\x64\vc15\bin"

call :check_dir %QtBin% || goto :end_script
call :check_dir %OpenCVBin% || goto :end_script

set "PATH=%OpenCVBin%;%QtBin%;%PATH%"
call "d:\Visual Studio 2019\Common7\IDE\devenv.exe" "d:\VS_Projects\Practica_bun\Build_23_11_2022\PracticaSpring2022.sln"
exit /b

:check_dir
IF NOT EXIST %~1 ( 
	echo %~1 does not exists on your system.
	exit /b 1
) ELSE (
	echo %~1 exists on your system.
	exit /b 0
)

:end_script
echo "The program execution has stopped "
pause
exit /b 