#pragma once
#include <all.h>

namespace ui {
	class textButton : public ui::baseUI {
	public:
		sf::Font defaultFont;
		sf::Text buttonText;
		sf::RectangleShape backgroundRectangle;
		void setSize(sf::Vector2f);
		void setPosition(sf::Vector2f) override;
		void render(sf::RenderWindow*) override;
		bool checkClick(sf::Vector2f);
		textButton(std::string text, sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(0, 0));
	};
}