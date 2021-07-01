#include <all.h>
#include "baseUI.h"

sf::Vector2f ui::baseUI::getPosition() {
	return this->position;
}

void ui::baseUI::setPosition(sf::Vector2f newPosition) {
	this->position = newPosition;
}

void ui::baseUI::drawPosition(sf::RenderWindow* window) {
	// draw a cross on the position to denote where it is.
	// vertical line
	sf::Vertex vertLine[2];
	vertLine[0].color = DEBUG_DRAW_COLOR;
	vertLine[0].position = this->getPosition() + sf::Vector2f(0, 10);
	vertLine[1].color = DEBUG_DRAW_COLOR;
	vertLine[1].position = this->getPosition() + sf::Vector2f(0, -10);
	window->draw(vertLine, 4, sf::Quads);
	// horizontal line
	sf::Vertex horizLine[2];
	horizLine[0].color = DEBUG_DRAW_COLOR;
	horizLine[0].position = this->getPosition() + sf::Vector2f(0, 10);
	horizLine[1].color = DEBUG_DRAW_COLOR;
	horizLine[1].position = this->getPosition() + sf::Vector2f(0, -10);
	window->draw(horizLine, 4, sf::Quads);
	// done
}