/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// CLASE SCENE
//Clase encargada de crear los objetos que tiene la escena, camara luz y gameObjects

#pragma once
#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <Light.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>
#include <SFML/Window.hpp>
#include "PhysicsWorld.hpp"
#include "GameObject.hpp"
#include "Floor.hpp"
#include "Tank.hpp"
#include "Wall.hpp"
#include "Targets.hpp"
#include "Key.hpp"
#include "PlatformMove.hpp"

using namespace std;
using namespace glt;

class Scene
{
	//Mapa que guarda los game objects de la escena
	map< string, shared_ptr< GameObject > > gameObjects;

	//Objeto render para el pintado de objetos
	Render_Node  renderer;

	//Objeto de fisicas para obtener las fisicas de los objetos
	PhysicsWorld physicsWorld;


public:

	//Metodos constructor y destructor de la escena
	 Scene();
	~Scene() {}

	//Metodo que añade un gameObject al mapa de gameObjects
	void addGameObject(string name, shared_ptr< GameObject > & gameObject);
	
	//Metodo update
	void update(float time);
	
	//Metodo que resetea el mundo fisico
	void resetPhWorld()
	{
		physicsWorld.resetWorld();
	}

	//Obtiene el game
	GameObject * Scene::getGameObject(const std::string & name);
	
	//LLama al metodo render para el pintado de objetos
	void render()
	{
		renderer.render();
	}

	//Metodo para instanciar un objeto bala en la escena
	void instantiateBullet(int _count, btVector3 &_vector);

	//Añade el objeto plataforma a la escena cuando este metodo es llamado
	void addPlatform()
	{
		addGameObject("Platform", shared_ptr<GameObject>(new PlatformMove(*this)));
	}

	//ajusta el tamaño del wieport
	void reset_viewport(const sf::Window & window);




};








