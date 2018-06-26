/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE TARGETS
//Clase encargada de crear las partes del objeto targets

#pragma once
#include"../code/Headers/Targets.hpp"

//Crea las partes del objeto targets
Targets::Targets(Scene & scene) :GameObject(scene)
{
	//target1
	shared_ptr<Shape> targetShape(new BoxShape(0.1f, 1.0f, 0.1f));
	shared_ptr<Rigidbody>targetBody(new Rigidbody(targetShape, -18.0f, -4.0f, -5.0f, false, 1, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/blancoTanque.obj", targetBody, 0.2f, "blanco11");

	//target2
	shared_ptr<Shape> targetShape2(new BoxShape(0.1f, 1.0f, 0.1f));
	shared_ptr<Rigidbody>targetBody2(new Rigidbody(targetShape2, -18.0f, -4.0f, -5.5f, false, 1, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/blancoTanque.obj", targetBody2, 0.2f, "blanco12");

	//target3
	shared_ptr<Shape> targetShape3(new BoxShape(0.1f, 1.0f, 0.1f));
	shared_ptr<Rigidbody>targetBody3(new Rigidbody(targetShape3, -18.0f, -4.0f, -4.5f, false, 1, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/blancoTanque.obj", targetBody3, 0.2f, "blanco13");

	//target4
	shared_ptr<Shape> targetShape4(new BoxShape(0.1f, 1.0f, 0.1f));
	shared_ptr<Rigidbody>targetBody4(new Rigidbody(targetShape4, -18.0f, -4.0f, -4.0f, false, 1, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/blancoTanque.obj", targetBody4, 0.2f, "blanco14");

	

}

void Targets::render()
{

}