//
//  Component.cpp
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder)
:mOwner(owner)
, mUpdateOrder(updateOrder)
{
    // add to actor's vector of components
    mOwner -> AddComponent(this);
}

Component::~Component() {
    mOwner -> RemoveComponent(this);
}

void Component::Update(float deltaTime) {

}


