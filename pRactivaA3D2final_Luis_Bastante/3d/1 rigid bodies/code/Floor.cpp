/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE FLOOR
//Clase encargada de crear las partes que componen el objeto suelo

#include "../code/Headers/Floor.hpp"

//Se crean las partes del objeto suelo y se añaden sus fisicas y modelos a la escena
Floor::Floor(Scene & scene) :GameObject(scene)
{

	shared_ptr<Shape> boxShape(new BoxShape(4.1f, 0.3f, 4.1f));
	shared_ptr<Rigidbody>stRbody(new Rigidbody(boxShape, 4.0f, -5.0f, -5.0f, true, 0, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", stRbody, 0.3f,"suelo11");

	shared_ptr<Shape> boxShape4(new BoxShape(4.1f, 0.3f, 4.1f));
	shared_ptr<Rigidbody>stRbody4(new Rigidbody(boxShape4, 4.0f, -5.0f, -8.1f, true, 0, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", stRbody4, 0.3f, "suelo14");

	shared_ptr<Shape> boxShape5(new BoxShape(4.1f, 0.3f, 4.1f));
	shared_ptr<Rigidbody>stRbody5(new Rigidbody(boxShape5, 4.0f, -5.0f, -1.9f, true, 0, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", stRbody5, 0.3f, "suelo15");

	shared_ptr<Shape> boxShape2(new BoxShape(4.1f, 0.3f, 4.1f));
	shared_ptr<Rigidbody>stRbody2(new Rigidbody(boxShape2, -11.0f, -5.0f, -5.0f, true, 0, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", stRbody2, 0.3f,"suelo12");

	shared_ptr<Shape> boxShape3(new BoxShape(2.7f, 0.0f, 2.7f));
	shared_ptr<Rigidbody>stRbody3(new Rigidbody(boxShape3, -20.0f, -5.0f, -5.0f, true, 0, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/sueloTanque.obj", stRbody3, 0.2f, "suelo13");

}


void Floor::render()
{
	
}