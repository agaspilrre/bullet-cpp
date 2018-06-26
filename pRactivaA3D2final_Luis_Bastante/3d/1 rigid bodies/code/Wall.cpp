/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE WALL
//Clase encargada de crear un muro

#include"../code/Headers/Wall.hpp"

//Crea un muro
Wall::Wall(Scene & scene) :GameObject(scene)
{
	shared_ptr<Shape> boxShape(new BoxShape(2.7f, 1.9f, 0.01f));
	shared_ptr<Rigidbody>stRbody(new Rigidbody(boxShape, -10.0f, -2.7f, -5.0f, false, 1, 80, 0, 0));
	stRbody.get()->get()->setLinearFactor(btVector3(0, 0, 0));
	stRbody.get()->get()->setAngularFactor(btVector3(0, 0, 0));
	addModelAndPhysics("../../../../assetsC/paredTanque.obj", stRbody, 0.2f, "pared11");

}

void Wall::render()
{
	
}