//
//  triangleFuntion.hpp
//  mySketch
//
//  Created by Hiromitsu Iwanaka on 2018/05/20.
//

#ifndef triangleFuntion_hpp
#define triangleFuntion_hpp

#include "ofxImGui.h"
#include "ofMain.h"

class triangleFunction{
    
public:
    triangleFunction();
    ~triangleFunction();
    
    
    void draw(float mouseX, float mouseY);
    
    void ImGui(string guiName);
    
private:
    
    
    float rad = 0.0;
    float teihen = 0.0;
    float syahen = 0.0;
    float takasa = 0.0;
    float ensyu = 0.0;
    
};


#endif /* triangleFuntion_hpp */
