/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//CLASE GAMEOBJECT
//Clase encargada de gestionar los gameObjects, sus partes, sus joints, añadir las graficas y las fisicas

#include "../code/Headers/GameObject.hpp"

//Añadimos a la parte recibida como parametro las fisicas y grafica y cargamos el objeto
void GameObject:: addModelAndPhysics(const string & model_obj_path, shared_ptr< Rigidbody > & rigidBody, float _physicsToGraphicsScale,string namePart)
{
	Parts &part = parts[namePart];
	part.physicsBody = rigidBody;
	part.physicsToGraphicsScale = _physicsToGraphicsScale;
	part.graphicsModel.reset(new Model_Obj(model_obj_path));
}

//Crea un hingeConstraint y lo añade al mapa de joints
void GameObject::addJoints(string name, shared_ptr< Rigidbody > & rgA, shared_ptr< Rigidbody > & rgB,btVector3 & pivotA, btVector3 & pivotB, btVector3 & axisA, btVector3 & axisB)
{
	
	shared_ptr<btHingeConstraint> joint(new btHingeConstraint(*rgA.get()->get(), *rgB.get()->get(), pivotA, pivotB, axisA, axisB,false));
	constrains[name] = joint;

}

//Recorre el mapa de partes actualizando las fisicas, transform, grafica, escala
void GameObject::update()
{

	btTransform physics_transform;

	for (auto & part : parts)
	{
		part.second.physicsBody->get()->getMotionState()->getWorldTransform(physics_transform);

		glm::mat4 graphics_transform;

		physics_transform.getOpenGLMatrix(glm::value_ptr(graphics_transform));

		part.second.graphicsModel->set_transformation(graphics_transform);

		part.second.graphicsModel->scale(part.second.physicsToGraphicsScale);
	}

}

//añade grafica y fisica a las partes del gameObject
void GameObject::addParts(glt::Render_Node & _graphicsModel, PhysicsWorld &_world)
{
	for (auto & part : parts)
	{
		_graphicsModel.add(part.first, part.second.graphicsModel);
		_world.addRigidBody(part.second.physicsBody);
	}
}

//Recorre los joints del objeto y los añade al mundo fisico
void GameObject::addJointsToPhysics(PhysicsWorld &_world)
{
	for (auto & constrain : constrains)
	{
		_world.addConstraint(constrain.second);
	}
}

//obtiene el transform del objeto especificado como parametro y a partir de ese transform saca el vector forward
btVector3 GameObject::Forward(const std::string & name)
{
	btTransform transform = parts[name].physicsBody.get()->get()->getWorldTransform();
	btScalar Matrix[16];
	transform.getOpenGLMatrix(Matrix);
	return btVector3(Matrix[8], Matrix[9], Matrix[10]);
}