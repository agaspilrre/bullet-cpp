/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE PLATFORMMOVE
//Clase encargada de crear el objeto plataforma movil y de gestionar su comportamiento

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "Rigidbody.hpp"

using std::shared_ptr;

class PlatformMove :public GameObject {

public:

	//Metodo constructor
	PlatformMove(Scene & scene);

	//Metodo render
	void render() override;


};