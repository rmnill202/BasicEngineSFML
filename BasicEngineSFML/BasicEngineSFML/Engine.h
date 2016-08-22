/*
* @Description
* The Engine class contains managers for resources and States, and runs the primary 
*  application loop in which logic updates, event handling and graphics rendering are 
*  handled for existing States. 
*
* @How to Use
* Required interaction with the Engine class is limited to instantiation with proper 
*  parameters, as well as calling the run() function in order to begin the primary 
*  application loop. Application specific processes are handled within States. 
*
* @What Does This Do?
* 1. Loop until the window closes, and for the top State in the manager
*   a. Update logic
*   b. Handle event
*   c. Draw
* 2. Instantiate a resource manager
* 3. Instantiate a state manager
* 4. Set and update application properties
*   -Frame rate, anti-aliasing, window size, fullscreen, etc...
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
	* Constructs an Engine object containing an SFML Window and managers for application states 
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
	sf::RenderWindow window; /* Application window */
	StateManager state_manager; /* Handles State creation/cleanup, transitioning between States */
	ResourceManager resource_manager; /* Handles the loading/cleanup of application resources */
};

