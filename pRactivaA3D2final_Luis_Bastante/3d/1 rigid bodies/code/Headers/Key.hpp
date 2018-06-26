/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE KEY
//Clase encargada de crear el objeto llave y de desactivarlo

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "Rigidbody.hpp"

using std::shared_ptr;

class Key :public GameObject {

public:
	
	//Metodo constructor
	Key(Scene & scene);

	//Metodo render
	void render() override;

	//Metodo para desactivar la llave de la escena
	void deleteKey();

};