#pragma once
#include <fstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <Thor/Resources.hpp>
#include <nlohmann/json.hpp>
// file names
#define SETTINGS_FILE_NAME "settings.json"
#define TEXTURE_CHECKBOX_CHECKED "checked_checkBox.png"
#define TEXTURE_CHECKBOX_UNCHECKED "unchecked_checkbox.png"
#define FONT_ARIAL "Arial.ttf"

// default settings
#define DEFAULT_ENCRYPTION NULL // this expands to 0, which is an int
#define DEFAULT_BGCOLOR sf::Color::Color(30,30,30,255)
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600
#define ENCRYPTOR_OVERRIDE "|| DEC KEY ||"
#define ENCRYPTOR_OVERRIDE_SIZE 13
#define DEFAULT_MSG_NUMBER 8


// word (character) size
#define DEFAULT_CHARACTER_SIZE 30



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
#include <networking.h>