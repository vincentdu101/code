//
//  Ship.h
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Actor.h"

class Ship : public Actor {
public:
    Ship(class Game* game);
    
    void UpdateActor(float deltaTime) override;
    void ActorInput(const uint8_t* keyState) override;
private:
    float mLaserCooldown;
};
