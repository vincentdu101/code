//
//  MoveComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/5/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
:Component(owner, updateOrder)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
{
    
}

void MoveComponent::Update(float deltaTime) {
    if (!Math::NearZero(mAngularSpeed)) {
        float rot = mOwner -> GetRotation();
        rot += mAngularSpeed * deltaTime;
        mOwner -> SetRotation(rot);
    }
    
    if (!Math::NearZero(mForwardSpeed)) {
        Vector2 pos = mOwner -> GetPosition();
        pos += mOwner -> GetForward() * mForwardSpeed * deltaTime;
        
        // screen wrapping code for asteroids
        if (pos.x < 0.0f) { pos.x = 1022.0f;}
        else if (pos.x > 1024.0f) { pos.x = 2.0f; }
        
        if (pos.y < 0.0f) { pos.y = 766.0f; }
        else if (pos.y > 768.0f) { pos.y = 2.0f; }
        
        mOwner -> SetPosition(pos);
    }
}
