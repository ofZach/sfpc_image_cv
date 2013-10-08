#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    pizzaShirt.loadImage("pizzaShirt.png");
    pizzaShirt.setImageType(OF_IMAGE_GRAYSCALE);
    
    pizzaShirtModified.allocate(pizzaShirt.width, pizzaShirt.height, OF_IMAGE_GRAYSCALE);
    
    ofSetWindowShape(pizzaShirt.width*2, pizzaShirt.height);

}

//--------------------------------------------------------------
void testApp::update(){

    
    unsigned char * origPixels = pizzaShirt.getPixels();
    unsigned char * newPixels = pizzaShirtModified.getPixels();
    
    int w = pizzaShirt.width;
    int h = pizzaShirt.height;
    
    
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            
            int i_m_1 = i - 1;
            int i_p_1 = i + 1;
            
            if (i_m_1 < 0) i_m_1 = 0;
            if (i_p_1 > w-1) i_p_1 = w-1;
            
            int j_m_1 = j - 1;
            int j_p_1 = j + 1;
            
            if (j_m_1 < 0) j_m_1 = 0;
            if (j_p_1 > h-1) j_p_1 = h-1;
            
            
            
            int ne = (j_m_1) * w + (i_p_1);
            int n_ = (j_m_1) * w + (i+0);
            int nw = (j_m_1) * w + (i_m_1);
            int w_ = (j+0) * w + (i_m_1);
            int sw = (j_p_1) * w + (i_m_1);
            int s_ = (j_p_1) * w + (i+0);
            int se = (j_p_1) * w + (i_p_1);
            int e_ = (j+0) * w + (i_p_1);
            int me = (j+0) * w + (i+0);   // <---- y * w + x
            
            
//            newPixels[me]       =   -1 * origPixels[ne] +
//                                    -1 * origPixels[n_] +
//                                    -1 * origPixels[nw] +
//                                    -1 * origPixels[w_] +
//                                    -1 * origPixels[sw] +
//                                    -1 * origPixels[s_] +
//                                    -1 * origPixels[se] +
//                                    -1 * origPixels[e_] +
//                                     9 * origPixels[me];
            
            newPixels[me]       =   (1 * origPixels[ne] +
                                    1 * origPixels[n_] +
                                    1 * origPixels[nw] +
                                    1 * origPixels[w_] +
                                    1 * origPixels[sw] +
                                    1 * origPixels[s_] +
                                    1 * origPixels[se] +
                                    1 * origPixels[e_] +
                                     1 * origPixels[me]) / 9.0;
        }
    }
    
    pizzaShirtModified.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    pizzaShirt.draw(0,0);
    pizzaShirtModified.draw(pizzaShirt.width, 0);

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