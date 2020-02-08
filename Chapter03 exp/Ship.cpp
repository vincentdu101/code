//
//  Ship.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"

Ship::Ship(Game* game)
:Actor(game)
,mLaserCooldown(0.0f) {
    // create a sprite component
    SpriteComponent* sc = new SpriteComponent(this, 150);
    sc -> SetTexture(game -> GetTexture("Assets/Ship.png"));
    
    // create an input component and set keys/speed
    InputComponent* ic = new InputComponent(this);
    ic -> SetForwardKey(SDL_SCANCODE_W);
    ic -> SetBackKey(SDL_SCANCODE_S);
    ic -> SetClockwiseKey(SDL_SCANCODE_A);
    ic -> SetCounterClockwiseKey(SDL_SCANCODE_D);
    ic -> SetMaxForwardSpeed(300.0f);
    ic -> SetMaxAngularSpeed(Math::TwoPi);
}

void Ship::UpdateActor(float deltaTime) {
    mLaserCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState) {
    if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f) {
        // create a laser and set its position/rotation to mine
        Laser* laser = new Laser(GetGame());
        laser -> SetPosition(GetPosition());
        laser -> SetRotation(GetRotation());
        
        // reset laser cooldown (half second)
        mLaserCooldown = 0.5f;
    }
}
