#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

//-------------------------------------
class trackedBlob {

    public:
    
        int size;
        ofPoint pos;
        int id;
        bool bFoundThisFrame;
        ofPolyline line;
};

//-------------------------------------
class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofVideoPlayer movie;
    ofxCvColorImage img;
    ofxCvGrayscaleImage imgGray;
    ofxCvContourFinder finder;
    
    vector < trackedBlob > trackedBlobs;
    int idCounter;
    
    
    
};
