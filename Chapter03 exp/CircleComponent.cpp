//
//  CircleComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/4/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "CircleComponent.h"
#include "Actor.h"

CircleComponent::CircleComponent(class Actor* owner)
:Component(owner)
,mRadius(0.0f)
{
    
}

const Vector2& CircleComponent::GetCenter() const {
    return mOwner -> GetPosition();
}

float CircleComponent::GetRadius() const {
    return mOwner -> GetScale() * mRadius;
}

bool Intersect(const CircleComponent& a, const CircleComponent& b) {
    // calculate distance squared
    Vector2 diff = a.GetCenter() - b.GetCenter();
    float distSq = diff.LengthSq();
    
    // calculate sum of radii squared
    float radiiSq = a.GetRadius() + b.GetRadius();
    radiiSq *= radiiSq;
    
    // are the two objects intercepting
    return distSq <= radiiSq;
}
