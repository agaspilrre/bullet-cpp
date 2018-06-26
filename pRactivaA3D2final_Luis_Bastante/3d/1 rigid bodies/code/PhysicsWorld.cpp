/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE PHYSICSWORLD
//Clase encargada de crear el mundo fisico y de gestionarlo.

#pragma once
#include "../code/Headers/PhysicsWorld.hpp"

PhysicsWorld::PhysicsWorld():collisionDispatcher(&collisionConfiguration)
{
	//Crea el mundo fisico
	world.reset
	(
		new btDiscreteDynamicsWorld
		(
			&collisionDispatcher,
			&overlappingPairCache,
			&constraintSolver,
			&collisionConfiguration
		)
	);

	//Establece el vector de gravedad en el mundo fisico
	world->setGravity(btVector3(0, -10, 0));

}

PhysicsWorld::~PhysicsWorld()
{
}
