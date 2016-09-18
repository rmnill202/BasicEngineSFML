/*
* @Description
* Centralized class for loading in resources. Prevents a single file from
*  being loaded in multiple times unnecessarily, and allows for easier memory
*  management.
*/
#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include <map>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	
	/*
	* @Description
	* Loads a texture into the manager and provides a pointer to the texture. If
	*  the texture fails to load in, a null pointer will be returned.
	*
	* @Parameters
	*  string file - The location of the file being loaded in. 
	*
	* @Return
	*  Texture* - Pointer to the texture loaded in, if successful. Null pointer
	*   if the texture failed to load in.
	*/
	sf::Texture* loadTexture(std::string file);
	/*
	* @Description
	* Same behavior as loadTexture(), but uses SoundBuffers instead.
	*
	* @Parameters
	*  string file - The location of the sound file being loaded in.
	*
	* @Return
	*  Texture* - Pointer to the sound loaded in, if successful. Null pointer
	*   if the sound failed to load in.
	*/
	sf::SoundBuffer* loadSoundBuffer(std::string file);
	/*
	* @Description
	* Same behavior as loadTexture(), but uses Fonts instead.
	*
	* @Parameters
	*  string file - The location of the font file being loaded in.
	*
	* @Return
	*  Texture* - Pointer to the font loaded in, if successful. Null pointer
	*   if the font failed to load in.
	*/
	sf::Font* loadFont(std::string file);

	/*
	* @Description
	* Searches for a texture given the location of its file, deletes it from the
	*  map of textures if found.
	*
	* @Parameters
	*  string file - The location of the file of the texture to be deleted from the map.
	*/
	void deleteTexture(std::string file);
	/*
	* @Description
	* Same behavior as deleteTexture(), but uses SoundBuffers instead.
	*
	* @Parameters
	*  string file - The location of the file of the sound to be deleted from the map.
	*/
	void deleteSoundBuffer(std::string file);
	/*
	* @Description
	* Same behavior as deleteTexture(), but uses Fonts instead.
	*
	* @Parameters
	*  string file - The location of the file of the font to be deleted from the map.
	*/
	void deleteFont(std::string file);
	/*
	* @Description
	* Empties the resources currently loaded into the resource manager, clears up
	*  memory.
	*/
	void cleanup();

private:
	std::map<std::string, sf::Texture*> map_textures; /* Map of file locations and Textures */
	std::map<std::string, sf::SoundBuffer*> map_sound_buffer; /* Map of file locations and SoundBuffers */
	std::map<std::string, sf::Font*> map_fonts; /* Map of file locations and Fonts */

};

