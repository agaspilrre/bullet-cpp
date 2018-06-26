/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE SHAPE
//Clase encargada de crear una shape para el rigidbody.

#pragma once
#include <btBulletDynamicsCommon.h>
#include<memory>

using namespace std;

class Shape
{
	protected:

		//Shared_ptr que guarda el shape
		shared_ptr< btCollisionShape > shape;

	public:

		//Metodo destructor
		virtual ~Shape() = default;

	protected:
		
		//Metodo Constructor recibe como parametro una shape que le pasan las clases hijas
		Shape(shared_ptr< btCollisionShape > _shape) : shape(_shape)
		{
		}

	public:

		//Metodo que devuelve el shape
		btCollisionShape * get()
		{
			return shape.get();
		}
};


