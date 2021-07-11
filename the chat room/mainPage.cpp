#include <all.h>
#include "openPage.h"

void oP::loadMain(sf::RenderWindow& window) {
	ui::textButton sendButton = ui::textButton("Send", sf::Vector2f(600, 500),sf::Vector2f(180,60)); //send button
	sendButton.buttonText.setScale(sf::Vector2f(1, 1) * 1.7f); // scale the text size of the send button

	// start of the actual loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				goto endFunction;
			}
		}

		window.clear(DEFAULT_BGCOLOR);
		sendButton.render(&window);
		window.display();
	}
	// end function goto statement
	endFunction:
	return;
}