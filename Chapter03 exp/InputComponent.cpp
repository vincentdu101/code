//
//  InputComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/5/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:MoveComponent(owner)
,mForwardKey(0)
,mBackKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
    
}

void InputComponent::ProcessInput(const uint8_t* keyState) {
    // calculate forward speed for move component
    float forwardSpeed = 0.0f;
    if (keyState[mForwardKey]) {
        forwardSpeed += mMaxForwardSpeed;
    }
    
    if (keyState[mBackKey]) {
        forwardSpeed -= mMaxForwardSpeed;
    }
    
    SetForwardSpeed(forwardSpeed);
    
    // calculate angular speed for move component
    float angularSpeed = 0.0f;
    if (keyState[mClockwiseKey]) {
        angularSpeed += mMaxAngularSpeed;
    }
    
    if (keyState[mCounterClockwiseKey]) {
        angularSpeed -= mMaxAngularSpeed;
    }
    
    SetAngularSpeed(angularSpeed);
}
