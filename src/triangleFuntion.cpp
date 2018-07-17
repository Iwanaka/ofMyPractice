//
//  triangleFuntion.cpp
//  mySketch
//
//  Created by Hiromitsu Iwanaka on 2018/05/20.
//

#include "triangleFuntion.hpp"


//    ofLerpRadians(30, 60, 0.5);
//    ofDegToRad(50);
//    ofRadToDeg(50);
//    ofAngleDifferenceRadians(10, 30);
//    ofWrapDegrees(50);


triangleFunction::triangleFunction(){
    
}

//--------------------------------------------------------------
triangleFunction::~triangleFunction(){
    
}

//--------------------------------------------------------------
void triangleFunction::draw(float mouseX, float mouseY){
    
    //角度 斜辺 底辺 高さのいずれか2つが分かって入れば残りの２つが算出できる
    //原点からマウスの位置までの距離を斜辺とする
    syahen = sqrt(pow(mouseX - 0, 2) + pow(mouseY - 0, 2));
    teihen = mouseX;
    takasa = mouseY;
    ensyu = TWO_PI * teihen;
    
    //底辺と高さを入れて角度θとしてラジアンを出す
    //ラジアンは円の半径に等しい孤の長さを表す
    rad = atan2(teihen, takasa);
    
    
    
    ofDrawCircle(0, 0, 3);
    
    ofDrawCircle(mouseX, mouseY, 5);
    
    ofNoFill();
    ofDrawTriangle(0, 0, mouseX, 0, mouseX, mouseY);
    ofDrawTriangle(0, 0, mouseX, 0, mouseX, -mouseY);
    ofDrawTriangle(0, 0, -mouseX, 0, -mouseX, mouseY);
    ofDrawTriangle(0, 0, -mouseX, 0, -mouseX, -mouseY);
    
    ofDrawTriangle(0, 0, mouseY, 0, mouseY, mouseX);
    ofDrawTriangle(0, 0, mouseY, 0, mouseY, -mouseX);
    ofDrawTriangle(0, 0, -mouseY, 0, -mouseY, mouseX);
    ofDrawTriangle(0, 0, -mouseY, 0, -mouseY, -mouseX);
    ofFill();
    
    //radの角度に応じてサークルを描画 TWO_PI は円周率の二倍
    //基本的に斜辺が円の描画位置と思う 半径となるものが斜辺
    //2πに孤の長さradを割って個数をだす
    int number = floor(TWO_PI /abs(rad));
    
    if(number > 0){
        for(int i = 0; i < number; i++){
            float angle = (TWO_PI / (float)number) * i;
            ofDrawCircle(syahen * cos(angle), syahen * sin(angle), 5);
        }
    }
    
    int radius = 30;
    for(int i = 0;i<20;i++){
        
        float angle = (TWO_PI / 20) * i;
        
        ofDrawCircle(radius * cos(angle), radius * sin(angle), 1);
        
    }
}

//--------------------------------------------------------------
void triangleFunction::ImGui(string guiName){
    
    
    ImGui::Begin(guiName.c_str());
    {
        
        ImGui::Text("===== PI =====");
        ImGui::Text("PI");
        ImGui::Text("%s", ofToString(PI).c_str());
        
        ImGui::Text("TWO_PI");
        ImGui::Text("%s",ofToString(TWO_PI).c_str());
        
        ImGui::Text("===== radian =====");
        ImGui::Text("%s",ofToString(rad).c_str());
        ImGui::Text("%s",ofToString(180 / PI).c_str());
        
        
        ImGui::Text("===== deg =====");
        ImGui::Text("%s",ofToString(ofRadToDeg(rad)).c_str());
        ImGui::Text("%s",ofToString(PI / 180).c_str());
        
        ImGui::Text("===== ensyu =====");
        ImGui::Text("%s",ofToString(ensyu).c_str());
        ImGui::Text("%s",ofToString(TWO_PI * rad).c_str());
        
        
        ImGui::Text("===== teihen =====");
        ImGui::Text("%s",ofToString(teihen).c_str());
        ImGui::Text("%s",ofToString(cos(rad)).c_str());
        
        
        ImGui::Text("===== shyahen =====");
        ImGui::Text("%s",ofToString(syahen).c_str());
        ImGui::Text("%s",ofToString(sin(rad)).c_str());
        
        
        ImGui::Text("===== takasa =====");
        ImGui::Text("%s",ofToString(takasa).c_str());
        ImGui::Text("%s",ofToString(tan(rad)).c_str());
        
    }
    ImGui::End();
    
}
