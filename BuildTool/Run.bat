x:
cd x:/AXYBEngine 
for /r "./Build/Samples/FirstDemo/Debug" %%f in (*.exe) do "%%f" & pause
