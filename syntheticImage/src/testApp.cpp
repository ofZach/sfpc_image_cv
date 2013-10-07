#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // typical: load an image
    // myImg.loadImage("...");
    
    // alternative: let's creat an image
    myImg.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    ofSetWindowShape(myImg.width, myImg.height);
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    unsigned char * pixels = myImg.getPixels();
    
//    1D for loop
//    for (int i = 0; i < myImg.width * myImg.height; i++){
//        pixels[i] = ofRandom(0,255);
//    }
    
    
//    for (int i = 0; i < myImg.width; i++){
//        for (int j = 0; j < myImg.height; j++){
//        
//            pixels[ j * myImg.width + i ] = i + j;
//            //((i % (j+1)) * 100;
//            
//        }
//    }
    
    
    for (int i = 0; i < myImg.width; i++){
        for (int j = 0; j < myImg.height; j++){
            
            float dist = ofDist(mouseX, mouseY, i, j);
            pixels[ j * myImg.width + i ] = dist;  // *10
            //((i % (j+1)) * 100;
            
        }
    }
    
    
    
    
    
    
    myImg.update();
    

}

//--------------------------------------------------------------
void testApp::draw(){

    myImg.draw(0,0);
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