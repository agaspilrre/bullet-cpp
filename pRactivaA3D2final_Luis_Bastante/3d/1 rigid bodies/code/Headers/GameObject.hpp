/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE GAMEOBJECT
//Clase encargada de gestionar los gameObjects, sus partes, sus joints, añadir las graficas y las fisicas

#pragma once
#include <memory>
#include "Shape.hpp"
#include "Rigidbody.hpp"
#include "Model_Obj.hpp"
#include "BoxShape.hpp"
#include "PhysicsWorld.hpp"
#include <Render_Node.hpp>

using glt::Model_Obj;
using std::shared_ptr;
class Scene;

class GameObject
{

protected: 
	
	//Estructura que contiene puntero al cuerpo fisico, puntero al modelo grafico, variable que relaciona la escala fisica y grafica
	struct Parts
	{
		shared_ptr< Rigidbody > physicsBody;
		shared_ptr< Model_Obj > graphicsModel;
		float physicsToGraphicsScale;
	};
		
	//puntero que guarda una referencia a escena
	Scene & scene;

	//Mapa de partes que componen un gameObject
	map< std::string, Parts > parts;

	//Mapa de joints que puede conterner un gameObject
	map< string, shared_ptr<btHingeConstraint>> constrains;

public:

	//Metodo constructor
	GameObject(Scene & scene) : scene(scene)
	{
		
	}

	//Añade modelo fisico y grafico a las partes del gameObject
	void addModelAndPhysics(const string & model_obj_path, shared_ptr< Rigidbody > & rigidBody, float physicsToGraphicsScale,string namePart);

	//Añade joints a las partes del gameObject
	void addJoints(string name, shared_ptr< Rigidbody > & rgA, shared_ptr< Rigidbody > & rgB,btVector3 & pivotA, btVector3 & pivotB, btVector3 & axisA, btVector3 & axisB);

	//Metodo update
	void update();
	
	//Metodo render que sobrescriben los hijos
	virtual void render() = 0;

	//Metodo que añade partes al gameObject
	void addParts(glt::Render_Node & _graphicsModel, PhysicsWorld &_world);
	
	//Obtiene la parte especificada con el parametro de un gameObject
	Parts & getParts(const std::string & name)
	{
		return parts[name];
	}

	//Añade los joints al mundo fisico
	void addJointsToPhysics(PhysicsWorld &_world);
	
	//Metodo para obtener la escena
	Scene & getScene()
	{
		return scene;
	}

	//Metodo para obtener vector forward de un objeto
	btVector3 Forward(const std::string & name);
	

};