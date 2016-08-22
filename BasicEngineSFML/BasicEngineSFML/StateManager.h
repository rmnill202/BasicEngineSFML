/*
* @Description
* Contains and manages States in a stack of State pointers. 
*
* @How to Use
* The StateManager's primary task is to handle memory allocation, which providing a
*  convenient interface for handling the States with stack behavior. States may be
*  pushed into the manager, popped, peeked (topState()) and emptied. States are
*  added to the manager with the keyword "new", which calls for the manager to delete
*  a state manually when the manager pops it.
*
* @What Does This Do?
* 1. Handles memory allocation/clearing for State objects.
* 2. Provides stack behavior for managing State objects.
*/
#pragma once
#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <memory>
#include <iostream>
#include "ResourceManager.h"

class State;

class StateManager {

public:
	StateManager();
	StateManager(sf::RenderWindow * window, ResourceManager* resource_manager);
	~StateManager();

	/*
	* @Description
	* Add a new State to the stack of states.
	*
	* @Parameters
	*  State* state - A State declared with the "new" keyword to avoid
	*   the object going out of scope following the end of the function
	*   it is created in
	*/
	void pushState(State* state);
	/*
	* @Description
	* Remove the top state from the stack of states.
	*/
	void popState();
	/*
	* @Description
	* Returns a pointer to the top state in the stack of states.
	*/
	State* topState();
	/*
	* @Description
	* Empties the stack of States and clears up memory allocated by
	*  each State.
	*
	* @Return
	* Whether or not the stack has been successfully emptied.
	*/
	bool empty();
	void freeStates(); /* Used for memory allocation testing */

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

private:
	ResourceManager* resource_manager; /* Resource manager of the Engine */
	sf::RenderWindow* window; /* Application window */
	std::vector<State*> states; /* Vector of States acting as a stack */
};

