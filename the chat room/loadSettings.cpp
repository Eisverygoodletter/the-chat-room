#include "openPage.h"
#include <all.h>
#include <fstream>

void oP::loadSettings() {
	std::ifstream settingsFile;
	settingsFile.open(SETTINGS_FILE_NAME);
	nlohmann::json getjson = nlohmann::json::parse(settingsFile);
	settingsFile.close();
	std::cout << getjson << '\n';
	dS::username = getjson["username"];
	dS::settings["encryption"] = getjson["encryption"];

	// open the settings page, where you can change the settings (obviously)
	sf::RenderWindow window;
	window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Settings");
	ui::textButton startButton = ui::textButton("Start", sf::Vector2f(DEFAULT_WINDOW_WIDTH/2 -70, DEFAULT_WINDOW_HEIGHT- 100), sf::Vector2f(130,40));
	
	// settings
	// encryption number and buttons
	sf::Text encryptionLabel = sf::Text("encryption:", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	encryptionLabel.setPosition(10, 100);
	encryptionLabel.setFillColor(DEFAULT_TEXTBUTTON_TEXTCOLOR);
	sf::Text encryptionNum = sf::Text("0", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	encryptionNum.setPosition(240, 100);
	encryptionNum.setFillColor(DEFAULT_TEXTBUTTON_TEXTCOLOR);
	ui::textButton encryptionAddButton = ui::textButton("+", sf::Vector2f(280,90),sf::Vector2f(50,50));
	encryptionAddButton.buttonText.setScale(sf::Vector2f(1, 1) * 1.5f);
	ui::textButton encryptionMinusButton = ui::textButton(" -", sf::Vector2f(160, 90), sf::Vector2f(50, 50));
	encryptionMinusButton.buttonText.setScale(sf::Vector2f(1, 1) * 1.5f);
	// text input for username
	sf::Text usernameLabel = sf::Text("username: ", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	usernameLabel.setPosition(10, 150);
	sf::Text usernameText = sf::Text("empty username", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	usernameText.setPosition(160, 150);


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
					// store settings
					nlohmann::json prep = nlohmann::json();
					prep["encryption"] = dS::settings["encryption"];
					prep["username"] = dS::username;
					std::ofstream outFile(SETTINGS_FILE_NAME);
					outFile << prep;
					outFile.close();
					oP::loadMain(window);
					goto endFunction;
				}
				else if (encryptionAddButton.checkClick(mousePos)) {
					dS::settings["encryption"]++; // increase encryption value
				}
				else if (encryptionMinusButton.checkClick(mousePos)) {
					dS::settings["encryption"]--;
				}
			}
			else if (e.type == sf::Event::TextEntered) {
				dS::username += e.text.unicode;
				if (e.text.unicode == '\b') {
					if (!(dS::username == "")) {
						// if not empty
						dS::username = dS::username.substr(0, dS::username.size() - 2);
					}
				}
			}
		}
		// updating ui values
		// update value of encryption displayer text
		encryptionNum.setString(std::to_string(dS::settings["encryption"]));
		// update value of username displayer text
		usernameText.setString(dS::username);

		// rendering
		window.clear(DEFAULT_BGCOLOR);
		startButton.render(&window);

		window.draw(encryptionLabel);
		window.draw(encryptionNum);
		encryptionAddButton.render(&window);
		encryptionMinusButton.render(&window);

		window.draw(usernameLabel);
		window.draw(usernameText);

		window.display();
	}
endFunction:;
	return;
}