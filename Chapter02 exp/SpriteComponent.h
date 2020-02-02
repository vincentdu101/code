//
//  SpriteComponent.h
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

// pragma once reduces build times by making sure the compiler
// won't open and read the file again after the first #include
// of the file in the translation unit
#pragma once
#include "Component.h"
#include "SDL/SDL.h"

// inheritance - SpriteComponent is derived from the base class Component
class SpriteComponent : public Component
{
public:
    // constructor - lower draw order corresponds with further back
    SpriteComponent(class Actor* owner, int drawOrder = 100);
    
    // destructor method - called when an object of the class
    // goes out of scope, or whenever the delete expression
    // is done to the pointer to the object of that class
    ~SpriteComponent();
    
    // virtual function is declared in base class and redefined/overriden
    // by derived class, similar to abstract class in Java
    virtual void Draw(SDL_Renderer* renderer);
    virtual void SetTexture(SDL_Texture* texture);
    
    // get methods
    int GetDrawOrder() const { return mDrawOrder; }
    int GetTexHeight() const { return mTexHeight; }
    int GetTexWidth() const { return mTexWidth; }
protected:
    SDL_Texture* mTexture;
    int mDrawOrder;
    int mTexWidth;
    int mTexHeight;
};
