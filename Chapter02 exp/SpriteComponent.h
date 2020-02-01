//
//  SpriteComponent.h
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Component.h"
#include "SDL/SDL.h"

class SpriteComponent : public Component
{
public:
    // lower draw order corresponds with further back
    SpriteComponent(class Actor* owner, int drawOrder = 100);
    ~SpriteComponent();
    
    virtual void Draw(SDL_Renderer* renderer);
    virtual void SetTexture(SDL_Texture* texture);
    
    int GetDrawOrder() const { return mDrawOrder; }
    int GetTexHeight() const { return mTexHeight; }
    int GetTexWidth() const { return mTexWidth; }
protected:
    SDL_Texture* mTexture;
    int mDrawOrder;
    int mTexWidth;
    int mTexHeight;
};
