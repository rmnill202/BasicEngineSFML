/*
* @Description
* Show how states may be used in order to create your own application.
*
*/
#pragma once
#include "BasicEngineSFML\State.h"
#include "SFML\Graphics.hpp"
#include <climits>

class StateTest : public State
{
public:
	void init(StateManager* state_manager, ResourceManager* resource_manager);
	void cleanup();
	void start();
	void pause();
	void update();
	void handleEvent(sf::Event event, sf::RenderWindow * window);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/* File locations */
	std::string menu_font = "Resources\\Orkney-Regular.otf";

	/* Some basic graphics objects */
	sf::Text counterText;
	int counter = 0;
};

