//
//  ofLightFunction.hpp
//  practiceEtc
//
//  Created by Hiromitsu Iwanaka on 2018/05/26.
//

#ifndef ofLightFunction_hpp
#define ofLightFunction_hpp

#include "ofMain.h"
#include "ofxImGui.h"

class ofLightFunction{
    
public:
    ofLightFunction();
    ~ofLightFunction();
    
    void setup();
    
    void draw(int mouseX,int mouseY);
    
    void ImGui(string guiName);
  
private:
    
    ofLight pointLight;
    ofLight spotLight;
    ofLight directionalLight;
    
    float pointLightAmbientColor[3];
    float pointLightDiffuseColor[3];
    float pointLightSpecularColor[3];
    float pointLightPosition[3];
    bool bPoint;
    
    
    float spotLightAmbientColor[3];
    float spotLightDiffuseColor[3];
    float spotLightSpecularColor[3];
    float spotLightOrientation[3];
    float spotLightPosition[3];
    int spotLightCutOff;
    int spotLightConcetration;
    bool bSpot;
    
    
    float directionalLightAmbientColor[3];
    float directionalLightDiffuseColor[3];
    float directionalLightSpecularColor[3];
    float directionalLightOrientation[3];
    bool bDirectional;
    
    ofVec3f center;
    float radius;
    bool bSmoothLigiting;
    bool useTex;
    bool bBox;
    bool bSphere;
    
    ofMaterial material;
    ofImage img;
    
};

#endif /* ofLightFunction_hpp */
