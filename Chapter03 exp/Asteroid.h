//
//  Asteroid.h
//  Game-mac
//
//  Created by Vincent Du on 2/4/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
    Asteroid(class Game* game);
    ~Asteroid();
    
    class CircleComponent* GetCircle() { return mCircle; }
private:
    class CircleComponent* mCircle;
};
