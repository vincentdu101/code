//
//  Bullet.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "Bullet.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleComponent.h"
#include "Game.h"
#include "Enemy.h"

Bullet::Bullet(class Game* game)
:Actor(game)
{
    SpriteComponent* sc = new SpriteComponent(this);
    sc -> setTexture(game -> GetTexture("Assets/Projectile.png"));
    
    MoveComponent* mc = new MoveComponent(this);
    mc -> SetForwardSpeed(400.0f);
    
    mCircle = new CircleComponent(this);
    mCircle -> SetRadius(5.0f);
    
    mLiveTime = 1.0f;
}

void Bullet::UpdateActor(float deltaTime) {
    Actor::UpdateActor(deltaTime);
    
    // check for collision vs enemies
    for (Enemy* e : GetGame() -> GetEnemies()) {
        if (Intersect(*mCircle, *(e -> GetCircle()))) {
            // we both die on collision
            e -> SetState(EDead);
            SetState(EDead);
            break;
        }
    }
    
    mLiveTime -= deltaTime;
    if (mLiveTime <= 0.0f) {
        // time limit hit, die
        SetState(EDead);
    }
}
