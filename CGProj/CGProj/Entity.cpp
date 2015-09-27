//
//  Entity.cpp
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#include "Entity.h"

Entity::Entity(){
    _position = Vector3(0,0,0);
}

Entity::~Entity(){
}

Vector3* Entity::getPosition(){
    return &_position;
}

Vector3* Entity::setPosition(GLdouble x, GLdouble y, GLdouble z){
    _position = Vector3(x, y, z);
    return &_position;
}

Vector3* Entity::setPosition(const Vector3& vec){
    _position = vec;
    return &_position;
}