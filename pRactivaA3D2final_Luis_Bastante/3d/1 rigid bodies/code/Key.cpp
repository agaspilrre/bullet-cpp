/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE KEY
//Clase encargada de crear el objeto llave y de desactivarlo

#pragma once

#include"../code/Headers/Key.hpp"
#include "Model_Obj.hpp"

//Metodo constructor crea el objeto llave
Key::Key(Scene & scene) :GameObject(scene)
{
	
	shared_ptr<Shape> keyShape(new BoxShape(1.0f, 0.4f, 0.4f));
	shared_ptr<Rigidbody>keyBody(new Rigidbody(keyShape, 0.0f, -4.0f, 0.5f, false, 1, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/llaveTanque.obj", keyBody, 0.3f, "Llave11");

}


void Key::render()
{
	
}


//Desactiva el objeto llave de la escena cuando esta funcion es llamada
void Key::deleteKey()
{
	parts["Llave11"].physicsBody.get()->get()->setActivationState(ISLAND_SLEEPING);
	parts["Llave11"].graphicsModel.get()->set_visible(false);
}