//
//  Laser.h
//  Game-mac
//
//  Created by Vincent Du on 2/5/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Actor"
class Laser : public Actor
{
public:
    Laser(class Game* game);
    
    void UpdateActor(float deltaTime) override;

private:
    class CircleComponent* mCircle;
    float mDeathTimer;
}
