//
//  AnimSpriteComponent.h
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent : public SpriteComponent {
public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
    
    // update animation every frame (overriden from component)
    void Update(float deltaTime) override;
    
    // set the textures used for animation
    void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
    
    // set/get the animation FPS
    float GetAnimFPS() const { return mAnimFPS; }
    void SetAnimFPS(float fps) { mAnimFPS = fps; }
    
private:
    // all textures in the animation
    std::vector<SDL_Texture*> mAnimTextures;
    
    // current frame displayed
    float mCurrFrame;
    
    // animation frame rate
    float mAnimFPS;
};
