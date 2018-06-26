/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE PLATFORMMOVE
//Clase encargada de crear el objeto plataforma movil y de gestionar su comportamiento

#pragma once
#include"../code/Headers/PlatformMove.hpp"

//Metodo constructor: construye el objeto plataforma movil
PlatformMove::PlatformMove(Scene & scene) :GameObject(scene)
{
	//Crea el shape y el rigidbody de la plataforma
	shared_ptr<Shape> platformShape(new BoxShape(1.1f, 0.1f, 1.1f));
	shared_ptr<Rigidbody>platformBody(new Rigidbody(platformShape, -4.0f, -4.7f, -5.0f, false, 1, 0, 0, 0));

	//Establecemos estos parametros a 0 para poder aplicarle a este objeto el setlinear velocity
	platformBody.get()->get()->setLinearFactor(btVector3(0, 0, 0));
	platformBody.get()->get()->setAngularFactor(btVector3(0, 0, 0));

	//añadimos la parte
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", platformBody, 0.08f, "plataforma11");

	//aplicamos un setlinearvelocity a este objeto
	parts["plataforma11"].physicsBody->get()->setLinearVelocity(btVector3(1, 0, 0));
}


//Comprobamos en que posicion en X esta moviendose la plataforma
void PlatformMove::render()
{
	//si supera los limites establecidos en los if, cambiamos la direccion en el eje x de la plataforma
	if (parts["plataforma11"].physicsBody->get()->getWorldTransform().getOrigin().x() >= 0.0f)
	{
		parts["plataforma11"].physicsBody->get()->setLinearVelocity(btVector3(-1, 0, 0));
	}

	if (parts["plataforma11"].physicsBody->get()->getWorldTransform().getOrigin().x() <= -7.0f)
	{
		parts["plataforma11"].physicsBody->get()->setLinearVelocity(btVector3(1, 0, 0));
	}
	
}