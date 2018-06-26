/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE TANK
//Clase encargada de crear el objeto tanque y gestionar su comportamiento

#pragma once
#include "GameObject.hpp"
#include "BoxShape.hpp"
#include "SphereShape.hpp"
#include "CylinderShape.hpp"
#include "Rigidbody.hpp"
#include <SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include"Bullet.hpp"

using std::shared_ptr;

class Tank :public GameObject {

	//variable para asignar distintos nombres a la instancia de balas
	int countName = 0;

	//variable que controla si el jugador ha obtenido la llave
	bool dontEnter = false;
	
public:

	//Metodo constructor
	Tank(Scene & scene);

	//Metodo render
	void render() override;

	
	

};