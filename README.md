# README #

Based on libPvAPI.dylib (as the libPvAPI.a won't compile with of >= 0.9).
The PvApi.h must be slightly modified.

ofxPvAPI::Camera is modelled after, but not completely compatible with, ofVideoGrabber. 
ofxPvAPI::ParamCam adds ofParameters and an ofParameterGroup to the Camera, for easy use with ofxGui.
ofxPvAPI::ParamCamExt adds extended functionality such as flip, rotate 90º,  homography warp and mono to RGB conversion

Tested with the Prosilica GC750 and the MAKO G-223B  (monochrome) and the MAKO G125C (color) on OSX 10.13 with of 0.10.

# TODO #

- [x] make for Linux
- [ ] make for Windows
- [ ] refactor parameterConnector

# FOR MAC #
tested on macOS 10.13 with OF 0.10.0 and Xcode 9.3

1.	Add `ofxPvAPI` to your addons folder
2.	Download the [legacy SDK](https://www.alliedvision.com/fileadmin/content/software/software/PvAPI/PvAPI_1.28_OSX.tgz "PvAPI_1.28_OSX.tgz") from [Allied Vision](https://www.alliedvision.com/en/support/software-downloads.html "Software Downloads") and copy the following files from the SDK to the addon.
*	 `/bin-pc/x64/libPvAPI.dylib` into `/ofxPvAPI/libs/PvAPI/lib/osx/`
*	 `/inc-pc/PvApi.h` into `/ofxPvAPI/libs/PvAPI/include`
3. 	Create example (or update your app) using the projectGenerator
4.	include libPvAPI.dylib in the example (or your app) by adding the following script to Project -> Build Phases -> Run Script
```	
# Copy libPvAPI and change install directory for PvAPI to run
rsync -aved "$OF_PATH/addons/ofxPvAPI/libs/PvAPI/lib/osx/libPvAPI.dylib" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Frameworks/";
install_name_tool -change libPvAPI.dylib @executable_path/../Frameworks/libPvAPI.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
```

*	When adding the addon manually in Xcode make sure to:
	* add the libPvAPI.dylib to Project -> Build Settings -> Other Linker Flags `../../../addons/ofxPvAPI/libs/PvAPI/lib/osx/libPvAPI.dylib`
	* add `-D_x64` to Project -> Build Settings -> Other C++ Flags
	* add `-D_OSX` to Project -> Build Settings -> Other C++ Flags

# FOR LINUX #
tested on Ubuntu 18.10 using make

1.	Add `ofxPvAPI` to your addons folder
2.	Download the [legacy SDK](https://www.alliedvision.com/fileadmin/content/software/software/PvAPI/PvAPI_1.28_Linux.tgz "PvAPI_1.28_Linux.tgz") from [Allied Vision](https://www.alliedvision.com/en/support/software-downloads.html "Software Downloads") and copy the following files from the SDK to the addon.
*	 `/lib-pc/x64/4.7/libPvAPI.a` into `/ofxPvAPI/libs/PvAPI/lib/linux/`
*	 `/inc-pc/PvApi.h` into `/ofxPvAPI/libs/PvAPI/include`
3. 	Create example with make

# KNOWN ISSUES AND FACTS #

*	The default pixel format is mono.
*	As the extended functions are performed on the texture, ParamCamExt::getPixels() gets it's pixels from the texture and is not optimized.
*	The example has no initial settings.XML file, save (right upper corner of the ofxGui) to create one.
*	The cameras don't work on wifi.
*	Sometimes it helps to turn off the Wifi
*	Sometimes it helps to turn off the Firewall.
*	Careful with the IP settings!
*	It is recommended to set the MTU to Jumbo / 9000 (System Preferences -> Network -> Ethernet -> Advanced -> Hardware -> Configure Manually -> MTU), but in my experience it also works without.
*	According to the driver attribute document the autoGain should work together with the autoExposure for best lightness result. In my experiments using them simultanious gives weird results.
*	Weird install_name_tool bug: Set app deployment target > 10.7





# FOR WINDOWS #
NOT TESTED FOR A LONG TIME below the obsolete intructions for OF 0.8.x and Windows 7, maybe they will be of some help

1.	Add `ofxPvAPI` to your addons folder
2.	Download the [legacy SDK](https://www.alliedvision.com/fileadmin/content/software/software/PvAPI/PvAPI_win_1.28.exe "PvAPI SDK for Windows  v1.28") from  [Allied Vision](https://www.alliedvision.com/en/support/software-downloads.html "Software Downloads") and copy the following files from the SDK to the addon.
*	`/inc-pc/PvApi.h` into `/ofxPvAPI/libs/PvAPI/include`
*	`/lib-pc/PvAPI.lib` into `/ofxPvAPI/libs/PvAPI/lib/win32/`
*	`PvAPI.dll` into `/ofxPvAPI/libs/PvAPI/lib/win32/`
3. 	IN Properties -> C/C++ -> additional include directories ADD
*	`..\..\..\addons\ofxPvAPI\src`
*	`..\..\..\addons\ofxPvAPI\libs\PvAPI\include`
4.	~~IN Properties -> Linker -> Additional Lybrary Directories ADD~~
*	~~* ..\..\..\addons\ofxPvApi\libs\PvAPI\lib\win32~~
*	For some reason this was not necessary, but i had to add the PvAPI.lib to the solution explorer

5.	copy `PvAPI.dll`: IN Build Events -> Post Build Event - > Command Line ADD
	`xcopy /y "$(ProjectDir)..\..\..\addons\ofxPvAPI\libs\PvAPI\lib\win32\PvAPI.dll"  "$(ProjectDir)bin"`
6.	Turn off the Firewall (cameras don't work otherwise)
