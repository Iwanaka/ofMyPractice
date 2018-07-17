#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
    
    light.setup();
    
    gui.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float mx = ofGetMouseX();
    float my = ofGetMouseY();
    
    
    if(isTri) {
        
        mx -= ofGetWidth()/2;
        my -= ofGetHeight()/2;
        
        ofPushMatrix();
        
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        tri.draw(mx, my);
        
        ofPopMatrix();
    }
    
    
    if(isLight){
        
        light.draw(mx, my);
        
    }
    
    
    gui.begin();
    {
        ImGui::Begin("host");
        {
            ImGui::Text("mouse pos");
            ImGui::Text("%s", ofToString(mx).c_str());
            ImGui::Text("%s", ofToString(my).c_str());
            
            ImGui::Checkbox("isTri", &isTri);
            ImGui::Checkbox("isSystemDialog", &isSystemDialog);
            ImGui::Checkbox("isLight", &isLight);
            
            if(ImGui::Button("system")){
                systemTest();
            }
            
        }
        ImGui::End();
        
        if(isTri) tri.ImGui("triangleFinction");
        if(isSystemDialog) systemDialog("systemDialog");
        if(isLight) light.ImGui("light");
    }
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
