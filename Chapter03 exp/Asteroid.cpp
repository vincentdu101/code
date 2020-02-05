//
//  Asteroid.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/4/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

// dynamically allocate classes
Asteroid::Asteroid(Game* game)
    :Actor(game)
    ,mCircle(nullptr)
{
    // initialize to random position/orientation
    Vector2 randPos = Random::GetVector(Vector2::Zero,
                                        Vector2(1024.0f, 768.0f));
    SetPosition(randPos);
    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));
    
    // create a sprite component
    SpriteComponent* sc = new SpriteComponent(this);
    sc -> SetTexture(game -> GetTexture("Assets/Asteroid.png"));
    
    // create a move component and set a forward speed
    MoveComponent* mc = new MoveComponent(this);
    mc -> SetForwardSpeed(150.0f);
    
    // create a circle component for collision
    mCircle = new CircleComponent(this);
    mCircle -> SetRadius(40.0f);
    
    // add to mAsteroids in game
    game -> AddAsteroid(this);
}

Asteroid::~Asteroid() {
    GetGame() -> RemoveAsteroid(this);
}
