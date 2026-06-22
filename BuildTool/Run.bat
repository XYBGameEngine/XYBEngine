x:
cd x:/AXYBEngine 
for /r "./Build/Debug" %%f in (*.exe) do "%%f" & pause
