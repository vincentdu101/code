//
//  Component.h
//  Game-mac
//
//  Created by Vincent Du on 1/31/20.
//  Copyright © 2020 Sanjay Madhav. All rights reserved.
//

#pragma once
class Component
{
public:
    // constructor
    // the lower the update order, the earlier the component updates
    Component(class Actor* owner, int updateOrder = 100);
    
    // destructor
    virtual ~Component();
    
    // update this component by deltaTime
    virtual void Update(float deltaTime);
    
    int GetUpdateOrder() const { return mUpdateOrder; }
    
protected:
    // owning actor
    class Actor* mOwner;
    
    // update order of component
    int mUpdateOrder;
};
