/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE BOXSHAPE
//Clase encargada de crear una shape de tipo caja para el rigidbody.

#pragma once
#include "Shape.hpp"
#include <btBulletDynamicsCommon.h>

using namespace std;

class BoxShape : public Shape
{
public:

	//Constructor: Crea una shape de tipo caja con altura anchura y profundiad establecidas en los parametros
	//le pasa el shape al constructor padre
	BoxShape(float width, float height, float depth) : Shape(shared_ptr<btCollisionShape>(new btBoxShape(btVector3(width,height,depth))))
	{
		

	}

};
