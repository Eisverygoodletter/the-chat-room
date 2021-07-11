
#include <iostream>
#include <all.h>
#undef main
int main() {
	std::cout << "\nlocal network chatroom developed by Eisverygoodletter (github)\n";
	std::cout << "the developer of this product / application is NOT responsible for any problems or damage caused by the\n";
	std::cout << "misuse of this product.\n";
	sf::sleep(sf::seconds(1.5));
	std::cout << "loading ...\n";
	sf::sleep(sf::seconds(1.5));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		std::cout << "writing memory file ...\n";
		dS::startSettings();
	}
	tL::loadTextures();
	oP::loadSettings();
	mc::cleanup();
}