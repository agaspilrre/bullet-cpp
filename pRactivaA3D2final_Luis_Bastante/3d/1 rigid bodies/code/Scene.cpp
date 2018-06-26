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

#include "../code/Headers/Scene.hpp"

	Scene::Scene()
	{
		//Se crean los nodos de camara y luz de la escena
		shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
		shared_ptr< Light  > light (new Light);
		
		//Se añaden los nodos a la escena
		renderer.add("camera", camera);
		renderer.add("light", light);

		//Se posicionan estos nodos en la escena
		renderer["light"]->translate(Vector3(10.f, 20.f, 10.f));
		renderer["camera"]->translate(Vector3(-5.5f, 0.f, 10.f));

		//Se añaden los gameObjects al mapa y a escena, Suelo, muro, objeticos, llave y tanque
		addGameObject("floor", shared_ptr<GameObject>(new Floor(*this)));
		addGameObject("Wall", shared_ptr<GameObject>(new Wall(*this)));
		addGameObject("Targets", shared_ptr<GameObject>(new Targets(*this)));
		addGameObject("Key", shared_ptr<GameObject>(new Key(*this)));
		addGameObject("tank", shared_ptr<GameObject>(new Tank(*this)));

	}


	void  Scene::addGameObject(string name, shared_ptr< GameObject > & gameObject)
	{
		//Añadimos el gameObject al mapa de gameObjects
		gameObjects[name] = gameObject;

		//Añadimos las partes que componen el gameObject y le pasamos referencia de render y mundo fisico
		gameObjects[name]->addParts(renderer, physicsWorld);

		//Añade los joinsts del objeto y le pasa una referencia del mundo fisico
		gameObjects[name]->addJointsToPhysics(physicsWorld);

	}


	void Scene::update(float time)
	{
		//Llama al update del mundo fisico
		physicsWorld.step(time);

		// llama al metodo update y render de todos los game objects
		for (auto iter = gameObjects.begin(), end = gameObjects.end(); iter != end; iter++)
		{
			iter->second->update();
			iter->second->render();
		}

	}


	void Scene::instantiateBullet(int _count, btVector3 &_vector)
	{
		//crea un nombre para el objeto bala y le añade el contador que le pasamos por parametro
		//para que el nombre no sea siempre igual y evitar asi conflicto con el programa
		string name = "bullet" + std::to_string(_count);

		//Añade objeto bala a la escena y al mapa de objetos
		addGameObject(name, shared_ptr<GameObject>(new Bullet(*this,_count,_vector)));

	}

	//Obtiene el gameObject que pedimos a traves del nombre que recibe la funcion como parametro
	//Si no se encuentra en el mapa devuelve un nullptr
	GameObject * Scene::getGameObject(const std::string & name)
	{

		if (gameObjects.count(name))
		{
			return gameObjects[name].get();
		}
		else
		{
			return nullptr;
		}

	}

	//Configura el tamaño del wievport cuando la funcion es llamada
	void Scene::reset_viewport(const sf::Window & window)
	{
		GLsizei width = GLsizei(window.getSize().x);
		GLsizei height = GLsizei(window.getSize().y);

		renderer.get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}


