//
//  Car.cpp
//  CGProj
//

#include "Car.h"
#include "Logger.h"


Car::Car()
{
    _direction.set(1,0,0);
    _position.set(0,0,0);
    
    _accel = 0.000012;
	_breakAccel = 0.0005;
    _speed = 0;
    _turnSpeed = 0.17;
    _friction = 0.00006;
    _angle = 0;
    _maxSpeed = 0.035;
    _upPressed = false;
    _downPressed = false;
    _leftPressed = false;
    _rightPressed = false;
    
}

Car::~Car()
{
}

void Car::draw()
{
    
    
    
    glPushMatrix();
    glTranslatef(_position.getX(), 0,_position.getZ());
    glRotatef(_angle, 0, 1, 0);
    glScalef(0.2,0.2,0.2);
    
    //cubo1
    glColor3f(0.33, 0.2, 0.15);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(14, 3, 8);
    glutSolidCube(1);
    glPopMatrix();
    
    //cubo2
    glColor3f(0.20, 0.21, 0.22);
    glPushMatrix();
    glTranslatef(-3.5, 3.5, 0);
    glScalef(7, 4, 8);
    glutSolidCube(1);
    glPopMatrix();
    
    //cubo3
    glColor3f(0.37, 0.34, 0-.33);
    glPushMatrix();
    glTranslatef(2.5, 2.5, 0);
    glScalef(5, 2, 4);
    glutSolidCube(1);
    glPopMatrix();
    
    //rodas frente
    glColor3f(0, 0, 0);
    glPushMatrix();
    glPushMatrix();
	   glTranslatef(4, -1.5, -4.5);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
    glPopMatrix();
    glPushMatrix();
	   glTranslatef(4, -1.5, 4.5);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
    glPopMatrix();
    glPopMatrix();
    
    //rodas tr�s
    glColor3f(0, 0, 0);
    glPushMatrix();
    glPushMatrix();
	   glTranslatef(-5.5, -0.75, -5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
    glPopMatrix();
    glPushMatrix();
	   glTranslatef(-5.5, -0.75, 5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    
}

void Car::move( GLdouble accel, GLdouble delta_t){
    
    if(accel != 0 && fabs(_speed) < _maxSpeed){
        _speed += accel*_accel*delta_t;
    }
    else if(_speed > 0 && accel == 0){
        _speed -= _friction*delta_t;
    }
    else if(accel == 0)
        _speed += _friction*delta_t;
        _position.set(_position.getX()+_direction.getX()*_speed*delta_t,0,_position.getZ()+_direction.getZ()*_speed*delta_t);
}

void Car::turn(GLdouble turn, GLdouble delta_t) {
    _angle += turn * _turnSpeed * delta_t;
    _direction.set(cos((_angle*3.14)/180), 0, -sin((_angle*3.14)/180));
    Vector3::normalize(_direction);
    
    
}

void Car::update(GLdouble delta_t) {
    
    if(_leftPressed == true && _rightPressed == false){
        turn(1, delta_t);
    }
    else if(_leftPressed == false && _rightPressed == true){
        turn(-1, delta_t);
    }
    
    
    if(_upPressed == true && _downPressed == false){
        move(1, delta_t);
    }
    else if(_upPressed == false && _downPressed == true){
        move(-1, delta_t);
    }
    else if(_speed > 0.0001 || _speed < -0.0001)
        move(0, delta_t);
}


