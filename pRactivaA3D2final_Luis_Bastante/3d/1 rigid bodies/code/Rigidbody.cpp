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

#include"../code/Headers/Rigidbody.hpp"

Rigidbody::Rigidbody(shared_ptr< Shape > &shape, float X, float Y, float Z, bool isStatic, float mass, float rotateX, float rotateY, float rotateZ) : shape(shape),
coordX(X),coordY(Y),coordZ(Z)

{
	//Establecemos el transform
	transform.setIdentity();

	//Establecemos la posicion donde se crea el cuerpo
	transform.setOrigin(btVector3(coordX, coordY, coordZ));

	//Establecemos la rotacion del cuerpo
	transform.setRotation(btQuaternion(rotateX, rotateY, rotateZ));
	
	//Pasamos el transform al motion state
	state.reset(new btDefaultMotionState(transform));

	//Si el bool es true establece el cuerpo como estatico
	if (isStatic)
	{
		btRigidBody::btRigidBodyConstructionInfo info(0, state.get(), shape.get()->get());
		body.reset(new btRigidBody(info));
	}

	//En caso contrario establece el cuerpo como dinamico
	else
	{
		btVector3 localInertia(0, 0, 0);
		shape->get()->calculateLocalInertia(mass, localInertia);
		btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get()->get(), localInertia);
		body.reset(new btRigidBody(info));

		//linea para que los objetos de la escena no se duerman y podamos controlarlos
		body->setActivationState(DISABLE_DEACTIVATION);
	
	}

	//Establecemos el restitution
	body->setRestitution(0.7f);

}



