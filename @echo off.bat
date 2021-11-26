@echo off

for /F "usebackq tokens=1,2,3,4 " %%i in (`wmic logicaldisk get caption^,description^,drivetype 2^>NUL`) do (

if %%l equ 2 (
set "Path=%%i"
        )

        )



:choice
set /P c=Copy Opswat Files[Y/N]?
if /I "%c%" EQU "Y" goto :YES
if /I "%c%" EQU "N" goto :NO
goto :choice


:YES
echo Copying Kiosk Files
robocopy "\\ngofs\Engineering\IT6000\10 CFR 73.54\OPSWAT\v4 Updates" U:\TEST 
*.* /XD "Older Patches\" /S

:NO
echo Copying Alternate Scanners:

REM COPY "\\ngofs\Engineering\IT6000\10 CFR 73.54\OPSWAT\Laptop_Scanning_Solutions\Alternate Scanners\msert_x64.exe" %Path%
REM COPY "\\ngofs\Engineering\IT6000\10 CFR 73.54\OPSWAT\Laptop_Scanning_Solutions\Alternate Scanners\msert_x86.exe" %Path%
REM COPY "\\ngofs\Engineering\IT6000\10 CFR 73.54\OPSWAT\Laptop_Scanning_Solutions\Alternate Scanners\mcafee_6_0_6.zip" %Path%

pause   