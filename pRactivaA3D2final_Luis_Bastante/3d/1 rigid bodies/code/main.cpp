/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Autor: Luis Bastante Fraile                                                *
*                                                                             *
*  Proyecto: Practica animacion 3D 2 version 1.0.                             *
*                                                                             *
*  Fecha: 09/06/2018                                                          *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//FUNCION MAIN
//Crea ventana y scena del juego, Hace bucle recursivo para flujo de juego y detecta eventos

#include "../code/Headers/Scene.hpp"
#include"../code/Headers/Shape.hpp"
#include"../code/Headers/SphereShape.hpp"
#include"../code/Headers/BoxShape.hpp"

int main ()
{
	//Crea ventana
    sf::Window window
    (
        sf::VideoMode(1024, 720),
        "Bullet Rigid Bodies",
        sf::Style::Default,
        sf::ContextSettings(24, 0, 0, 3, 2, sf::ContextSettings::Core)      // Se usa OpenGL 3.2 core profile
    );

    // Se determinan las caracter�sticas de OpenGL disponibles en la m�quina:
	if (!glt::initialize_opengl_extensions())
	{
		exit (-1);
	}

    // Se activa la sincronizaci�n vertical:
    window.setVerticalSyncEnabled (true);

	//Creamos el objeto escena
	Scene scene;
	
    scene.reset_viewport (window);

    glClearColor (0.2f, 0.2f, 0.2f, 1.f);

    bool running = true;
    int  frame   = 0;

	//Bucle de flujo de juego
    do
    {
       //detectamos si hay eventos de ventana, si se ha cerrado o si se cambia de tama�o
        sf::Event event;

        while (window.pollEvent (event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    running = false;
                    break;
                }

                case sf::Event::Resized:
                {
					scene.reset_viewport(window);
                    break;
                }
            }
        }

		//Llamamos al update de escena y le pasamos el timer
		scene.update (1.f / 60.f);

        // Render the scene:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//LLamamos al metodo render de escena
        scene.render ();

        window.display ();
    }
    while (running);

    // Se debe destruir el mundo f�sico antes de que se destruyan los cuerpos r�gidos:
	scene.resetPhWorld();
	
    return EXIT_SUCCESS;
}
