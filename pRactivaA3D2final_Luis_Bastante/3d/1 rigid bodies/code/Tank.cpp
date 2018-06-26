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
#include"../code/Headers/Tank.hpp"
#include "../code/Headers/Scene.hpp"

//Crea todas las partes que componen el tanque y los joints para unir las partes del tanque
Tank::Tank(Scene & scene) :GameObject(scene)
{

	//Ruedas delanteras
	shared_ptr<Shape> weelLeftShape(new SphereShape(0.5f));
	shared_ptr<Rigidbody> welLeftRbody(new Rigidbody(weelLeftShape, 5.9f, -4.5f, -4.0f, false, 50.f, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/ruedaTanque.obj", welLeftRbody, 0.2f, "ruedaI11");
	parts["ruedaI11"].physicsBody.get()->get()->setFriction(20.5f);

	shared_ptr<Shape> weelRigthShape(new SphereShape(0.5f));
	shared_ptr<Rigidbody> welRigthRbody(new Rigidbody(weelRigthShape, 5.9f, -4.5f, -4.5f, false, 50.f, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/ruedaTanque.obj", welRigthRbody, 0.2f, "ruedaD11");
	parts["ruedaD11"].physicsBody.get()->get()->setFriction(20.5f);

	//Ruedas traseras
	shared_ptr<Shape> weelLeftRearShape(new SphereShape(0.5f));
	shared_ptr<Rigidbody> welLeftRearRbody(new Rigidbody(weelLeftRearShape, 6.2f, -4.5f, -4.0f, false, 50.f, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/ruedaTanque.obj", welLeftRearRbody, 0.2f, "ruedaI12");
	parts["ruedaI12"].physicsBody.get()->get()->setFriction(20.5f);

	shared_ptr<Shape> weelRigthRearShape(new SphereShape(0.5f));
	shared_ptr<Rigidbody> welRigthRearRbody(new Rigidbody(weelRigthRearShape, 6.2f, -4.5f, -4.5f, false, 50.f, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/ruedaTanque.obj", welRigthRearRbody, 0.2f, "ruedaD12");
	parts["ruedaD12"].physicsBody.get()->get()->setFriction(20.5f);

	//base del tange
	shared_ptr<Shape> baseTankShape(new BoxShape(0.2f, 0.1f, 0.2f));
	shared_ptr<Rigidbody>baseTankBody(new Rigidbody(baseTankShape, 5.8f, -3.4f, -4.2f, false, 120, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/baseTanque.obj", baseTankBody, 0.2f, "baseTanque11");

	//torreta del tanque
	shared_ptr<Shape> turretTankShape(new BoxShape(0.1f, 0.1f, 0.1f));
	shared_ptr<Rigidbody>turretTankBody(new Rigidbody(turretTankShape, 5.8f, 1.2f, -4.2f, false, 70, 0, 0, 0));
	addModelAndPhysics("../../../../assetsC/cabinaTanque.obj", turretTankBody, 0.2f, "torretaTanque11");

	//JOINTS

	//ruedaizq delanter a base tanque
	addJoints("ruedaIDBase", welLeftRbody, baseTankBody, btVector3(0.0f, 0.0f, 0.f), btVector3(-0.5f, -0.5, 0.5), btVector3(0, 0, 1.f), btVector3(0, 0, 1.f));
	////rueda derecha delantera a base tanque
	addJoints("ruedaDDBase", welRigthRbody, baseTankBody, btVector3(0.0f, 0.0f, 0.f), btVector3(-0.5, -0.5, -0.5), btVector3(0, 0, 1.f), btVector3(0, 0, 1.f));
	////////rueda izquierda trasera a base tanque
	addJoints("ruedaITBase", welLeftRearRbody, baseTankBody, btVector3(0.0f, 0.0f, 0.f), btVector3(0.5, -0.5f, 0.5f), btVector3(0, 0, 1.f), btVector3(0, 0, 1.f));
	////////rueda derecha trasera a base tanque
	addJoints("ruedaDTBase", welRigthRearRbody, baseTankBody, btVector3(0.0f, 0.0f, 0.f), btVector3(0.5, -0.5f, -0.5f), btVector3(0, 0, 1.f), btVector3(0, 0, 1.f));
	//////base tanque a torreta tanque
	addJoints("baseTorreta", turretTankBody, baseTankBody, btVector3(0, 0, 0), btVector3(0, 0.5, 0), btVector3(0, 1, 0), btVector3(0, 1, 0));
	
}

void Tank::render()
{
	
	//Obtenemos el vector forward de la base del tanque para el movimiento del tanque
	btVector3 VecForw = Forward("baseTanque11");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		//Mover ruedas derechas hacia delante
		parts["ruedaI11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw*4);
		parts["ruedaI12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);
		parts["ruedaD11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);
		parts["ruedaD12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw*4);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		//Mover ruedas derechas hacia atras
		parts["ruedaI11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaI12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaD11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaD12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		//Gira el tanque hacia la izquierda
		parts["ruedaI11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);
		parts["ruedaI12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);
		parts["ruedaD11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaD12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		//Gira el tanque hacia la derecha
		parts["ruedaI11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaI12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * -4);
		parts["ruedaD11"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);
		parts["ruedaD12"].physicsBody.get()->get()->applyTorqueImpulse(VecForw * 4);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{

		//Gira la torreta del tanque hacia la derecha
		parts["torretaTanque11"].physicsBody.get()->get()->applyTorqueImpulse(btVector3(4, 0, 0));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{

		//Gira la torreta del tanque hacia la izquierda
		parts["torretaTanque11"].physicsBody.get()->get()->applyTorqueImpulse(btVector3(0, 0.01f, 0));
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		//incrementamos contador del nombre
		countName++;

		//obtenemos vector forward de la torreta del tanque
		btVector3 VecForwCanon = Forward("torretaTanque11");

		//llamamos al metodo instanciar bala y le pasamos el contador de nombre y el vector forward de la torreta
		scene.instantiateBullet(countName, VecForwCanon);
			
	}

	//Comprovamos el rango de posiciones en el if y si el tanque esta dentro significa que esta encima de la llave y la coge
	if (parts["baseTanque11"].physicsBody.get()->get()->getWorldTransform().getOrigin().x() >= 0.f && 
		parts["baseTanque11"].physicsBody.get()->get()->getWorldTransform().getOrigin().x() <=1.5f &&
		parts["baseTanque11"].physicsBody.get()->get()->getWorldTransform().getOrigin().z() <= -0.f &&
		parts["baseTanque11"].physicsBody.get()->get()->getWorldTransform().getOrigin().z() >= -1.5f && 
		!dontEnter)
	{

		//ponemos el bool a true para que una vez cogida la llave no vuelva a entrar por este if
		dontEnter = true;

		//aplicamos movimiento al objeto muro para que despeje el camino y el tanque pueda disparar a los objetivos
		scene.getGameObject("Wall")->getParts("pared11").physicsBody.get()->get()->setLinearVelocity(btVector3(0, 3, 0));
		
		//Obtenemos el objeto key y llamamos a su metodo delete key para borrar la llave de la escena
		Key *keyObject = dynamic_cast<Key*>(scene.getGameObject("Key"));
		keyObject->deleteKey();

		//añadimos la plataforma de movimiento a la escena
		scene.addPlatform();

	}

}



