#include <all.h>
#include "textButton.h"

void ui::textButton::setPosition(sf::Vector2f position) {
	this->position = position; // baseUI class settings
	sf::Vector2f textOffset; // done because the origin of the text is set in the middle
	textOffset.x = this->buttonText.getLocalBounds().width / 2;
	textOffset.y = this->buttonText.getLocalBounds().height / 2 - 10;
	this->buttonText.setPosition(position + textOffset);
	this->backgroundRectangle.setPosition(position);
}
void ui::textButton::setSize(sf::Vector2f size) {
	this->backgroundRectangle.setSize(size);
}
void ui::textButton::render(sf::RenderWindow* window) {
	window->draw(this->backgroundRectangle);
	window->draw(this->buttonText);
}
bool ui::textButton::checkClick(sf::Vector2f mousePos) {
	if (this->backgroundRectangle.getGlobalBounds().contains(mousePos)) {
		return true;
	}
	return false;
}

ui::textButton::textButton(std::string text, sf::Vector2f position, sf::Vector2f size) {
	this->buttonText = sf::Text(text, tL::fH["ARIAL"], DEFAULT_CHARACTER_SIZE);
	this->buttonText.setScale(DEFAULT_TEXTBUTTON_SIZE);
	this->buttonText.setFillColor(DEFAULT_TEXTBUTTON_TEXTCOLOR);
	//this->buttonText.setOrigin(sf::Vector2f(this->buttonText.getLocalBounds().width / 2, this->buttonText.getLocalBounds().height / 2));
	this->backgroundRectangle = sf::RectangleShape();
	this->backgroundRectangle.setFillColor(DEFAULT_TEXTBUTTON_BGCOLOR);
	this->setPosition(position);
	this->setSize(size);
}