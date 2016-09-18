#include "StateManager.h"
#include "State.h"

StateManager::StateManager() {
	window = nullptr;
	resource_manager = nullptr;
}

StateManager::StateManager(sf::RenderWindow * window, ResourceManager* resource_manager) {
	this->window = window;
	this->resource_manager = resource_manager;
}

StateManager::~StateManager() {
	this->freeStates();
	window = nullptr;
	resource_manager = nullptr;
}

void StateManager::pushState(State * state) {
	if (!this->isEmpty())
		states.back()->pause(); /* The top state is paused */

	state->init(this, this->resource_manager); 
	states.push_back(state); 
	states.back()->start(); /* The new state is started */
}

void StateManager::popState() {
	if (!states.empty()) {
		states.back()->cleanup();
		delete states.back();
		states.pop_back();
	}
}

State * StateManager::topState() {
	return states.back();
}

bool StateManager::isEmpty() {
	return states.empty();
}

void StateManager::freeStates() { 
	while (!this->isEmpty()) {
		states.back()->cleanup();
		delete states.back();
		states.pop_back();
	}

	states.clear(); /* Clear up the vector */
	std::vector<State*>().swap(states); /* Deallocate memory by swapping vector with empty vector */
}

void StateManager::setWindow(sf::RenderWindow * window) {
	this->window = window;
}

sf::RenderWindow * StateManager::getWindow() {
	return window;
}