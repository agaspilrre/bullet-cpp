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
#include <btBulletDynamicsCommon.h>
#include <memory>
#include<vector>
#include "Rigidbody.hpp"

class PhysicsWorld
{
	//Variables que necesita el mundo fisico para poder inicializarse
	std::unique_ptr< btDiscreteDynamicsWorld > world;
	btDefaultCollisionConfiguration collisionConfiguration;
	btCollisionDispatcher collisionDispatcher;
	btDbvtBroadphase overlappingPairCache;
	btSequentialImpulseConstraintSolver constraintSolver;

public:

	//Metodos destructor y constructor
	 PhysicsWorld();
	~PhysicsWorld();

	//Metodo que devuelve el mundo fisico
	btDiscreteDynamicsWorld * getWorld()
	{
		return world.get();
	}

	//Metodo update del mundo fisico
	void step(float time)
	{
		world->stepSimulation(time);
	}

	//Añade rigidbody al mundo fisico
	void addRigidBody(std::shared_ptr<Rigidbody> & rigidBody)
	{
		world->addRigidBody(rigidBody.get()->get());
	}

	//Resetea el mundo fisico
	void resetWorld()
	{
		world.reset();
	}

	//Añade constrainst de un objeto al mundo fisico
	void addConstraint(std::shared_ptr<btHingeConstraint>  _contraint)
	{
		btHingeConstraint *joint= _contraint.get();
		world->addConstraint(joint);
	}


};

