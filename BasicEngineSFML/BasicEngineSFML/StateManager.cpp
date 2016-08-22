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
	while (!states.empty()) {
		states.back()->cleanup();
		delete states.back();
		states.pop_back();
	}

	states.clear(); /* Clear up the vector */
	std::vector<State*>().swap(states); /* Deallocate memory by swapping vector with empty vector */
}

void StateManager::pushState(State * state) {
	state->init(this, this->resource_manager);
	states.push_back(state);
}

void StateManager::popState() {
	if (!states.empty()) {
		states.back()->cleanup();
		delete states.back();
		states.pop_back();
	}
	else
		std::cout << "Already empty!" << std::endl;
}

State * StateManager::topState() {
	return states.back();
}

bool StateManager::empty() {
	return states.empty();
}

void StateManager::freeStates() { /* Used for memory allocation testing, will be phased out */
	while (!states.empty()) {
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