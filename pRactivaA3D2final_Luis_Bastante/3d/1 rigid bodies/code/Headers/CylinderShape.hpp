/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE CYLINDERSHAPE
//Clase encargada de crear una shape de tipo cilindro para el rigidbody.

#pragma once
#include "Shape.hpp"
#include <btBulletDynamicsCommon.h>

using namespace std;

class CylinderShape : public Shape
{
public:

	//Constructor: Crea una shape de tipo cilindro con altura anchura y profundiad establecida como parametro
	//Le pasa esta shape a la clase padre
	CylinderShape(float width, float height, float depth) : Shape(shared_ptr<btCollisionShape>(new btBoxShape(btVector3(width, height, depth))))
	{

		
	}

};
