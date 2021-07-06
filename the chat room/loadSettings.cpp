#include "openPage.h"
#include <all.h>
#include <fstream>

void oP::loadSettings() {
	tL::loadTextures();
	std::ifstream settingsFile;
	settingsFile.open(SETTINGS_FILE_NAME, std::ios::in);
	settingsFile.seekg(0);
	dS::storeClass toStore = dS::storeClass();
	settingsFile.read((char*)&toStore, sizeof(toStore));
	settingsFile.close();
	dS::settings["encryption"] = toStore.encryption;
	// open the settings page, where you can change the settings (obviously)
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Settings");
	ui::textButton testbutton = ui::textButton("cool Text", sf::Vector2f(10, 10), sf::Vector2f(50, 50));
	ui::checkBox testbox = ui::checkBox(sf::Vector2f(100, 100), sf::Vector2f(50, 50), true);
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			else if (e.type == sf::Event::MouseButtonReleased) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			}
		}
		window.clear();
		testbox.render(&window);
		testbutton.render(&window);
		testbutton.drawPosition(&window);
		window.display();
	}
}