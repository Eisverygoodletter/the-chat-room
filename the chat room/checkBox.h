#pragma once
#include <all.h>

namespace ui {
	class checkBox : public ui::baseUI {
	protected:
		bool checked;
		sf::Sprite uncheckedSprite;
		sf::Sprite checkedSprite;
	public:
		bool getChecked();
		void setChecked(bool);
		void setSize(sf::Vector2f);
		void setPosition(sf::Vector2f) override;
		void render(sf::RenderWindow*) override;
		bool checkClick(sf::Vector2f position);
		checkBox(sf::Vector2f position, sf::Vector2f size, bool defaultChecked);
	};
}