//
//  Butter.cpp
//  CGProj
//

#include "Butter.h"

GLboolean Butter::checkOutOfBounds()
{
	GLdouble x = _position.getX(), z = _position.getZ();
	if (x > 75 || x < -75 || z > 50 || z < -50)
		return true;
	return false;
}

Butter::Butter()
{
    _hascollider = true;
    _collisionradius *= 1;
    _friction = 0.00002;
}

Butter::Butter(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
    _hascollider = true;
    _collisionradius *= 1;
    _friction = 0.00002;
	
}

Butter::~Butter()
{
}

void Butter::render()
{
    glPushMatrix();
     glTranslated(0,-0.3f, 0);
     glScalef(1.5f, 1.5f, 1.5f);
    //Body
     glPushMatrix();
      glColor3f(1, 1, 0.67f);
      glScalef(1.1f,1.0f,1.5f);
      glutSolidCube(1);
     glPopMatrix();
	 //Droplet 1
     glPushMatrix();
      glTranslatef(0.65f, -0.25f, 0.2f);
      glutSolidSphere(0.25f, 16, 16);
    //Droplet 2
      glPushMatrix();
       glTranslatef(0.2f, -0.05f,0.25f);
       glutSolidSphere(0.2f, 16, 16);
    //Droplet3
       glPushMatrix();
        glTranslatef(0.125f, -0.025f,0.125f);
        glutSolidSphere(0.15f, 16, 16);
       glPopMatrix();

      glPopMatrix();

     glPopMatrix();
    
    glPopMatrix();
    
}


void Butter::update(GLdouble delta_t) 
{
	
	if (_speed > 0) {
        move(delta_t);
		_speed -= _friction*delta_t;
		if (_speed < 0) _speed = 0;
	}

	if (checkOutOfBounds() == true)
		reset();
}

void Butter::move(GLdouble delta_t)
{
   _position.set(_position.getX()+_direction.getX()*_speed*delta_t,_position.getY(),_position.getZ()+_direction.getZ()*_speed*delta_t);
}

void Butter::collide(GameObject* obj) 
{
	obj->collideWith(this);
}

void Butter::collideWith(Car* car)
{
	if (_speed < car->getSpeed())
	 _speed = fabs(car->getSpeed()*0.9);
    _direction.set(_position.getX() - car->_position.getX(), _position.getY() - car->_position.getY(),_position.getZ() - car->_position.getZ());
    _direction.normalize2D();
}

