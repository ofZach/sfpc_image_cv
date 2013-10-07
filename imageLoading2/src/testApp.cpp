#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    myImg.loadImage("chuckClose.png");
    myImg.setImageType(OF_IMAGE_GRAYSCALE);
    
    myImg2.allocate(myImg.width, myImg.height, OF_IMAGE_GRAYSCALE);
    
    ofSetWindowShape(myImg.width*2, myImg.height);
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    unsigned char * pixelsA = myImg.getPixels();
    unsigned char * pixelsB = myImg2.getPixels();
    
    for (int i = 0; i < myImg.width * myImg.height; i++){
        
        if (pixelsA[i] > mouseX){
            pixelsB[i] = 255;
        } else {
            pixelsB[i] = 0;
        }
        
        //pixelsB[i] =
    }
    
    myImg2.update();
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofBackground(0);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    myImg.draw(0,0);
    myImg2.draw(myImg.width, 0);
    
    
    
    
    
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