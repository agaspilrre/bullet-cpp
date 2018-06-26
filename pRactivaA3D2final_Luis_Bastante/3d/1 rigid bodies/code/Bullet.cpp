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

#include"../code/Headers/Bullet.hpp"
#include"../code/Headers/Scene.hpp"

Bullet::Bullet(Scene & scene, int _count, btVector3 &_vector) :GameObject(scene)
{
	//Creamos un sphereshape para la bala
	shared_ptr<Shape> sphereShape(new SphereShape(0.2f));

	//Obtenemos el vector donde se encuentra la torreta del tanque
	//Sumamos al vector anterior el forward que recibimos como parametro en cada coordenada 
	btVector3 canonPosition = btVector3(scene.getGameObject("tank")->getParts("torretaTanque11").physicsBody.get()->get()->getWorldTransform().getOrigin());
	float posX = canonPosition.x()+ _vector.x();
	float posY = canonPosition.y()+ _vector.y();
	float posZ = canonPosition.z()+ _vector.z();

	//Creamos un rigidbody dinamico para la bala en la posicion que guardamos de la torreta del tanque
	//Para que se instancie en su lugar adecuado
	shared_ptr<Rigidbody> dcRbody(new Rigidbody(sphereShape, posX, posY, posZ, false, 1.f, 0, 0, 0));

	//Descativamos estos parametros para poder aplicarle un velocity a la bala
	dcRbody.get()->get()->setLinearFactor(btVector3(0, 0, 0));
	dcRbody.get()->get()->setAngularFactor(btVector3(0, 0, 0));

	//al nombre de la bala le añadimos el count q recibimos como parametro para que el nombre no sea el mismo cada vez que instanciamos
	name = "bola11" + std::to_string(_count);

	//añadimos esta parte al objeto bala
	addModelAndPhysics("../../../../assetsC/sphere.obj", dcRbody, 0.3f,name);

	//Seteamos de nuevo el origen
	parts[name].physicsBody.get()->getTransform().setOrigin(canonPosition + _vector);

	//Aplicamos un setlinearvelocity a la bala en la direccion forward que obtenemos del parametro
	parts[name].physicsBody->get()->setLinearVelocity(_vector*10);
	
}

void Bullet::render()
{
	//Incrementamos el contador en cada frame
	countDestroy++;

	//Si el contador es mayor a 50 destruimos la bala
	//esto se hace para limitar el alcance de la bala
	if (countDestroy > 50)
	{
		parts[name].physicsBody.get()->get()->setActivationState(ISLAND_SLEEPING);
		parts[name].graphicsModel.get()->set_visible(false);
	}

}

