#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    grabber.initGrabber(320,240);
    colorImage.allocate(320, 240);
    currFrame.allocate(320, 240);
    prevFrame.allocate(320, 240);
    diffImage.allocate(320, 240);
    
    player.loadSound("Biz Markie - Biz'S Baddest Beats - 01 - One Tow.mp3");
    player.setLoop(true);
    player.play();
    
}

//--------------------------------------------------------------
void testApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImage.setFromPixels(grabber.getPixelsRef());
        currFrame = colorImage;
        currFrame.flagImageChanged();
        
        
        
        diffImage.absDiff( currFrame, prevFrame );
        diffImage.threshold(mouseX);
        
        int nWhitePixels = diffImage.countNonZeroInRegion(0, 0, 320, 240);
        cout << nWhitePixels << endl;
        
        float speed = ofMap(nWhitePixels, 0, 10000, 0.1, 3, true);
        player.setSpeed(speed);
        
        prevFrame = currFrame;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    grabber.draw(0,0);
    currFrame.draw(320,0);
    prevFrame.draw(0,240);
    diffImage.draw(320,240);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}