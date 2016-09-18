/*
* @Description
* Contains and manages States in a stack of pointers. Cleans up objects when
*  the application ends, or when resources are deleted.
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
	*  State* state - The new top State
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
	* Checks if the stack of States is empty
	*
	* @Return
	* Whether or not the stack is empty.
	*/
	bool isEmpty();
	/*
	* @Description
	* Empties the stack of States and clears up memory allocated for them.
	*/
	void freeStates(); 

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

private:
	ResourceManager* resource_manager;
	sf::RenderWindow* window;
	std::vector<State*> states;
};

