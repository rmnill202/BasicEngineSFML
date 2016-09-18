/*
* @Description
* The Engine class contains managers for resources and States, and runs the primary 
*  application loop in which logic updates, event handling and graphics rendering are 
*  handled for existing States. 
*/
#pragma once
#include <SFML\Graphics.hpp> 
#include "StateManager.h"
#include "ResourceManager.h"
#include "State.h"
#include "Utilities.h"

class Engine {

public:
	/*
	* @Description
	* Constructs an Engine object containing a window and managers for application states 
	*  and resources.
	*
	* @Parameters
	*  int width - Width of the application window on start
	*  int height - Height of the application window on start
	*  string title - Title of the application window
	*  bool fullscreen - Whether or not the application is fullscreen upon launching
	*  State* state - The default state the application will launch in
	*/
	Engine(int width = 1024, int height = 768, std::string title = "New Application", bool fullscreen = false, State* state = nullptr);
	~Engine();

	/* 
	* @Description
	* Loops while the application window is open. For each State in the State Manager, logic
	*  is updated, events are handled and graphics are drawn onto the screen.
	*
	* @Return
	* Returns an exit status when the application is finished. Used for determining whether or
	*  not an error occurred. 
	*/
	int run();

private:
	sf::RenderWindow window;
	StateManager state_manager;
	ResourceManager resource_manager;
};

