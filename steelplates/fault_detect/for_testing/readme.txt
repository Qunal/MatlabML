MATLAB Builder EX 

1. Prerequisites for Deployment 

. Verify the MATLAB Compiler Runtime (MCR) is installed and ensure you    
  have installed version 8.3 (R2014a).  

. If the MCR is not installed, do the following:
  (1) enter
  
      >>mcrinstaller
      
      at MATLAB prompt. The MCRINSTALLER command displays the 
      location of the MCR Installer.

  (2) run the MCR Installer.

Or download the Windows 32-bit version of the MCR for R2014a 
from the MathWorks Web site by navigating to

   http://www.mathworks.com/products/compiler/mcr/index.html
   

For more information about the MCR and the MCR Installer, see 
Distribution to End Users in the MATLAB Compiler documentation  
in the MathWorks Documentation Center.

NOTE: You will need administrator rights to run MCRInstaller.

2. Files to Deploy and Package

-fault_detect_1_0.dll (output from mcc)
-fault_detect.bas (VBA module file created by mcc)
-fault_detect.xla (Excel AddIn file created by mcc)
-MCRInstaller.exe
   -if end users are unable to download the MCR using the above  
    link, include it when building your component by clicking 
    the "Add MCR" link in the Deployment Tool
-This readme file

NOTE: Verify fault_detect_1_0.dll is registered on the target machine. If you have 
      trouble registering this DLL, see Troubleshooting in the MATLAB Builder EX 
      documentation in the MathWorks Documentation Center.

3. Definitions

For information on deployment terminology, go to 
http://www.mathworks.com/help. Select MATLAB Compiler > 
Getting Started > About Application Deployment > 
Application Deployment Terms in the MathWorks Documentation 
Center.
