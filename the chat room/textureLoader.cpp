#pragma once
#include "textureLoader.h"
#include <all.h>

thor::ResourceHolder<sf::Texture, std::string> tL::rH = thor::ResourceHolder<sf::Texture, std::string>();
thor::ResourceHolder<sf::Font, std::string> tL::fH = thor::ResourceHolder<sf::Font, std::string>();


void tL::loadTextures() {
	try {
		tL::rH.acquire("CHECKBOX_CHECKED", thor::Resources::fromFile<sf::Texture>(TEXTURE_CHECKBOX_CHECKED));
		tL::rH.acquire("CHECKBOX_UNCHECKED", thor::Resources::fromFile<sf::Texture>(TEXTURE_CHECKBOX_UNCHECKED));
		tL::fH.acquire("ARIAL", thor::Resources::fromFile<sf::Font>(FONT_ARIAL));
		std::cout << "finished loading textures\n";
	}
	catch (thor::ResourceLoadingException& e){
		std::cout << "experienced error when loading textures.\n";
		std::cout << e.what() << '\n';
		std::cout << "continuing ...\n";
	}
}
