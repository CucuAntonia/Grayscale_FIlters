::set "ExePath = %cd%\bin"
::set "DependenciesPath = %cd%\bin"
::set "PATH=%DependenciesPath%;%ExePath%;%PATH%"
set QT_DEBUG_PLUGINS=1
start %cd%\bin\ImageProcessingApp.exe

pause