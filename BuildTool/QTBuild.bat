x:
cd x:/AXYBEngine
rmdir /s /q ThirdPartyBuild/QT_6_10_3
mkdir ThirdPartyBuild/QT_6_10_3


cmake -S ThirdParty/QT_6_10_3 -B ThirdPartyBuild/QT_6_10_3
cmake --build ThirdPartyBuild/QT_6_10_3 -j 16
pause