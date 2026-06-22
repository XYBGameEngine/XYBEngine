x:
cd x:/AXYBEngine
rmdir /s /q Build
mkdir Build
cmake -S . -B Build
cmake --build Build
pause