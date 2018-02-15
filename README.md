# TODO #

* fix reset of parameters on connection reset
* fix tearing
* make threaded
* linux / windows

# README #

openframeworks > 0.9 addon for use with Allied Vision Prosilica cameras.
Based on previously private repository for openframeworks < 8.4.
The static libPvAPI.a would not compile with OF 0.9, after switching to the dynamic library things worked out although libPvAPI.dylib needs to be copied into directory of the application that depends on it.
The PvApi.h must be slightly modified (see below)

Tested with the Prosilica GC750 (monochrome) and the Mako G-125C (color) on OSX 10.13
previous versions tested on Windows 7


# FOR MAC #

1.	Add `ofxProsilica' to your addons folder
1.	Download the legacy SDK from [Allied Vision](https://www.alliedvision.com/en/support/software-downloads.html "software-downloads") and copy the following files from the SDK to the addon.
⋅⋅*	 `/inc-pc/PvApi.h` into `/ofxProsilica/libs/PvAPI/include`
⋅⋅*	 `/lib-pc/x86/4.2/libPvAPI.dylib` into `/ofxProsilica/libs/PvAPI/lib/osx/`
2. 	modify `PvApi.h` to include
`
#ifdef TARGET_OSX
#define _OSX
#define _x86
#endif
`
before `#ifndef PVAPI_H_INCLUDE` will do fine
3.	Create example or app using the projectGenerator
4. 	When adding the addon manually add the ibPvAPI.dylib to Project -> Build Settings -> Other Linker Flags
	`../../../addons/ofxProsilica/libs/PvAPI/lib/osx/libPvAPI.dylib`
5. 	Copy libPvAPI.dylib into the projects bin folder
6. 	Turn off the Firewall
7. 	~~Set MTU to Jumbo / 9000 (System Preferences -> Network -> Ethernet -> Advanced -> Hardware -> Configure Manually -> MTU)~~



# FOR WINDOWS #

NOT TESTED FOR OF 0.9 / Win 10, but procedure should be similar

1.	Add `ofxProsilica' to your addons folder
2.	Download the legacy SDK from [Allied Vision](https://www.alliedvision.com/en/support/software-downloads.html "software-downloads") and copy the following files from the SDK to the addon.
⋅⋅*	`/inc-pc/PvApi.h` into `/ofxProsilica/libs/PvAPI/include`
⋅⋅*	 `/lib-pc/PvAPI.lib` into `/ofxProsilica/libs/PvAPI/lib/win32/`
⋅⋅*	`PvAPI.dll` into `/ofxProsilica/libs/PvAPI/lib/win32/`
3. 	IN Properties -> C/C++ -> additional include directories ADD
⋅⋅*	`..\..\..\addons\ofxProsilica\src`
⋅⋅*	`..\..\..\addons\ofxProsilica\libs\PvAPI\include`
4.	~~IN Properties -> Linker -> Additional Lybrary Directories ADD~~
⋅⋅*	~~* ..\..\..\addons\ofxProsilica\libs\PvAPI\lib\win32~~
⋅⋅For some reason this was not necessary, but i had to add the PvAPI.lib to the solution explorer

5.	copy `PvAPI.dll`: IN Build Events -> Post Build Event - > Command Line ADD `xcopy /y "$(ProjectDir)..\..\..\addons\ofxProsilica\libs\PvAPI\lib\win32\PvAPI.dll"  "$(ProjectDir)bin"`
6.	Turn off the Firewall (cameras don't work otherwise)


# KNOWN ISSUES AND FACTS#

* Turn off the Firewall!
* when setting persistentIP to false, unplug and replug the the camera.
* when setting persistentIP to true make sure you know what you are doing.
* the default pixel format is mono, deal with it.
* according to the driver attribute document the autoGain should work together with the autoExposure for best lightness result. In my experiments using them simultanious gives weird results.
* the example has no initial settings.XML file, save (right upper corner of the ofxGui) to create one.
* The cameras don't work great on wifi, but on low resolutions they might work.
* Sometimes it helps to turn of the Wifi



