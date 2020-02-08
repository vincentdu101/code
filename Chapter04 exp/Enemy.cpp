//
//  Enemy.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "Enemy.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "NavComponent.h"
#include "Grid.h"
#include "Tile.h"
#include "CircleComponent.h"
#include <algorithm>

Enemy::Enemy(class Game* game)
:Actor(game)
{
    // add to enemy vector
    game -> GetEnemies().emplace_back(this);
    
    SpriteComponent* sc = new SpriteComponent(this);
    sc -> SetTexture(game -> GetTexture("Assets/Airplane.png"));
    
    // set position at start tile
    SetPosition(GetGame() -> GetGrid() -> GetStartTile() -> GetPosition());
    
    // setup a nav component at the start tile
    NavComponent* nc = new NavComponent(this);
    nc -> SetForwardSpeed(150.0f);
    nc -> StartPath(GetGame() -> GetGrid() -> GetStartTile());
    
    // set up a circle for collision
    mCircle = new CircleComponent(this);
    mCircle -> SetRadius(25.0f);
}

Enemy::~Enemy() {
    // remove from enemy vector
    auto iter = std::find(GetGame() -> GetEnemies().begin(),
                          GetGame() -> GetEnemies().end(),
                          this);
    GetGame() -> GetEnemies().erase(iter);
}

void Enemy::UpdateActor(float deltaTime) {
    Actor::UpdateActor(deltaTime);
    
    // am i near the end title?
    Vector2 diff = GetPosition() - GetGame() -> GetGrid() -> GetEndTile() -> GetPosition();
    if (Math::NearZero(diff.Length(), 10.0f)) {
        SetState(EDead);
    }
}
