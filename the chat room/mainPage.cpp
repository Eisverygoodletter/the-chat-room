#include <all.h>
#include "openPage.h"

void oP::loadMain(sf::RenderWindow& window) {
	ui::textButton sendButton = ui::textButton("Send", sf::Vector2f(600, 500),sf::Vector2f(180,60)); //send button
	sendButton.buttonText.setScale(sf::Vector2f(1, 1) * 1.7f); // scale the text size of the send button

	sf::Text typeText = sf::Text("", tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	typeText.setPosition(30, DEFAULT_WINDOW_HEIGHT - 60);

	sf::UdpSocket sendSocket;
	sendSocket.setBlocking(false);
	sf::UdpSocket recvsocket;
	recvsocket.bind(DEFAULT_UDP_PORT);
	recvsocket.setBlocking(false);
	bool sendMsg = false;

	std::vector<sf::Text> textList = {};

	// start of the actual loop
	while (window.isOpen()) {
		sf::Event e;
		sendMsg = false;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				goto endFunction;
			}
			if (e.type == sf::Event::TextEntered) {
				typeText.setString(typeText.getString() + e.text.unicode);
				if (e.text.unicode == '\b') {
					if (!typeText.getString().isEmpty()) {
						typeText.setString(typeText.getString().substring(0, typeText.getString().getSize() - 2));
					}
					else {
						typeText.setString(typeText.getString().substring(0, typeText.getString().getSize() - 1));
					}
				}
			}
			if (e.type == sf::Event::MouseButtonReleased) {
				sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
				if (sendButton.checkClick(mousePos)) {
					sendMsg = true;
				}
			}
		}
		if (sendMsg) {
			if (!typeText.getString().isEmpty()) {
				if (!nt::processCommands(typeText.getString())) {
					sf::Packet toSend = nt::encryptMessage(typeText.getString());
					sendSocket.send(toSend, sf::IpAddress::Broadcast, DEFAULT_UDP_PORT);
				}
				typeText.setString("");
			}
			else {
				std::cout << "ERROR NO VALUE DETECTED ON SEND. SEND ABORTED\n";
			}
		}
		// socket receiving
		sf::Packet recvPacket;
		sf::IpAddress otherAddress;
		unsigned short otherPort;
		sf::Socket::Status stat = recvsocket.receive(recvPacket, otherAddress, otherPort);
		if (stat == sf::Socket::Done) {
			// decrypt packet
			std::pair<std::string, std::string> packetval = nt::decryptMessage(recvPacket);
			sf::Text newText = sf::Text(packetval.first + ": " + packetval.second, tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
			newText.setPosition(10, DEFAULT_WINDOW_HEIGHT - 150);
			for (sf::Text& t : textList) {
				t.setPosition(10, t.getPosition().y - 40);
			}
			textList.push_back(newText);
		}

		window.clear(DEFAULT_BGCOLOR);
		sendButton.render(&window);
		window.draw(typeText);
		for (sf::Text& t : textList) {
			window.draw(t);
		}
		window.display();
	}
	// end function goto statement
	endFunction:
	return;
}