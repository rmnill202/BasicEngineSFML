#include "StateTest.h"

void StateTest::init(StateManager * state_manager, ResourceManager * resource_manager) {
	this->state_manager = state_manager;
	this->resource_manager = resource_manager;
	this->resource_manager->loadFont(menu_font);

	counterText.setFont(*this->resource_manager->loadFont(menu_font));
	counterText.setCharacterSize(24);
	counterText.setFillColor(sf::Color(151, 140, 162));
	counterText.setString("Press space to iterate: 0");
	counterText.setPosition(state_manager->getWindow()->getSize().x / 4, state_manager->getWindow()->getSize().y / 4);
	counterText.setFillColor(sf::Color::White);
}

void StateTest::cleanup() {
	state_manager->freeStates();
	resource_manager->cleanup();
}

void StateTest::start() {
}

void StateTest::pause() {
}

void StateTest::update() {
}

void StateTest::handleEvent(sf::Event event, sf::RenderWindow * window) {
	if ((event.type == sf::Event::KeyPressed) && 
		(event.type != sf::Event::KeyReleased) &&
		(event.key.code == sf::Keyboard::Space)) {

		if (counter < INT_MAX - 1) {
			counter++;
			counterText.setString("Press space to iterate: " + std::to_string(counter));
			std::cout << "Space" << std::endl;
		}
	}
	else if (event.type == sf::Event::Resized) {
		counterText.setPosition(state_manager->getWindow()->getSize().x / 4, state_manager->getWindow()->getSize().y / 4);
	}
}

void StateTest::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(counterText, states);
}
