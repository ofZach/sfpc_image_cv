#include "testApp.h"

bool bDeleteTracker( trackedBlob & b){
    if (b.bFoundThisFrame == false){
        return true;
    } else {
        return false;
    }
    
}

//--------------------------------------------------------------
void testApp::setup(){

    idCounter = 0;
    movie.loadMovie("trackingTest.mov");
    img.allocate(movie.width, movie.height);
    imgGray.allocate(movie.width, movie.height);
    movie.play();
}

//--------------------------------------------------------------
void testApp::update(){
    movie.update();
    if (movie.isFrameNew()){
        img.setFromPixels(movie.getPixelsRef());
        imgGray = img;
        imgGray.threshold(128);
        finder.findContours(imgGray, 10, 320*240, 20, false);
    
        // for every BLOB look against every tracked blobs
        // and see if one is close enough, and update that tracked blob.
        // if we don't find one, make a new tracked blob;
        // if tracked blob is not matched, delete it
        
        // reset the found counter:
        for (int i = 0; i < trackedBlobs.size(); i++){
            trackedBlobs[i].bFoundThisFrame = false;
        }
        
        // linearly search for the closest non found tracked blob.
        for (int i = 0; i < finder.blobs.size(); i++){
            
            int minIndex = -1;
            float minDistance = 10000000;
            
            for (int j = 0; j < trackedBlobs.size(); j++){
                if (trackedBlobs[j].bFoundThisFrame == false){
                    float distance = ofDist(trackedBlobs[j].pos.x,
                                            trackedBlobs[j].pos.y,
                                            finder.blobs[i].centroid.x,
                                            finder.blobs[i].centroid.y);
                    if (distance < minDistance){
                        minDistance = distance;
                        minIndex = j;
                    }
                                            
                }
            }
            
            
            if (minIndex != -1 && minDistance < 15){
                
                // WOOOHOOOO we have match..
                
                // if have a match, copy data!!!!!
                
                trackedBlobs[minIndex].pos = finder.blobs[i].centroid;
                trackedBlobs[minIndex].size = finder.blobs[i].area;
                trackedBlobs[minIndex].bFoundThisFrame = true;
                trackedBlobs[minIndex].line.addVertex(trackedBlobs[minIndex].pos);
            } else {
                
                trackedBlob temp;
                temp.pos = finder.blobs[i].centroid;
                temp.size = finder.blobs[i].area;
                temp.id = idCounter++;
                temp.line.addVertex(temp.pos);
                temp.bFoundThisFrame = true;
                trackedBlobs.push_back(temp);
                
            }
        }
        
                
        ofRemove(trackedBlobs, bDeleteTracker);
       

        
        
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofScale(2,2,1);
    ofSetColor(255);
    movie.draw(0,0);
    //finder.draw();
    
//    for (int i = 0; i < finder.blobs.size(); i++){
//        
//        ofDrawBitmapStringHighlight( ofToString(i), finder.blobs[i].centroid + ofPoint(10,0));
//    }

    ofEnableAlphaBlending();
    
//    for (int i = 0; i < trackedBlobs.size(); i++){
//        ofSetColor(255,255,255,100);
//        ofCircle(trackedBlobs[i].pos, 10);
//        ofDrawBitmapString( ofToString(trackedBlobs[i].id), trackedBlobs[i].pos + ofPoint(10,0));
//        
//    }
    
    ofNoFill();
    for (int i = 0; i < trackedBlobs.size(); i++){
        trackedBlobs[i].line.draw();
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
