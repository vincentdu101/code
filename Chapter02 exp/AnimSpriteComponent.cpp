//
//  AnimSpriteComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
:SpriteComponent(owner, drawOrder)
, mCurrFrame(0.0f)
, mAnimFPS(24.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime) {
    SpriteComponent::Update(deltaTime);
    
    if (mAnimTextures.size() > 0) {
        // update the current frame based on frame rate
        // and delta time
        mCurrFrame += mAnimFPS * deltaTime;
        
        // wrap current frame if needed, reset it if it is
        while (mCurrFrame >= mAnimTextures.size()) {
            mCurrFrame -= mAnimTextures.size();
        }
        
        // set the current frame
        SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
    }
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures) {
    mAnimTextures = textures;
    if (mAnimTextures.size() > 0) {
        // set the active texture to first frame
        mCurrFrame = 0.0f;
        SetTexture(mAnimTextures[0]);
    }
}
