//
//  Bullet.h
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Actor.h"

class Bullet : public Actor {
public:
    Bullet(class Game* game);
    void UpdateActor(float deltaTime) override;

private:
    class CircleComponent* mCircle;
    float mLiveTime;
}
