/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE FLOOR
//Clase encargada de crear las partes que componen el objeto suelo

#pragma once
#include "GameObject.hpp"

using std::shared_ptr;

class Floor:public GameObject {

public:
	//Metodo Constructor
	Floor(Scene & scene);
	
	//Metodo render
	void render() override;

};