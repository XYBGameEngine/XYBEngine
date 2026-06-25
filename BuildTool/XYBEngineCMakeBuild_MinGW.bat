x:
cd x:/AXYBEngine
set "MINGW_BIN=X:\QT\Tools\mingw1310_64\bin"
set "PATH=%MINGW_BIN%;%PATH%"
rmdir /s /q Build
mkdir Build
cmake -S . -B Build -G "MinGW Makefiles" ^
  -DCMAKE_MAKE_PROGRAM=%MINGW_BIN%/mingw32-make.exe ^
  -DCMAKE_C_COMPILER=%MINGW_BIN%/gcc.exe ^
  -DCMAKE_CXX_COMPILER=%MINGW_BIN%/g++.exe ^
  -DCMAKE_PREFIX_PATH=X:/QT/6.11.1/mingw_64
cmake --build Build -j 16
pause
