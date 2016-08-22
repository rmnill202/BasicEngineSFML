/*
* @Description
* Centralized class for loading in resources. Prevents a single file from
*  being loaded in multiple times unnecessarily, and allows for easier memory
*  management.
*
* @How to Use
* It is recommended to keep track of files in your States using a string, just so
*  you aren't required to copy and paste the location of the file multiple times.
* 
*
* @What Does This Do?
* 1. Maintains maps of sf::Texture and sf::SoundBuffer objects associated with
*  std::string file locations
* 2. Ensures that a given file are only loaded in once by checking maps for the
*  file location in std::string format.
* 3. Returns convenient pointer references to sf::Texture and sf::SoundBuffer
*  objects when loading in files.
* 4. Cleans up all files from memory when calling the cleanup() function or
*  ending the application, as well as having the ability to remove specific files
*  from memory at any time. 
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
	* Searches for a texture given the location of its file, deletes it from the
	*  map of textures if found.
	*
	* @Parameters
	*  string file - The location of the file of the texture to be deleted.
	*/
	void deleteTexture(std::string file);
	/*
	* @Description
	* Same behavior as deleteTexture(), but uses SoundBuffers instead.
	*
	* @Parameters
	*  string file - The location of the file of the sound to be deleted.
	*/
	void deleteSoundBuffer(std::string file);
	/*
	* @Description
	* Empties the resources currently loaded into the resource manager, clears up
	*  memory.
	*/
	void cleanup();

	sf::Font primary_font; /* Default font used by the application for text items */

private:
	std::map<std::string, sf::Texture*> map_textures; /* Map of file locations and Textures */
	std::map<std::string, sf::SoundBuffer*> map_sound_buffer; /* Map of file locations and SoundBuffers */

};

