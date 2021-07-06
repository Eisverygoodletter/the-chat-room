#pragma once
#include <fstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <Thor/Resources.hpp>
// file names
#define SETTINGS_FILE_NAME "settings.set"
#define TEXTURE_CHECKBOX_CHECKED "checked_checkBox.png"
#define TEXTURE_CHECKBOX_UNCHECKED "unchecked_checkbox.png"
#define FONT_ARIAL "Arial.ttf"

// default settings
#define DEFAULT_ENCRYPTION NULL // this expands to 0, which is an int
// default draw parameters

// checkbox
#define DEFAULT_CHECKBOX_SIZE sf::Vector2f(0.1f, 0.1f) // note that just the text is replaced
// word (character) size
#define DEFAULT_CHARACTER_SIZE 30
// values for drawing the debug position cross
#define DEBUG_DRAW_COLOR sf::Color::Green
#define DEBUG_DRAW_DISTANCE 20
// textButton
#define DEFAULT_TEXTBUTTON_TEXTCOLOR sf::Color::Black
#define DEFAULT_TEXTBUTTON_BGCOLOR sf::Color::White

/*

	order of includes:
	1. textureLoader.h [ no requirements ]
	2. ui.h [ requires textures loaded by textureLoader.h ]
	3. dataStore.h [ may require ui and textureLoader ]
	4. openPage.h [ requires ui.h and dataStore.h ]
	5. misc.h [ up to change ]

*/


//include all predeclarations
#include <PreDecl_textureLoader.h>
#include <PreDecl_ui.h>
#include <PreDecl_dataStore.h>
#include <PreDecl_openPage.h>


// include all actual header files.
#include <textureLoader.h>
#include <ui.h>
#include <dataStore.h>
#include <openPage.h>
#include <misc.h>