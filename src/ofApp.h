#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "triangleFuntion.hpp"

#include "ofLightFunction.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void systemTest();
    
    void systemDialog(string guiName);
    ofFileDialogResult dialog;
    
    triangleFunction tri;
    ofLightFunction light;
    
    ofxImGui::Gui gui;
    bool isTri = false;
    bool isSystemDialog = false;
    bool isLight = false;
};
