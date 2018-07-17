//
//  other.cpp
//  practiceEtc
//
//  Created by Hiromitsu Iwanaka on 2018/05/20.
//

#include <stdio.h>
#include "ofMain.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::systemTest(){
    
    int result;
    stringstream ss;
    ss << "ifconfig >> ../test.txt";
    result = system(ss.str().c_str());
    
    
    ofLog() << "====================";
    
    printf("%d \n",result);
    
    ofLog() << "====================";
    
    printf("%d \n",WEXITSTATUS(result));
    
    ofLog() << "====================";
    
    string test1 = ofToString(result);
    string test2 = ofToString(WEXITSTATUS(result));
    
    ofLog() << test1;
    ofLog() << test2;
}

//--------------------------------------------------------------
void ofApp::systemDialog(string guiName){
    
    //change default path
    //ofToDataPath("");
    
    ImGui::Begin("systemDialog");
    {
        if(ImGui::Button("ofSystemAlertDialog")){
            ofSystemAlertDialog("test");
        }
        if(ImGui::Button("ofSystemLoadDialog")){
            //input to ofFileDialogResult from ofSystemLoadDialog
            dialog = ofSystemLoadDialog();
            if(dialog.bSuccess){
                ofLog() << dialog.getName();
                ofLog() << dialog.getPath();
            }
        }
        if(ImGui::Button("ofSystemSaveDialog")){
            ofSystemSaveDialog("test." + ofToLower("TXT"), "save your file");
            if(dialog.bSuccess){
                //input here, you want file for save
                ofLog() << "save";
            }
        }
        if(ImGui::Button("ofSystemTextBoxDialog")){
            ofLog() << ofSystemTextBoxDialog("qustion");
        }
    }
    ImGui::End();
    
}


//--------------------------------------------------------------

//--------------------------------------------------------------

//--------------------------------------------------------------
