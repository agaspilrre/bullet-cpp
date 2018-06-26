/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE SPHERESHAPE
//Clase encargada de crear una shape de tipo esfera para el rigidbody.

#pragma once
#include "Shape.hpp"
#include <btBulletDynamicsCommon.h>

using namespace std;

class SphereShape : public Shape
{
	public:

		//Constructor: crea una shape de tipo esfera con un radio establecido como parametro
		//Le pasa esta shape a la clase padre
		SphereShape(float radius) : Shape(shared_ptr<btCollisionShape>(new btSphereShape(btScalar(radius))))
		{


		}

};







