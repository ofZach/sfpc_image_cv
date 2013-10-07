#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    myImg.loadImage("chuckClose.png");
    myImg.setImageType(OF_IMAGE_GRAYSCALE);
    
   
    
    ofSetWindowShape(myImg.width*2, myImg.height);
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofBackground(0);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    myImg.draw(0,0);
    
    unsigned char * pixels = myImg.getPixels();
    
//    for (int i = 0; i < myImg.width; i += 10){
//        for (int j = 0; j < myImg.width; j+=10){
//            int pixelVal = pixels[j*myImg.width + i];
//            
//            float radius = ofMap(pixelVal, 0, 255, 3, 3.6);
//            
//            ofCircle(i + myImg.width, j, radius);
//        }
//    }
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < myImg.width; i += 10){
        for (int j = 0; j < myImg.width; j+=10){
            int pixelVal = pixels[j*myImg.width + i];
            
            float angle = ofMap(pixelVal, 0, 255, 0, 180);
            
            ofPushMatrix();  // take a snapshot (identity matrix)
                ofTranslate(i + myImg.width, j);
                ofRotateZ(angle);
                ofRect(0,0, 10,2);
            ofPopMatrix();
        }
    }
    
    
    
    
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