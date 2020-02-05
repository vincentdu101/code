//
//  CircleComponent.h
//  Game-mac
//
//  Created by Vincent Du on 2/4/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Component.h"
#include "Math.h"

class CircleComponent : public Component {
public:
    CircleComponent(class Actor* owner);
    
    void SetRadius(float radius) { mRadius = radius; }
    float GetRadius() const;
    
    const Vector2& GetCenter() const;
private:
    float mRadius;
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);
