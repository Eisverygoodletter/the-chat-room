#pragma once
#include <all.h>

namespace ui {
	class baseUI {
	protected:
		sf::Vector2f position;
	public:
		sf::Vector2f getPosition();
		virtual void setPosition(sf::Vector2f);
		baseUI() = default;
		void drawPosition(sf::RenderWindow*);
		// functions to be derived from
		// render (to draw) the object
		virtual void render(sf::RenderWindow*) = 0;
	};
}