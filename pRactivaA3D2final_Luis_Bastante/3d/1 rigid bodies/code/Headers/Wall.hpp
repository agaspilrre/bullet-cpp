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

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "Rigidbody.hpp"

using std::shared_ptr;

class Wall :public GameObject {

public:

	//Metodo constructor
	Wall(Scene & scene);

	//Metodo render
	void render() override;


};