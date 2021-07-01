#include "checkBox.h"

void ui::checkBox::setPosition(sf::Vector2f position) {
	this->position = position;
	this->uncheckedSprite.setPosition(position);
	this->checkedSprite.setPosition(position);
}

bool ui::checkBox::getChecked() {
	// get if checkBox is checked
	return this->checked;
}

void ui::checkBox::setChecked(bool isChecked) {
	// nothing to change here as drawing which sprite is handled by ui::checkBox::render();
	this->checked = isChecked;
}

void ui::checkBox::render(sf::RenderWindow* window) {
	// drawing the two sprites based on the checked variable
	if (this->checked) {
		window->draw(this->checkedSprite);
	}
	else {
		window->draw(this->uncheckedSprite);
	}
}

void ui::checkBox::setSize(sf::Vector2f size) {
	this->uncheckedSprite.setScale(size);
	this->checkedSprite.setScale(size);
}

ui::checkBox::checkBox(sf::Vector2f position, sf::Vector2f size, bool defaultChecked = false) {
	this->checked = defaultChecked;
	this->setSize(size);
	this->setPosition(size);
}

bool ui::checkBox::checkClick(sf::Vector2f mousePos) {
	if (this->checkedSprite.getGlobalBounds().contains(mousePos)) {
		this->checked = !this->checked;
		return true;
	}
	return false;
}