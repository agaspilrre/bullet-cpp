/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE BULLET
//Clase encargada de crear  un objeto bala y de gestionar su comportamiento.

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "Rigidbody.hpp"

using std::shared_ptr;

class Bullet :public GameObject {

	//Variable para controlar el rango de alcance de la bala
	int countDestroy = 0;

	//Variable para asignar nombre a la parte de este objeto
	string name;

public:

	//Metodo Constructor
	Bullet(Scene & scene,int _count, btVector3 &_vector);

	//Metodo render
	void render() override;

	

};