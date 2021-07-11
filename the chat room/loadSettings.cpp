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
	window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Settings");
	ui::textButton startButton = ui::textButton("Start", sf::Vector2f(DEFAULT_WINDOW_WIDTH/2 -70, DEFAULT_WINDOW_HEIGHT- 100), sf::Vector2f(130,40));
	
	// settings
	// encryption number and buttons
	sf::Text encryptionNum = sf::Text("0", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	encryptionNum.setPosition(100, 100);
	encryptionNum.setFillColor(DEFAULT_TEXTBUTTON_TEXTCOLOR);

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			else if (e.type == sf::Event::MouseButtonReleased) {
				sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
				if (startButton.checkClick(mousePos)) {
					// starting
					std::cout << "starting chat session...\n";
					oP::loadMain(window);
					goto endFunction;
				}
			}
		}
		// updating ui values
		// update value of encryption displayer text
		encryptionNum.setString(std::to_string(dS::settings["encryption"]));

		// rendering
		window.clear(DEFAULT_BGCOLOR);
		startButton.render(&window);
		window.draw(encryptionNum);
		window.display();
	}
	endFunction:
	return;
}