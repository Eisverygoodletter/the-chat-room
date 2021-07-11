#pragma once
// values for drawing the debug position cross
#define DEBUG_DRAW_COLOR sf::Color::Green
#define DEBUG_DRAW_DISTANCE 20
// checkbox
#define DEFAULT_CHECKBOX_SCALE 0.1f // note that just the text is replaced
#include <all.h>
// textButton
#define DEFAULT_TEXTBUTTON_TEXTCOLOR sf::Color::White
#define DEFAULT_TEXTBUTTON_BGCOLOR sf::Color::Black
#define DEFAULT_TEXTBUTTON_SIZE sf::Vector2f(1,1)
#define DEFAULT_TEXTBUTTON_BGSIZE sf::Vector2f(250, 40)

namespace ui {
	class baseUI;
	class checkBox;
	class textButton;
}