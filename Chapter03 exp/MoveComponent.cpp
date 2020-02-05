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
        
    }
}
