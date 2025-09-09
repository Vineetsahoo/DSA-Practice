@echo off
REM Batch script to automatically move .exe files to output folder

REM Create output folder if it doesn't exist
if not exist "output" mkdir output

REM Move all .exe files to output folder
for %%f in (*.exe) do (
    echo Moving %%f to output folder...
    move "%%f" "output\"
)

echo All .exe files moved to output folder!
pause
