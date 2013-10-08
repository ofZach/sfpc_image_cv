#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    grabber.initGrabber(320,240);
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    diffImage.allocate(320, 240);
    
    bTakeBackground = true;
}

//--------------------------------------------------------------
void testApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImage.setFromPixels(grabber.getPixelsRef());
        grayImage = colorImage;
        grayImage.flagImageChanged();
        
        if (bTakeBackground == true){
            bg = grayImage;
            bTakeBackground = false;
        }
        
        // abs(-10) = 10
        // | |
        // abs(10) = 10;
        
        diffImage.absDiff( bg, grayImage );
        diffImage.threshold(mouseX);
        
        for (int i = 0; i < mouseY / 10; i++){
            diffImage.erode_3x3();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    grabber.draw(0,0);
    grayImage.draw(320,0);
    bg.draw(0,240);
    diffImage.draw(320,240);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == ' ' ){
        bTakeBackground = true;
    }
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