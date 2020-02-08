//
//  Enemy.h
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Actor.h"

class Enemy : public Actor {
public:
    Enemy(class Game* game);
    ~Enemy();
    void UpdateActor(float deltaTime) override:
    class CircleComponent* GetCircle() { return mCircle; }
private:
    class CircleComponent* mCircle;
}
