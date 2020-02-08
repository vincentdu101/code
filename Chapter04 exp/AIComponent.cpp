//
//  AIComponent.cpp
//  Game-mac
//
//  Created by Vincent Du on 2/7/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#include "AIComponent.h"
#include "Actor.h"
#include "AIState.h"
#include <SDL/SDL_log.h>

AIComponent::AIComponent(class Actor* owner)
:Component(owner)
,mCurrentState(nullptr) {
    
}

void AIComponent::Update(float deltaTime) {
    if (mCurrentState) {
        mCurrentState -> Update(deltaTime);
    }
}

void AIComponent::ChangeState(const std::string& name) {
    // first exit the current state
    if (mCurrentState) {
        mCurrentState -> OnExit();
    }
    
    // try to find the new state from the map
    auto iter = mStateMap.find(name);
    if (iter != mStateMap.end()) {
        mCurrentState = iter -> second;
        
        // we're entering the new state
        mCurrentState -> OnEnter();
    } else {
        SDL_Log("Could not find AIState %s in state map", name.c_str());
        mCurrentState = nullptr;
    }
}

void AIComponent::RegisterState(AIState* state) {
    mStateMap.emplace(state -> GetName(), state);
}
