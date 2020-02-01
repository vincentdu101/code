//
//  BGSpriteComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "BGSpriteComponent.h"
#include "Actor.h"

BGSpriteComponent::BGSpriteComponent(class Actor* owner, int drawOrder)
:SpriteComponent(owner, drawOrder)
, mScrollSpeed(0.0f)
{
}

void BGSpriteComponent::Update(float deltaTime) {
    SpriteComponent::Update(deltaTime);
    for (auto& bg : mBGTextures) {
        // update the x offset
        bg.mOffset.x += mScrollSpeed * deltaTime;
        
        // if this is completely off the screen, reset offset to
        // the right of the last bg texture
        if (bg.mOffset.x < -mScreenSize.x) {
            bg.mOffset.x = (mBGTextures.size() - 1) * mScreenSize.x - 1;
        }
    }
}

void BGSpriteComponent::Draw(SDL_Renderer* renderer) {
    // draw each background texture
    for (auto& bg : mBGTextures) {
        SDL_Rect r;
        // assume screen size dimensions
        r.w = static_cast<int>(mScreenSize.x);
        r.h = static_cast<int>(mScreenSize.y);
        
        // center the rectangle around the position of the owner
        r.x = static_cast<int>(mOwner -> GetPosition().x - r.w / 2 + bg.mOffset.x);
        r.y = static_cast<int>(mOwner -> GetPosition().y - r.h / 2 + bg.mOffset.y);
        
        // draw this background
        SDL_RenderCopy(renderer, bg.mTexture, nullptr, &r);
    }
}

void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture*>& textures) {
    int count = 0;
    for (auto tex : textures) {
        BGTexture temp;
        temp.mTexture = tex;
        
        // each texture is screen width in offset
        temp.mOffset.x = count * mScreenSize.x;
        temp.mOffset.y = 0;
        mBGTextures.emplace_back(temp);
        count++;
    }
}
