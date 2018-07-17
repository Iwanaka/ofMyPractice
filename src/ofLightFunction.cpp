//
//  ofLightFunction.cpp
//  practiceEtc
//
//  Created by Hiromitsu Iwanaka on 2018/05/26.
//

#include "ofLightFunction.hpp"

//--------------------------------------------------------------
ofLightFunction::ofLightFunction()
:radius(180.0f)
,center(ofGetWidth()*0.5, ofGetHeight()*0.5, 0)
,pointLightAmbientColor()
,pointLightDiffuseColor()
,pointLightSpecularColor()
,pointLightPosition()
,spotLightDiffuseColor()
,spotLightSpecularColor()
,spotLightPosition()
,spotLightOrientation()
,spotLightConcetration(45)
,spotLightCutOff(50)
,directionalLightSpecularColor()
,directionalLightDiffuseColor()
,directionalLightOrientation()
,bSmoothLigiting(true)
,bPoint(true)
,bSpot(true)
,bDirectional(true)
,bBox(true)
,bSphere(true)
,useTex(true){
    
}

//--------------------------------------------------------------
ofLightFunction::~ofLightFunction(){
    
}

//--------------------------------------------------------------
void ofLightFunction::setup(){
    
    ofSetSmoothLighting(bSmoothLigiting);
    ofEnableDepthTest();
    
    ofSetBoxResolution(128);
    ofSetSphereResolution(128);
    
    pointLight.setPointLight();
    spotLight.setSpotlight();
    directionalLight.setDirectional();
    
    material.setShininess( 120 );
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    ofDisableArbTex();
    
    img.load("001.jpg");
    
    
}

//--------------------------------------------------------------
void ofLightFunction::draw(int mouseX, int mouseY){
    
    
    pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x,
                           sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y,
                           -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
    
    
    spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
    spotLight.setPosition( mouseX, mouseY, spotLightPosition[3]);
    
    ofEnableLighting();
    material.begin();
    {
        
        if(bPoint) pointLight.enable();
        if(bSpot) spotLight.enable();
        if(bDirectional) directionalLight.enable();
        
        if(useTex) img.getTexture().bind();
        
        
        ofSetColor(255, 255, 255, 255);
        ofPushMatrix();
        ofTranslate(center.x, center.y, center.z-300);
        ofRotate(ofGetElapsedTimef() * .8 * RAD_TO_DEG, 0, 1, 0);
        if(bSphere) ofDrawSphere( 0,0,0, radius);
        ofPopMatrix();
        
        
        ofPushMatrix();
        ofTranslate(center.x, center.y, -900);
        ofRotate(ofGetElapsedTimef() * .2 * RAD_TO_DEG, 0, 1, 0);
        if(bBox) ofDrawBox( 0, 0, 0, 850);
        ofPopMatrix();
        
        
        if(useTex) img.getTexture().unbind();
        
        
        if(!bPoint) pointLight.disable();
        if(bSpot) spotLight.disable();
        if(bDirectional) directionalLight.disable();
        
    }
    material.end();
    ofDisableLighting();
    
    
    
    
    ofSetColor(pointLight.getDiffuseColor());
    if(bPoint) pointLight.draw();
    
    ofSetColor( spotLight.getDiffuseColor() );
    if(bSpot) spotLight.draw();
}

