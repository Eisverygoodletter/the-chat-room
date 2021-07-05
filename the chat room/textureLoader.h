#pragma once
#include <all.h>
#include <SFML/Graphics.hpp>
namespace tL {
	extern thor::ResourceHolder<sf::Texture, std::string> rH;
	extern thor::ResourceHolder<sf::Font, std::string> fH;
	extern void loadTextures();
}