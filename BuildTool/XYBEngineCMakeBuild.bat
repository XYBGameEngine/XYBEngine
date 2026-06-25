x:
cd x:/AXYBEngine
rmdir /s /q Build
mkdir Build
#cmake -S . -B Build -DCMAKE_PREFIX_PATH=X:\QT\6.11.1\mingw_64
cmake -S . -B Build 
cmake --build Build -j 16
pause