//--------------------------------------------------------------
void ofLightFunction::ImGui(string guiName){
    
    
    ImGui::Begin(guiName.c_str());
    {
    
        ImGui::PushID("light param");
        {
            
            ImGui::SliderFloat("radius", &radius, 10.0f, 360.0f);
            ImGui::Checkbox("tex", &useTex); ImGui::SameLine(100);
            ImGui::Checkbox("box", &bBox);ImGui::SameLine(200);
            ImGui::Checkbox("sphere", &bSphere);
            
            if(ImGui::Checkbox("smooth light", &bSmoothLigiting)){
                ofSetSmoothLighting(bSmoothLigiting);
            }
            
        }
        ImGui::PopID();
        
        
        ImGui::PushID("point light");
        {
            
            ImGui::Checkbox("point", &bPoint);
            
            //全体の色
            if(ImGui::ColorEdit3("point ambient light color", pointLightAmbientColor)){
                
                ofFloatColor col;
                col.set(pointLightAmbientColor[0], pointLightAmbientColor[1], pointLightAmbientColor[2]);
                pointLight.setAmbientColor(col);
                
            }
            
            //反射しているところの色
            if(ImGui::ColorEdit3("point diffuse light color", pointLightDiffuseColor)){
                
                ofFloatColor col;
                col.set(pointLightDiffuseColor[0], pointLightDiffuseColor[1], pointLightDiffuseColor[2]);
                pointLight.setDiffuseColor(col);
                
            }
            
            //強く反射しているところの反射
            if(ImGui::ColorEdit3("point specular light color", pointLightSpecularColor)){
                
                ofFloatColor col;
                col.set(pointLightSpecularColor[0], pointLightSpecularColor[1], pointLightSpecularColor[2]);
                pointLight.setSpecularColor(col);
                
            }
            
            
        }
        ImGui::PopID();
        
        
        
        ImGui::PushID("spot");
        {
            
            ImGui::Checkbox("spot", &bSpot);
            
            
            if(ImGui::ColorEdit3("spot ambient light color", spotLightAmbientColor)){
                
                ofFloatColor col;
                col.set(spotLightAmbientColor[0], spotLightAmbientColor[1], spotLightAmbientColor[2]);
                spotLight.setAmbientColor(col);
                
            }
            
            if(ImGui::ColorEdit3("spot diffuse light color", spotLightDiffuseColor)){
                
                ofFloatColor col;
                col.set(spotLightDiffuseColor[0], spotLightDiffuseColor[1], spotLightDiffuseColor[2]);
                spotLight.setDiffuseColor(col);
                
            }
            
            if(ImGui::ColorEdit3("spot specular light color", spotLightSpecularColor)){
                
                ofFloatColor col;
                col.set(spotLightSpecularColor[0], spotLightSpecularColor[1], spotLightSpecularColor[2]);
                spotLight.setSpecularColor(col);
                
            }
            
            if(ImGui::SliderInt("spot light cut off", &spotLightCutOff, 0, 90)){
                spotLight.setSpotlightCutOff(spotLightCutOff);
            }
            
            if(ImGui::SliderInt("spot light consentration", &spotLightConcetration, 0, 128)){
                spotLight.setSpotConcentration(spotLightConcetration);
            }

        }
        ImGui::PopID();
        
        
        ImGui::PushID("directional");
        {
            
            ImGui::Checkbox("directional", &bDirectional);
            
            
            if(ImGui::ColorEdit3("directional ambient light color", directionalLightAmbientColor)){
                
                ofFloatColor col;
                col.set(directionalLightAmbientColor[0], directionalLightAmbientColor[1], directionalLightAmbientColor[2]);
                directionalLight.setAmbientColor(col);
                
            }
            
            
            if(ImGui::ColorEdit3("directional diffuse light color", directionalLightDiffuseColor)){
                
                ofFloatColor col;
                col.set(directionalLightDiffuseColor[0], directionalLightDiffuseColor[1], directionalLightDiffuseColor[2]);
                directionalLight.setDiffuseColor(col);
                
            }
            
            if(ImGui::ColorEdit3("directional specular light color", directionalLightSpecularColor)){
                
                ofFloatColor col;
                col.set(directionalLightSpecularColor[0], directionalLightSpecularColor[1], directionalLightSpecularColor[2]);
                directionalLight.setSpecularColor(col);
                
            }
            
            if(ImGui::SliderFloat3("directional light orientation", directionalLightOrientation, 0, 360)){
                directionalLight.setOrientation(ofVec3f(directionalLightOrientation[0], directionalLightOrientation[1],directionalLightOrientation[2]));
            }
            
        }
        ImGui::PopID();
        
    }
    ImGui::End();
    
    
}
