
::Find CMake path

set "CMakePath="
set "CMakeProgramFilesPath=CMake\bin\ctest.exe"
set "CMakeProgramFilesX86Path=CMake\bin\ctest.exe"

echo "Trying to find CMakePath"
for %%d in (c d e f g h i j k l m n o p q r s t u v w x y z) do (
	if exist "%%d:\%CMakeProgramFilesPath%" (
		for %%i in ("%%d:\%CMakeProgramFilesPath%") do (
			set CMakePath=%%~dpi
			
		)
		goto :display_cmake
	 ) else (
		if exist "%%d:\%CMakeProgramFilesX86Path%" (
			for %%i in ("%%d:\%CMakeProgramFilesX86Path%") do (
				set CMakePath=%%~dpi
				
			)
			goto :display_cmake
			
			
		)
	)
)
:display_cmake
echo "CMakePath was found!"
echo "CMakePath: %CMakePath%" 

set "PATH=%CMakePath%;%PATH%"
set "CTestPath=%CMakePath%ctest.exe"
echo "CTestPath=%CTestPath%"



set CTestArgs=-DCompiler=%Compiler% -DPlatform=%Platform% -DBuildType=%BuildConfig%
echo "CTestArgs: %CTestArgs%"

::Config 
echo "Stage=%Stage%"
echo "Compiler=%Compiler%"
if %Stage%==Config (
	%CTestPath% %CTestArgs% -VV -S "%~dp0\ImageProcessingApp_config.cmake"
	)
	
::Build
if %Stage%==Build (
	%CTestPath% %CTestArgs% -VV -S "%~dp0\ImageProcessingApp_build.cmake"
	)

::Test
if %Stage%==Test (
	%CTestPath% %CTestArgs% -VV -S "%~dp0\ImageProcessingApp_tests.cmake"
	)