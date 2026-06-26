x:
cd x:/AXYBEngine 
for /r "./Build" %%f in (*.exe) do "%%f" & pause
