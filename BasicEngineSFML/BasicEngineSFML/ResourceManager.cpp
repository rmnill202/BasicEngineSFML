#include "ResourceManager.h"
#include "Utilities.h"

ResourceManager::ResourceManager() {
	try {
		primary_font.loadFromFile("Orkney-Regular.otf");
	}
	catch (std::exception& e) {
		//std::cout << e.what() << std::endl;
	}
}

ResourceManager::~ResourceManager() {
	this->cleanup();
}

sf::Texture * ResourceManager::loadTexture(std::string file) {
	std::map<std::string, sf::Texture*>::iterator found = map_textures.find(file);

	if (found != map_textures.end()) { /* File already loaded in */
		//std::cout << "Texture already loaded, map size: " << map_textures.size() << std::endl;
		return found->second;
	}
	else {  /* Attempt to load file in */
		sf::Texture* texture = new sf::Texture();

		if ( !texture->loadFromFile(file) ) {
			/* Texture doesn't exist */
			//throw GameException("Texture file not found", GameException::ExceptionType::ERROR);
			//std::cout << "Failed to load file, map size: " << map_textures.size() << std::endl;
			return nullptr;
		}

		/* If the file has been successfully loaded */
		map_textures.insert(std::pair<std::string, sf::Texture*>(file, texture));
		//std::cout << "File loaded, map size: " << map_textures.size() << std::endl;
	}
}

sf::SoundBuffer * ResourceManager::loadSoundBuffer(std::string file) {
	std::map<std::string, sf::SoundBuffer*>::iterator found = map_sound_buffer.find(file);
	
	if (found != map_sound_buffer.end()) { /* File already loaded in */
		//std::cout << "Texture already loaded, map size: " << map_sound_buffer.size() << std::endl;
		return found->second;
	}
	else {  /* Attempt to load file in */
		sf::SoundBuffer* sound = new sf::SoundBuffer();

		if (!sound->loadFromFile(file)) {
			/* Audio file doesn't exist */
			//throw GameException("Audio file file not found", GameException::ExceptionType::ERROR);
			//std::cout << "Failed to load file, map size: " << map_sound_buffer.size() << std::endl;
			return nullptr;
		}

		/* If the file has been successfully loaded */
		map_sound_buffer.insert(std::pair<std::string, sf::SoundBuffer*>(file, sound));
		//std::cout << "File loaded, map size: " << map_sound_buffer.size() << std::endl;
	}
}

void ResourceManager::deleteTexture(std::string file) {
	std::map<std::string, sf::Texture*>::iterator found = map_textures.find(file);

	if ( found != map_textures.end() ) { /* The texture is found */
		delete found->second;
		map_textures.erase(found);
		//std::cout << "Resource deleted, map size: " << map_textures.size() << std::endl;
	}
	else {
		//std::cout << "Resource not loaded, map size: " << map_textures.size() << std::endl;
	}
}

void ResourceManager::deleteSoundBuffer(std::string file) {
	std::map<std::string, sf::SoundBuffer*>::iterator found = map_sound_buffer.find(file);

	if (found != map_sound_buffer.end()) { /* The sound is found */
		delete found->second;
		map_sound_buffer.erase(file);
	}
}

void ResourceManager::cleanup() {
	/* Cleanup textures */
	for (std::map<std::string, sf::Texture*>::iterator itr = map_textures.begin(); itr != map_textures.end(); itr++) {
		delete itr->second;
		map_textures.erase(itr);
	}
	/* Cleanup audio */
	for (std::map<std::string, sf::SoundBuffer*>::iterator itr = map_sound_buffer.begin(); itr != map_sound_buffer.end(); itr++) {
		delete itr->second;
		map_sound_buffer.erase(itr);
	}
}
