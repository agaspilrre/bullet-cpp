/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE TARGETS
//Clase encargada de crear las partes del objeto targets

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "Rigidbody.hpp"

using std::shared_ptr;

class Targets :public GameObject {

public:

	//Metodo constructor
	Targets(Scene & scene);

	//Metodo render
	void render() override;


};
