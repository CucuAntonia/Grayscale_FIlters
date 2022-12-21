@echo off
:home
cls
title run Tests
echo "Starting to run tests..."

:: Calea absoluta catre executabilul de vstest
set "ApplicationPATH="D:\Microsoft Visual Studio\2017\BuildTools\Common7\IDE\Extensions\TestPlatform""

:: Calea absoluta catre dll-ul de teste. Fiecare utilizator trebuie sa isi verifice si, ulterior, sa isi seteze calea.
set "SolutionPath=D:\VS_Projects\Practica_bun\Build_23_11_2022\bin\Debug"

:: Pentru a rula toate testele deodata, se va folosi comanda:
:: %ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Averaging"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Averaging"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Averaging"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Luminance"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Luminance"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Luminance"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Desaturation"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Desaturation"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Desaturation"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Minimum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Minimum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Minimum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Maximum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Maximum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Maximum_decomposition"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Single_color_channel"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Single_color_channel"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Single_color_channel_Blue"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Single_color_channel_Green"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Single_color_channel_Red"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Custom_gray_shades"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidNumberOfChannels_Custom_gray_shades"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage_Custom_gray_shades"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_Mat2QImage"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidInputImage_QImage2Mat"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage1Channel_Mat2QImage"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImage3Channels_Mat2QImage"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImageGrayscale8_QImage2Mat"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImageRGB32_QImage2Mat"

%ApplicationPATH%\vstest.console.exe "%SolutionPath%\Tests.dll" /TestCaseFilter:Name="ValidOutputImageRGB888_QImage2Mat"


/Logger:cmd
pause



