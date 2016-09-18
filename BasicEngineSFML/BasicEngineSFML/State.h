/*
* @Description
* Abstract class for application states, which may handle events, be updated and
*  be drawn onto the window.
*
* @How to Use
* Create children classes for application states (different menus, transitions, gameplay).
*  The update() and draw() functions are called every frame, while handleEvent() is only
*  called when an action by the user is registered. The start() and pause() functions are
*  called whenever a State either enters the stack or another State enters the stack,
*  accordingly.
*
* @What Does This Do?
* 1. Initialize references to its manager, as well as the accompanying resource manager.
* 2. Provides an easy way to handle multiple application states in their own classes.
*/
#pragma once
#include <SFML\Graphics\Drawable.hpp> 
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>
#include "StateManager.h"
#include "ResourceManager.h"

class StateManager;

class State : public sf::Drawable {
public:
	virtual void init(StateManager* state_manager, ResourceManager* resource_manager) = 0;
	virtual void cleanup() = 0;
	virtual void start() = 0;
	virtual void pause() = 0;

	/*
	* @Description
	* Called on every frame so long as this State is the top state in the StateManager.
	*  Intended for use with logic updates, 
	*/
	virtual void update() = 0;
	/*
	* @Description
	* Called when an event is registered by the Engine, and this State is at the top of
	*  the StateManager.
	*
	* @Parameters
	*  Event event - The registered event (ex: "B" key pressed)
	*  RenderWindow window - The application window
	*/
	virtual void handleEvent(sf::Event event, sf::RenderWindow * window) = 0;

protected:
	StateManager* state_manager; /* Manager of this state */
	ResourceManager* resource_manager; /* Resource manager of the Engine */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

