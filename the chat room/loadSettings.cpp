#include "openPage.h"
#include <all.h>
#include <fstream>

void oP::loadSettings() {
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
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.display();
	}
}