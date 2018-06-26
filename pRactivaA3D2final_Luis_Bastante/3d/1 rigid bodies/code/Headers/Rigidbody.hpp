/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE RIGIDBODY
//Clase encargada de crear  rigidbody.

#pragma once
#include"../../code/Headers/Shape.hpp"
#include <btBulletDynamicsCommon.h>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class Rigidbody
{
	
protected:

	//puntero que guarda el body
	shared_ptr< btRigidBody 		  > body;

	//puntero que guarda el motion state
	shared_ptr< btDefaultMotionState  > state;

	//puntero que guarda el shape
	shared_ptr< Shape   			  > shape;

	//Variables que guardan las coordenadas de origen del rigidbody
	float coordX;
	float coordY;
	float coordZ;

	//Variable que guarda el transform del rigidbody
	btTransform transform;
	

public:

	//Metodo constructor:
	//Parametros: puntero a shape, coordenadas iniciales, bool que indica si es un cuerpo estatico o dinamico y rotacion
	Rigidbody(shared_ptr< Shape > &shape,float X,float Y,float Z,bool isStatic,float mass,float rotateX,float rotateY,float rotateZ);

	//Metodo destructor
	virtual ~Rigidbody() = default;

	//Metodo que devuelve el rigidbody
	btRigidBody * get()
	{
		return body.get();
	}

	//Metodo que devuelve el transform del rigidbody
	btTransform getTransform()
	{
		return transform;
	}


};

