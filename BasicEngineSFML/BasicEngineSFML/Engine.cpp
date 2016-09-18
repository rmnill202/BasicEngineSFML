#include "Engine.h"

Engine::Engine(int width, int height, std::string title, bool fullscreen, State* state) :
	window(sf::VideoMode(width, height), title, sf::Style::Default), 
	resource_manager(),
	state_manager(&this->window, &this->resource_manager) {
	
	/* Initial application settings */
	if (fullscreen) 
		window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	if(state != nullptr)
		state_manager.pushState(state);
}

int Engine::run() {
	int exit_status = 0; /* Keep track of any runtime failures */

	while (window.isOpen()) {
		/* (1) Update game logic */
		if (!state_manager.isEmpty()) { 
			state_manager.topState()->update();
		}
		/* (2) Handle game events */
		sf::Event event; 
		while (window.pollEvent(event)) {
			if (!state_manager.isEmpty()) { /* Handle event in top state , if it exists*/
				state_manager.topState()->handleEvent(event, &window);
			}
			if (event.type == sf::Event::Closed) { /* Window is closed by the user */
				window.close();
			}
			else if (event.type == sf::Event::Resized) { /* Automatically update window/view size changes */
				window.setView(sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)));
			}
		}
		/* (3) Render graphics */
		window.clear(sf::Color::Black);
		if (!state_manager.isEmpty()) {
			window.draw(*state_manager.topState());
		}
		window.display();
	}
	return exit_status;
}

Engine::~Engine() {
	this->resource_manager.cleanup();
	this->state_manager.~StateManager();
}
