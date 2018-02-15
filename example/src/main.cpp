#include "ofMain.h"
#include "ofApp.h"

#ifdef TARGET_OSX
#define _OSX
#define _x86
#endif
//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	ofSetWindowPosition(100,100);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
